import { existsSync } from 'node:fs';
import path from 'node:path';
import bibSource from '../data/papers.bib?raw';

export interface Author {
  name: string; // "M. Edmonds"
  equal: boolean; // marked with * (equal contribution)
  me: boolean;
}

export interface Paper {
  key: string;
  title: string;
  authors: Author[];
  venue: string;
  year: number;
  abbr?: string;
  award?: string;
  preview?: string;
  selected: boolean;
  links: { label: string; href: string }[];
  bibtex?: string;
}

type Entry = { type: string; key: string; fields: Record<string, string> };

/**
 * Minimal BibTeX reader: `@type{key, field = {value}, ...}`. Values must be wrapped in
 * braces (nested braces are fine); quoted values, @string macros and comments aren't
 * supported because papers.bib doesn't use them.
 */
function parseBib(src: string): Entry[] {
  const entries: Entry[] = [];
  const head = /@(\w+)\s*\{\s*([^,\s]+)\s*,/g;
  const field = /\s*(\w+)\s*=\s*\{/y;
  for (let m; (m = head.exec(src)); ) {
    const fields: Record<string, string> = {};
    let i = head.lastIndex;
    for (field.lastIndex = i; ; field.lastIndex = i) {
      const f = field.exec(src);
      if (!f) break;
      let depth = 1;
      let j = field.lastIndex;
      for (; depth > 0; j++) {
        if (j >= src.length) throw new Error(`papers.bib: unclosed brace in ${m[2]}.${f[1]}`);
        if (src[j] === '{') depth++;
        else if (src[j] === '}') depth--;
      }
      fields[f[1].toLowerCase()] = src.slice(field.lastIndex, j - 1).replace(/\s+/g, ' ').trim();
      i = j;
      while (/[\s,]/.test(src[i] ?? '')) i++;
    }
    head.lastIndex = i;
    entries.push({ type: m[1].toLowerCase(), key: m[2], fields });
  }
  return entries;
}

// "Edmonds*, M." -> { name: "M. Edmonds", equal: true }
function parseAuthor(raw: string): Author {
  const [last, first = ''] = raw.split(',').map((s) => s.trim());
  const equal = last.endsWith('*');
  const surname = last.replace(/\*$/, '');
  return { name: `${first} ${surname}`.trim(), equal, me: surname === 'Edmonds' };
}

// Bare file names live in /papers/; anything with a scheme or leading slash is used as is.
// Local paths are checked against the repo (builds run from its root).
function resolvePdf(key: string, value: string): string {
  if (value.includes('://')) return value;
  const href = value.startsWith('/') ? value : `/papers/${value}`;
  if (!existsSync(path.join(process.cwd(), href))) {
    throw new Error(`papers.bib: ${key} links to missing file ${href}`);
  }
  return href;
}

const BIBTEX_FIELDS = ['title', 'author', 'journal', 'booktitle', 'school', 'volume', 'number', 'pages', 'year', 'month', 'doi'];

function toBibtex({ type, key, fields }: Entry): string {
  const lines = BIBTEX_FIELDS.filter((f) => fields[f]).map((f) => {
    const value = f === 'author' ? fields[f].replaceAll('*', '') : fields[f];
    return `  ${f} = {${value}}`;
  });
  return `@${type}{${key},\n${lines.join(',\n')}\n}`;
}

function toPaper(entry: Entry): Paper {
  const { key, fields: f } = entry;
  const links: Paper['links'] = [];
  if (f.pdf) links.push({ label: 'PDF', href: resolvePdf(key, f.pdf) });
  if (f.supp) links.push({ label: 'Supplement', href: resolvePdf(key, f.supp) });
  if (f.html) links.push({ label: 'Article', href: f.html });
  else if (f.doi) links.push({ label: 'DOI', href: `https://doi.org/${f.doi}` });
  if (f.website) links.push({ label: 'Project page', href: f.website });
  if (f.code) links.push({ label: 'Code', href: f.code });
  if (f.video) links.push({ label: 'Video', href: f.video });
  return {
    key,
    title: f.title,
    authors: f.author.split(' and ').map(parseAuthor),
    venue: f.journal ?? f.booktitle ?? f.school ?? '',
    year: Number(f.year),
    abbr: f.abbr,
    award: f.award_name,
    preview: f.preview && `/assets/img/publication_preview/${f.preview}`,
    selected: f.selected === 'true',
    links,
    bibtex: f.bibtex_show === 'true' ? toBibtex(entry) : undefined,
  };
}

/** Every paper in papers.bib, newest first (file order within a year). */
export const papers: Paper[] = parseBib(bibSource)
  .map(toPaper)
  .sort((a, b) => b.year - a.year);

export function paperByKey(key: string): Paper {
  const paper = papers.find((p) => p.key === key);
  if (!paper) throw new Error(`No paper "${key}" in papers.bib`);
  return paper;
}

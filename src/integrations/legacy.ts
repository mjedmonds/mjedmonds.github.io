import type { AstroIntegration } from 'astro';
import { createReadStream } from 'node:fs';
import { cp, mkdir, stat } from 'node:fs/promises';
import type { IncomingMessage, ServerResponse } from 'node:http';
import path from 'node:path';
import { fileURLToPath } from 'node:url';

// Static content from the pre-Astro site, published byte for byte at its old URLs
// (/CS80/..., /papers/..., /cv/*.pdf). Each path is relative to the repo root and is served at
// the same path on the site. Astro never parses these: the course slides contain template-like
// syntax and nested reveal.js checkouts. The course landing pages and paper project pages were
// moved into src/ and are no longer here; their slides, images and data files still are.
const LEGACY_PATHS = [
  'CS32', 'CS50', 'CS52', 'CS80', // CS31 had only its landing page, now in src/data/courses
  'papers', 'projects',
  'CS31.html', 'CS32.html', 'teaching.html', 'favicon.png',
  // Only the two PDFs are published from the cv submodule.
  'cv/mark_edmonds_cv.pdf', 'cv/mark_edmonds_resume.pdf',
];

const ROOT = fileURLToPath(new URL('../../', import.meta.url));

// Files under LEGACY_PATHS that are never published (rel is relative to the repo root).
const isUnpublished = (rel: string) => {
  const name = path.basename(rel);
  // Git metadata and macOS/Dropbox litter ("Icon\r" files).
  if (name === '.git' || name === '.DS_Store' || name.startsWith('Icon\r')) return true;
  // The reveal.js checkouts are only needed for the CSS and JS the slide decks load, not the
  // library's own README, demo and test pages. Decks use their own plugin/ folder.
  const inRevealCheckout = rel.split('/').slice(0, -1).includes('reveal.js');
  if (inRevealCheckout && (name.endsWith('.html') || name === 'test')) return true;
  return name === 'template-revealjs.html'; // unused reveal-md templates
};

const MIME: Record<string, string> = {
  '.html': 'text/html; charset=utf-8', '.css': 'text/css', '.js': 'text/javascript',
  '.json': 'application/json', '.svg': 'image/svg+xml', '.png': 'image/png',
  '.jpg': 'image/jpeg', '.jpeg': 'image/jpeg', '.gif': 'image/gif', '.ico': 'image/x-icon',
  '.pdf': 'application/pdf', '.woff': 'font/woff', '.woff2': 'font/woff2', '.ttf': 'font/ttf',
  '.mp4': 'video/mp4', '.md': 'text/markdown; charset=utf-8', '.txt': 'text/plain; charset=utf-8',
};

/** Maps a request path to a legacy file on disk, or null if it isn't legacy content. */
async function resolveLegacy(urlPath: string): Promise<string | null> {
  const rel = decodeURIComponent(urlPath).replace(/^\/+/, '');
  const owned = LEGACY_PATHS.some((p) => rel === p || rel.startsWith(`${p}/`));
  if (!owned || isUnpublished(rel) || rel.split('/').some((part) => part === '..')) return null;
  let file = path.join(ROOT, rel);
  try {
    if ((await stat(file)).isDirectory()) file = path.join(file, 'index.html');
    return (await stat(file)).isFile() ? file : null;
  } catch {
    return null;
  }
}

export default function legacy(): AstroIntegration {
  return {
    name: 'legacy-content',
    hooks: {
      // `astro dev`: serve legacy files straight from the repo. Astro's dev route guard 404s
      // page requests for files outside src/ and public/, and it puts itself at the front of
      // the middleware stack once the server is set up. This plugin's post hook runs after
      // Astro's, so unshifting here puts the legacy handler ahead of the guard.
      'astro:config:setup': ({ updateConfig }) => {
        updateConfig({
          vite: {
            plugins: [
              {
                name: 'legacy-content-dev',
                configureServer: (server) => () => {
                  server.middlewares.stack.unshift({
                    route: '',
                    handle: async (req: IncomingMessage, res: ServerResponse, next: () => void) => {
                      const file = await resolveLegacy((req.url ?? '/').split('?')[0]);
                      if (!file) return next();
                      res.setHeader('Content-Type', MIME[path.extname(file).toLowerCase()] ?? 'application/octet-stream');
                      createReadStream(file).pipe(res);
                    },
                  });
                },
              },
            ],
          },
        });
      },
      // `astro build`: copy legacy files into the output.
      'astro:build:done': async ({ dir, logger }) => {
        const out = fileURLToPath(dir);
        for (const p of LEGACY_PATHS) {
          await mkdir(path.dirname(path.join(out, p)), { recursive: true });
          await cp(path.join(ROOT, p), path.join(out, p), {
            recursive: true,
            filter: (src) => !isUnpublished(path.relative(ROOT, src)),
          });
        }
        logger.info(`copied ${LEGACY_PATHS.length} legacy paths`);
      },
    },
  };
}

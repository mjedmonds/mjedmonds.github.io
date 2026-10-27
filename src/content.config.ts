import { defineCollection } from 'astro:content';
import { glob } from 'astro/loaders';
import { z } from 'astro/zod';

// One file per item; the body is a single line of Markdown.
const news = defineCollection({
  loader: glob({ pattern: '*.md', base: './src/content/news' }),
  schema: z.object({ date: z.coerce.date() }),
});

// Served at /research/<file name>/.
const research = defineCollection({
  loader: glob({ pattern: '*.md', base: './src/content/research' }),
  schema: z.object({
    title: z.string(),
    description: z.string(),
    period: z.string(),
    image: z.string().optional(),
    order: z.number(),
    publications: z.array(z.string()).default([]), // keys in src/data/papers.bib
  }),
});

// Paper pages carried over from the old site; each is served at /projects/<path>.html.
const projects = defineCollection({
  loader: glob({ pattern: '*.md', base: './src/content/projects' }),
  schema: z.object({
    path: z.string(),
    paper: z.string(), // key in src/data/papers.bib
    title: z.string(),
    authors: z.string(), // HTML, with affiliation superscripts
    affiliations: z.string().optional(),
    images: z.array(z.object({ src: z.string(), alt: z.string() })).default([]),
    links: z.array(z.object({ label: z.string(), href: z.string() })).default([]),
    figures: z.array(z.object({ src: z.string(), alt: z.string(), caption: z.string() })).default([]),
    videos: z.array(z.object({ src: z.string(), title: z.string() })).default([]),
    coverage: z.array(z.object({ source: z.string(), title: z.string(), href: z.string() })).default([]),
  }),
});

export const collections = { news, research, projects };

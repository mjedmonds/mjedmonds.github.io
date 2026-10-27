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

export const collections = { news, research };

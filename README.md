# mjedmonds.com

Personal site built with [Astro](https://astro.build) and a small custom theme, mjedmonds-theme (one CSS file, no client-side framework). `.github/workflows/deploy.yml` builds it on every push to `master` and deploys it to GitHub Pages; the Pages source must be set to **GitHub Actions**.

## Content

| What | Where |
| --- | --- |
| Bio, photo, home page | `src/pages/index.astro`, `public/assets/img/prof_pic.jpg` |
| News | `src/content/news/` (one Markdown file per item) |
| Publications | `src/data/papers.bib` (thumbnails in `public/assets/img/publication_preview/`) |
| Research projects | `src/content/research/` (served under `/research/`, not linked in the nav) |
| Experience and education | `src/data/experience.ts` |
| Teaching | `src/data/teaching.ts` |
| Nav and social links | `src/data/site.ts` |
| Theme | `src/styles/global.css`, `src/layouts/Base.astro`, `src/components/` |

In `papers.bib`, `selected = {true}` puts a paper on the home page, `*` after a surname marks equal contribution, and a bare `pdf`/`supp` file name refers to `papers/`. The build fails if a local PDF is missing.

## Legacy content

The course sites (`CS31`–`CS80`, including the reveal.js slides), the old project pages (`projects/`), and paper PDFs (`papers/`) are plain static files from the previous site. `src/integrations/legacy.ts` serves them as-is in `npm run dev` and copies them into `dist/` on build, so their URLs stay the same. It also publishes the CV and resume PDFs from the `cv` submodule at `/cv/*.pdf`.

To update the CV or resume, commit in the `cv` submodule, then commit the updated submodule pointer here.

## Local development

Requires Node 22.23 or newer.

```bash
npm install
npm run dev       # http://localhost:4321 with live reload
npm run build     # build everything into dist/
npm run preview   # serve dist/
npm run check     # type-check
```

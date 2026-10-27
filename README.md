# mjedmonds.com

Personal site built with [Astro](https://astro.build) and a small custom theme, mjedmonds-theme (one CSS file, no client-side framework). `.github/workflows/deploy.yml` builds it on every push to `master` and deploys it to GitHub Pages; the Pages source must be set to **GitHub Actions**.

## Content

| What | Where |
| --- | --- |
| Bio, photo, home page | `src/pages/index.astro`, `public/assets/img/prof_pic.jpg` |
| News | `src/content/news/` (one Markdown file per item) |
| Publications | `src/data/papers.bib` (thumbnails in `public/assets/img/publication_preview/`) |
| Research projects | `src/content/research/` (served under `/research/`, not linked in the nav) |
| Paper project pages | `src/content/projects/` (served at their old `/projects/<dir>/<name>.html` URLs; images stay in `projects/`) |
| Experience and education | `src/data/experience.ts` |
| Teaching | `src/data/teaching.ts` |
| Nav and social links | `src/data/site.ts` |
| Theme | `src/styles/global.css`, `src/layouts/Base.astro`, `src/components/` |

In `papers.bib`, `selected = {true}` puts a paper on the home page, `*` after a surname marks equal contribution, a bare `pdf`/`supp` file name refers to `papers/`, and `arxiv = {id}` adds an arXiv link. The build fails if a local PDF is missing.

## Legacy content

The course slides, PDFs and examples (`CS32`–`CS80`), the images and data files for the paper project pages (`projects/`), and the paper PDFs (`papers/`) are plain static files from the previous site. `src/integrations/legacy.ts` serves them as-is in `npm run dev` and copies them into `dist/` on build, so their URLs stay the same. It also publishes the CV and resume PDFs from the `cv` submodule at `/cv/*.pdf`. It skips the reveal.js checkouts' own README, demo and test pages, which the slides don't use.

The course landing pages (`/CS80/CS80.html` and so on) come from `src/data/courses/*.json`, and the paper project pages (`/projects/.../*.html`) come from `src/content/projects/`; both use the site layout at their old URLs. The old theme's `css/`, `js/` and `highlight/` folders are no longer published.

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

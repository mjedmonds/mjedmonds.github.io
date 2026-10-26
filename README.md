# mjedmonds.com

Personal site built with [al-folio](https://github.com/alshedivat/al-folio) v1.2 (Jekyll) and deployed to GitHub Pages by `.github/workflows/deploy.yml`, which builds the site and pushes `_site` to the `gh-pages` branch.

## Content

| What | Where |
| --- | --- |
| Bio, photo, home page | `_pages/about.md`, `assets/img/prof_pic.jpg` |
| News | `_news/` (one file per item) |
| Publications | `_bibliography/papers.bib` (thumbnails in `assets/img/publication_preview/`) |
| Research projects | `_projects/` (served under `/research/`) |
| Experience and education | `_pages/experience.md` |
| Teaching | `_pages/teaching.md` |
| Social links | `_data/socials.yml` |

## Legacy content

The course sites (`CS31`–`CS80`, including the reveal.js slides), the old project pages (`projects/`), and paper PDFs (`papers/`) are plain static files from the previous site. Jekyll is told to skip them (`exclude` in `_config.yml`), and `bin/copy-legacy` copies them into `_site` after the build so their URLs stay the same. It also publishes the CV and resume PDFs from the `cv` submodule at `/cv/*.pdf`.

To update the CV or resume, commit in the `cv` submodule, then commit the updated submodule pointer here.

## Local development

Requires Homebrew `ruby@3.3` (macOS's built-in Ruby 2.6 is too old) and ImageMagick.

```bash
bin/build          # build everything into _site
bin/build serve    # build, then serve at http://localhost:4000 with live reload
```

`bin/build` puts Homebrew Ruby 3.3 on the PATH and sets a UTF-8 locale. To run `bundle` directly instead, first run `export PATH="/opt/homebrew/opt/ruby@3.3/bin:$PATH"`.

import { defineConfig } from 'astro/config';
import legacy from './src/integrations/legacy';

export default defineConfig({
  site: 'https://mjedmonds.com',
  integrations: [legacy()],
  // Write routes as real files: pages live in folder/index.astro (served at /folder/), and
  // project pages keep their old /projects/<dir>/<name>.html addresses.
  build: { format: 'preserve' },
});

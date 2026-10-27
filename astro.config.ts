import { defineConfig } from 'astro/config';
import legacy from './src/integrations/legacy';

export default defineConfig({
  site: 'https://mjedmonds.com',
  integrations: [legacy()],
});

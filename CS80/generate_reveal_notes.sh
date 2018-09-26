#!/bin/bash 

INPUT_DIR="./notes_md"
TEMPLATE="./notes_md/template-revealjs.html"
OUTPUT_DIR="./notes_reveal"

pandoc -t html5 -s --template=${TEMPLATE} --standalone --section-divs --no-highlight --filter pandoc-include-code -o ch2_html_pt1_test.html ch2_html_pt1.md
#!/bin/bash 

INPUT_DIR="./notes_md"
TEMPLATE="./notes_md/template-revealjs.html"
OUTPUT_DIR="./notes_reveal_md"

command="pandoc --wrap=none -t hml5 -s --template=${TEMPLATE} --standalone --section-divs --no-highlight --filter pandoc-include-code -o ${OUTPUT_DIR}/ch4_css.html ch4_css.md"

echo ${command}
${command}
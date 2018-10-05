#!/bin/bash 

INPUT_DIR="./notes_md"
TEMPLATE="./notes_md/template-revealjs.html"
OUTPUT_DIR="./notes_reveal_md"

# convert to absolute paths
INPUT_DIR="${PWD}/${INPUT_DIR}"
TEMPLATE="${PWD}/${TEMPLATE}"
OUTPUT_DIR="${PWD}/${OUTPUT_DIR}"

# need to cd to input dir for pandoc-include-code
cd ${INPUT_DIR}

for f in ${INPUT_DIR}/*.md; do
  [ -f "$f" ] || break
  base_f=$(basename "$f" .md)
  command="pandoc --wrap=none -t html5 -s --template=${TEMPLATE} --standalone --section-divs --no-highlight --filter pandoc-include-code -o ${OUTPUT_DIR}/${base_f}.html ${f}"

  echo ${command}
  ${command}
done
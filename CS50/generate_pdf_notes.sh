#!/bin/bash 

INPUT_DIR="./notes_md"
TEMPLATE="./notes_md/template-eisvogel.latex"
OUTPUT_DIR="./notes_pdf_md"

# convert to absolute paths
INPUT_DIR="${PWD}/${INPUT_DIR}"
TEMPLATE="${PWD}/${TEMPLATE}"
OUTPUT_DIR="${PWD}/${OUTPUT_DIR}"

# need to cd to input dir for pandoc-include-code
cd ${INPUT_DIR}

for f in ${INPUT_DIR}/*.md; do
  [ -f "$f" ] || break
  base_f=$(basename "$f" .md)
  command="pandoc --template=${TEMPLATE} --listings --filter pandoc-include-code -o ${OUTPUT_DIR}/${base_f}.pdf ${f}" 

  echo ${command}
  ${command}
done
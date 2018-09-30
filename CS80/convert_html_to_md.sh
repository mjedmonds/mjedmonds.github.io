#!/bin/bash

echo "You probably do not want to run this command. It will replace all existing markdown and convert from HTML. The conversion is imperfect and will require manual modification. Exiting..."
exit 1

INPUT_DIR="./notes_reveal"
OUTPUT_DIR="./notes_md_new"

for f in ${INPUT_DIR}/*.html; do
  [ -f "$f" ] || break
  base_f=$(basename "$f" .html)
  command="pandoc --wrap=none -s -r html $f -o ${OUTPUT_DIR}/${base_f}.md"
  echo ${command}
  ${command}
    
done
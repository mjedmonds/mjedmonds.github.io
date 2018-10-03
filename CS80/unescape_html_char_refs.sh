INFILE=$1
OUTFILE=$2

cat ${INFILE} | recode html..ascii > ${OUTFILE}

#!/usr/bin/awk -f
# Slide 22: Robust CSV field extraction & filtering
# Usage: awk -f 13_streaming_csv_parser.awk data.csv
BEGIN {
    FS = ","
    OFS = "\t"
}
NR == 1 {
    print "HEADER: " $0
    next
}
$3 > 500 {
    # Print rows where column 3 exceeds threshold
    print $1, $2, $3, "HIGH_VALUE"
}

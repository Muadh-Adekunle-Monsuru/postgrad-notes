#!/usr/bin/awk -f
# Slide 8: Formatted output using printf
# Usage: awk -f 05_printf_formatting.awk grades.tsv
BEGIN {
    FS = "\t"
    printf "%-15s %-10s %8s %15s\n", "STUDENT", "COURSE", "SCORE", "Course_Grade"
    printf "%-15s %-10s %8s,%15s\n", "---------------", "----------", "--------", "---------------"
}
NR > 1 {
    printf "%-15s %-10s %8.2f,%8.2f\n", $1, $2, $3, (0.3*$1 + 0.5*$2+0.2*$3)
}

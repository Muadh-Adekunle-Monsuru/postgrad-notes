#!/usr/bin/awk -f
# Slide 6: Built-in variables (NR, NF, FS, OFS)
# Usage: awk -f 03_built_in_vars.awk data.txt
BEGIN {
    OFS = " | "
    print "Line#", "FieldCount", "FirstField", "LastField"
    print "--------------------------------------------------"
}
{
    print NR, NF, $1, $NF
}
END {
    print "--------------------------------------------------"
    print "Total records processed: " NR
}

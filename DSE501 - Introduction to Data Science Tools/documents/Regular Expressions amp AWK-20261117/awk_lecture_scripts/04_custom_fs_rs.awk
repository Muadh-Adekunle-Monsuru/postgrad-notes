#!/usr/bin/awk -f
# Slide 7: Custom Record and Field Separators (Multi-line records)
# Usage: awk -f 04_custom_fs_rs.awk stanzas.txt
BEGIN {
    RS = ""      # Blank line as record separator (paragraph mode)
    FS = "\n"   # Newline as field separator
}
{
    print "Record #" NR " contains " NF " lines."
    print "Header: " $1
    print "---"
}

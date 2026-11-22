#!/usr/bin/awk -f
# Slide 4: Basic field access and formatting
# Usage: ./01_field_printing.awk /etc/passwd
BEGIN {
    FS = ":"
}
{
    print "User: " $1 "\tUID: " $3 "\tShell: " $7
}

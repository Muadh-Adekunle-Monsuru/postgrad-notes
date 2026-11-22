#!/usr/bin/awk -f
# Slide 5: Pattern matching with regular expressions
# Usage: awk -f 02_pattern_matching.awk /etc/passwd
/bash$/ {
    print "Interactive Bash user found: " $1 " with UID " $3
}

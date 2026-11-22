#!/usr/bin/awk -f
# Slide 10: Conditional branching (if-else, ternary)
# Usage: awk -f 07_conditional_branching.awk /etc/passwd
BEGIN {
    FS = ":"
}
{
    status = ($3 == 0) ? "SUPERUSER" : ($3 < 1000 ? "SYSTEM" : "REGULAR")
    printf "%-20s (UID: %5d) -> %s\n", $1, $3, status
}

#!/usr/bin/awk -f
# Slide 18: User-defined functions
# Usage: awk -f 11_user_defined_functions.awk numbers.txt
function clamp(val, low, high) {
    if (val < low) return low
    if (val > high) return high
    return val
}

function trim(str) {
    gsub(/^[ \t]+|[ \t]+$/, "", str)
    return str
}

{
    raw = trim($1)
    val = clamp(raw + 0, 0, 100)
    print "Original: " raw " -> Clamped (0..100): " val
}

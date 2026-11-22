#!/usr/bin/awk -f
# Slide 13: String manipulation (length, index, substr, sub, gsub)
# Usage: awk -f 09_string_functions.awk input.txt

BEGIN {
    FS = "|"
    OFS = " | "
}

{
    # 1. length(): measure record length
    rec_len = length($0)

    # 2. index(): find location of substring
    pos = index($0, "Status:")

    # 3. substr(): extract token ID from column 1
    token_id = substr($1, 1, 12)

    # 4. sub(): replace first occurrence of domain in email column
    sub(/@.*/, "@masked.domain", $3)

    # 5. gsub(): remove brackets around status payload
    n_subs = gsub(/\[|\]/, "", $4)

    printf "Record %d [Len: %3d | 'Status:' at: %2d]\n", NR, rec_len, pos
    printf "  Token ID: %s\n", token_id
    printf "  Masked Email: %s\n", $3
    printf "  Cleaned Status: %s (%d brackets stripped)\n", $4, n_subs
    print "------------------------------------------------------------"
}

#!/usr/bin/awk -f
# Slide 11: Associative arrays - Frequency counting
# Usage: awk -f 08_frequency_hashmap.awk words.txt
{
    for (i = 1; i <= NF; i++) {
        word = tolower($i)
        gsub(/[^a-z0-9]/, "", word)
        if (length(word) > 0) {
            freq[word]++
        }
    }
}
END {
    for (w in freq) {
        printf "%-20s %d\n", w, freq[w]
    }
}

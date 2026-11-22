#!/usr/bin/awk -f
# Slide 9: Arithmetic operations - Column summation & average
# Usage: awk -f 06_column_sum_average.awk numbers.txt
{
    sum += $1
    count++
}
END {
    if (count > 0) {
        printf "Count: %d\nSum: %.2f\nAverage: %.2f\n", count, sum, sum / count
    } else {
        print "No data found."
    }
}

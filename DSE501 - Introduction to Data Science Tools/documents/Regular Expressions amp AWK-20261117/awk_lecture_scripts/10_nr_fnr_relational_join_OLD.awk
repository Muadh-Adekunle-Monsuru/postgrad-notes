#!/usr/bin/awk -f
# Slide 15: The NR==FNR Idiom - Relational file join
# Usage: awk -f 10_nr_fnr_relational_join.awk departments.txt employees.txt
# File 1 (departments.txt): dept_id name
# File 2 (employees.txt): emp_id dept_id emp_name
NR == FNR {
    dept[$1] = $2
    next
}
{
    d_name = ($2 in dept) ? dept[$2] : "Unknown"
    printf "Emp ID: %-5s Name: %-15s Dept: %s\n", $1, $3, d_name
}

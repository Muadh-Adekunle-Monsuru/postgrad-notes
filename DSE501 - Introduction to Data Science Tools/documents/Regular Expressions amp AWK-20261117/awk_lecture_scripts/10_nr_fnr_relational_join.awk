#!/usr/bin/awk -f
# Usage: awk -f 10_nr_fnr_relational_join.awk departments.txt employees.txt

NR == FNR {
    dept[$1] = $2
    next
}
BEGIN {
    printf "%-6s %-16s %-16s %8s\n", "EMP_ID", "EMPLOYEE", "DEPARTMENT", "SALARY"
    printf "%-6s %-16s %-16s %8s\n", "------", "----------------", "----------------", "--------"
}
{
    d_name = ($2 in dept) ? dept[$2] : "Unknown"
    printf "%-6s %-16s %-16s %8s\n", $1, $3, d_name, $4
}

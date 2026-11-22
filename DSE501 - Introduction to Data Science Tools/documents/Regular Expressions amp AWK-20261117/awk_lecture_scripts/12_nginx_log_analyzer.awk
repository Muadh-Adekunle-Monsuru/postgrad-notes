#!/usr/bin/awk -f
# Slide 21: Real-world Apache/Nginx web log analytics
# Usage: awk -f 12_nginx_log_analyzer.awk access.log
# Log format: IP - - [date] "METHOD /path HTTP/1.1" status bytes
{
    ip = $1
    status = $9
    bytes = $10

    ip_count[ip]++
    status_count[status]++
    total_bytes += (bytes ~ /^[0-9]+$/ ? bytes : 0)
}
END {
    print "=== Top IP Addresses ==="
    for (ip in ip_count) {
        printf "%-18s %d requests\n", ip, ip_count[ip]
    }
    print "\n=== HTTP Status Codes ==="
    for (st in status_count) {
        printf "HTTP %s: %d\n", st, status_count[st]
    }
    printf "\nTotal Bandwidth: %.2f MB\n", total_bytes / (1024 * 1024)
}

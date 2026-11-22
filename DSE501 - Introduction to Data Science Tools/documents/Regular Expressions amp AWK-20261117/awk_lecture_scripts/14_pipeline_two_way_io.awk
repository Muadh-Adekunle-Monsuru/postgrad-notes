#!/usr/bin/awk -f
# Slide 24: Dynamic pipeline execution & co-processes
# Usage: awk -f 14_pipeline_two_way_io.awk
BEGIN {
    sort_cmd = "sort -k2 -n -r"
    
    # Pipe data directly to sort command
    print "Alice 45" | sort_cmd
    print "Bob 89"   | sort_cmd
    print "Charlie 72" | sort_cmd
    print "Dave 95"  | sort_cmd
    
    close(sort_cmd)
}

#!usr/bin/awk -f
# Slide 4: Basic field access and formatting
BEGIN{
    total_words=0
    total_bytes=0
    }
    {
    total_words+=NF
    total_bytes+=length($0)+1 
    }
END{printf "%s lines \t | \t %d words \t | \t %d bytes \n",NR,total_words,total_bytes}
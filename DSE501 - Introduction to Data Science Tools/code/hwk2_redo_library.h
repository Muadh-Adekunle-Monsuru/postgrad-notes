FILE *file_open(char *argv[])
{
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file");
        exit(-1);
    }

    return file;
}
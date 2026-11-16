#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

FILE *read_file(int argc, char *argv[]);
void count_alpha(FILE *file, int counts[]);
void print_histogram(const int counts[]);

int main(int argc, char *argv[]){
    FILE *file = read_file(argc, argv);
    int counts[26] = {0};
    count_alpha(file, counts);
    print_histogram(counts);
    return 0;
}

FILE *read_file(int argc, char *argv[]){
    char ch;

    if(argc<2){
        fprintf(stderr,"Arguments not complete: enter %s <file-name> \n",argv[0]);
        exit(-1);
    }

    FILE *file = fopen(argv[1],"r");

    if(file == NULL){
        printf("Error opening file\n");
        exit(-1);
    } 


    return file;
}


void count_alpha(FILE *file, int counts[]){
    int ch;
    while((ch=fgetc(file)) != EOF){
        if(isalpha(ch)){
            counts[tolower(ch)-'a']++;
        }
    }
    fclose(file);
}


void print_histogram(const int counts[]){
    for(int i = 0; i<26;i++){
        printf("%c: ", i+'a');
        for(int j = 0; j<counts[i];j++){
            printf("*");
        }
        printf("\n");
    }printf("\n=========================================\n");
}
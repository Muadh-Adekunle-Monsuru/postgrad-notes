#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *filePtr;

    if((filePtr=fopen("new_data.txt","w"))==NULL){
        printf("Unable to openfile");
        exit(-1);
    }

    fprintf(filePtr, "Muadh, Monsur, 24, M, Istanbul, Turkey");
    printf("File written to");



    fclose(filePtr);
    return 0;
}
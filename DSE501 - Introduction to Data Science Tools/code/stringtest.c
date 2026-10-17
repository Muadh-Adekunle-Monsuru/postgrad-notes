#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "countalpha.c"

int countDigit(char str[]);

int main(int argc, char *argv[]){
    char SENTENCE[] = "Today, October 6 , 2026, we covered a lot. Hope to see you write long programs.";
    int alphabets, digits, symbol, i=0;
    char firstStr[] = {'A','E','I','O','6','E','9','8'};

    printf("there are %d digits in the sentence \n",countDigit(SENTENCE));
    printf("there are %d letters in the sentence \n",countAlpha(SENTENCE));

    

    return 0;
}
    

int countDigit(char str[]){
    int numDigits = 0;
   int len = strlen(str);,

    for(int i = 0; i<len;i++){
        if(isdigit(str[i])){
            numDigits++;
        }
    }
    return numDigits;
} 

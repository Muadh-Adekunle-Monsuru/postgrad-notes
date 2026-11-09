#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int count_digits(char str[]);
int sum_digits(char str[]);

int main(){
    char sentence[200];

    printf("What is the sentence \n");
    fgets(sentence,sizeof(sentence),stdin);
    printf("There is a total of %d digits and the sum of the digits is: %d \n", count_digits(sentence),sum_digits(sentence));




    return 0;
}


int count_digits(char str[]){
    int counts = 0;
    int i;
    int len = strlen(str);
    int sum = 0;
    
    for(i=0;i<len;i++){
        if(isdigit(str[i])){
            counts++;
            
        }
    }

    return counts;
}

int sum_digits(char str[]){
    int i;
    int len = strlen(str);
    int sum = 0;
    
    for(i=0;i<len;i++){
        if(isdigit(str[i])){
           sum += str[i]-'0';
        }
    }

    return sum;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*	Quiz for Homework 1: Write a program that reads a sentence (maximum 82 characters) from command line and prints the following (Note: Use as many as function as possible; that is the main part of the program should not exceed a couple of lines).
	a)	Number and sum of digits in the sentence and 
	b)	Histogram showing the repetition of each digit (0-9).
*/

void toFreq(int *freq, char *str, int *count, int *sum){
	*count = 0, *sum=0;
	for (int i=0; i<strlen(str); i++){
		if((str[i] >='0') && (str[i]<='9')){
			(*count)++;
			*sum +=str[i]-'0';
			freq[str[i]-'0']++;
		}
	}
}

void printHistogram(int* freq){
	for (int i=0;i<10;i++){
		printf("Digit %d",i);
		for (int j=0;j<freq[i];j++)
			printf("*");
		printf("\n");
	}
}

int main(int argc, char const *argv[]){
	char str[82];
	int freq[10]={0}, countDigit,sumDigit;
	//scanf("%s",str);
	fgets(str,83, stdin);
	printf("This is your input\t: %s",str);
	toFreq(freq,str, &countDigit, &sumDigit);
	printf("There is a total of %d digits, and the sum of the digits is %d\n", countDigit,sumDigit);
	printHistogram(freq);
	return 0;
}


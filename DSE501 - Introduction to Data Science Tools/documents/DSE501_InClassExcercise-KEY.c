#include <stdio.h>
#include <stdlib.h>
/*	Quiz for Homework 1: Write a program that reads a sentence (maximum 82 characters) from command line and prints the following (Note: Use as many as function as possible; that is the main part of the program should not exceed a couple of lines).
	a)	Number and sum of digits in the sentence and 
	b)	Histogram showing the repetition of each digit (0-9).
*/
int countDigit(int *freq){
	int c=0;
	for(int i=0; i<10;i++)
		c+=freq[i];
	return c;
}

int sumDigit(int *freq){
	int s=0;
	for(int i=0; i<10;i++)
		s+=i*freq[i];
	return s;
}

void printHistogram(int* freq){
	for (int i=0;i<10;i++){
		printf("Digit %d",i);
		for (int j=0;j<freq[i];j++)
			printf("*");
		printf("\n");
	}
}

void toFreq(int *freq, char *str){
	for (int i=0; i<82; i++){
		if((str[i] >='0') && (str[i]<='9'))
			freq[str[i]-'0']++;
	}
}

int main(int argc, char const *argv[])
{
	char str[82];
	int freq[10]={0};
	scanf("%s",str);
	toFreq(freq,str);
	printf("There is a total of %d digits, and the sum of the digits is %d\n", countDigit(freq),sumDigit(freq));
	printHistogram(freq);
	return 0;
}


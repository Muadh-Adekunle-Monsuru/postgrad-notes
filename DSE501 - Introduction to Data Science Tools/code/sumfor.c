#include <stdio.h>

int main(){
    int input, sum=0, i;
    printf("%s","Enter a number to find its sum: ");
    scanf("%d",&input);

    for(i = 0 ; i<=input; i++)
    {
        sum += i;
        printf("for i: %d | sum:%d \n",i,sum);
    }
    return 0;
}
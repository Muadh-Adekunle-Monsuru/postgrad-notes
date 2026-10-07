#include <stdio.h>
#include <math.h>
int main(){
    float input;
    double sine; 
    printf("%s","Input a value between 0-1:");
    scanf("%f",&input);
    sine = sin(input);
    printf("\n The sine of %.3f is %lf",input, sine);


    return 0;
}
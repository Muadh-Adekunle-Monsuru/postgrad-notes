#include <stdio.h>

double square(double);
double cube(double);

int main(){
    int i,j ;
    double n;
    printf("%s","Find the square and cube of n: ");
    scanf("%lf",&n);

    for(i=1;i<n;i++){
        for(j=0;j<10;j++){
           printf("N: %f | Square: %f | Cube: %f |  \n\t",i+j/10.0,square(i+j/10.0), cube(i+j/10.0));
    }}


    return 0;
}


double square(double x){
    return (x*x);
}

double cube(double x){
    return (x*x*x);
}
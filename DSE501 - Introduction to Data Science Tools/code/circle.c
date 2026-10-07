#include <stdio.h>
#define PI 3.141

int main(){
    float radius; double area;
    printf("%s","What is the radius: ");
    scanf("%f",&radius);
    area = PI*radius*radius;
    printf("A circle with the radius %.3f has an area of %.2f",radius,area);

    return 0;
}
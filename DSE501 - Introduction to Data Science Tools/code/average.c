#include <stdio.h>

int SIZE = 5;

int main(){
    int i;
    int grades[] = {78,67,92,83,88};
    float sum=0.0;

    for(i=0;i<SIZE;i++){
        sum += grades[i];
    }

    printf("The sum of the grades is:%f and the average is %f \n",sum,sum/SIZE);


    return 0;
}
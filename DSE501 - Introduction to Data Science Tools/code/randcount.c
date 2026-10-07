#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    double median = RAND_MAX/2.0;
    int i, above_cnt=0,below_cnt=0;
    srand(time(NULL));
    for (i=0;i<1000;i++){
        int val = rand();
        if(val<median){
            below_cnt++;
        }else{
            above_cnt++;
        }
        printf("Difference: %d \t", above_cnt-below_cnt);
    }
    printf("Total above median: %d | Total below median: %d \n", above_cnt,below_cnt);

    return 0;
}
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define NCALLS 5000000000
#define NCOLS 4
#define NROWS 3

int main(){
    int i;
    float startTime, endTime;    

    startTime = time(NULL);
    srand(time(NULL));

    for(i=0;i<NCALLS;++i){
        int val = rand();
        if(i<=NCOLS*NROWS){
            printf("%7d \t",val);
        }
    }
    endTime=time(NULL);
    printf("The execution took: %fms for executing %ld random numbers", endTime-startTime, NCALLS);


    return 0;
}
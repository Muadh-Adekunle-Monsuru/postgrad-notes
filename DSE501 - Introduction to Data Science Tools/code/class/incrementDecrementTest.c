#include <stdio.h>

int main(int argc, char const *argv[]){
	int x = 5, y=10, z;
    printf("x = %d, y = %d, z = %d\n",x,y,z);
    z = y++/x++ - --x/5;
    printf("New values are : x = %d, y = %d, z = %d\n",x,y,z);

    return 0;
}
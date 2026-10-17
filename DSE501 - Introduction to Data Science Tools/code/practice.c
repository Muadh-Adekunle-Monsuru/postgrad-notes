#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void){
    char first_name[50],last_name[50],gender[2],street_name[50],city[50],country[50];
    int age, street_number, row=0;
    FILE *ctrPtr;
    char dataArray[50][8][50];

    if((ctrPtr=fopen("DSE501_Hwk1_Instructors.txt","r"))==NULL){
        printf("File does not exist");
        exit(-1);
    }else{

        printf("%s %s %s %s %s %s %s %s","First Name","Last Name", "Age","Gender","Street Name","Street Number", "City", "Country");

        while(fscanf(ctrPtr,"%[^,], %[^,], %d, %[^,], %[^,], %d, %[^,], %[^.]. \n",first_name,last_name,&age,gender,street_name,&street_number,city,country)==8){

            printf("%s %s %d %s %s %d %s %s \n",first_name,last_name,age,gender,street_name,street_number,city,country);

            strcpy(dataArray[row][0],first_name);
            sprintf(dataArray[row][4],"%d",age);

            row++
        }

        fclose(ctrPtr);
    }




    return 0;
}
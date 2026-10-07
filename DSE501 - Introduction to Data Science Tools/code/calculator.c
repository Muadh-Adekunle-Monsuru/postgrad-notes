#include <stdio.h>
#include <stdlib.h> // Required for atof




int main(int argc, char *argv[]){
    int firstNum = atoi(argv[1]);
    int secondNum = atoi(argv[2]);
    float answer;
    char sign = argv[3][0];

    if (argc < 3) {
        printf("Usage: %s <num1> <num2> <operator>\n", argv[0]);
        exit(-1); 
    }

    switch(sign){
        case '+':
            answer = firstNum + secondNum;
            break;
        case '-':
            answer = firstNum - secondNum;
            break;
        case '/':
            if(secondNum==0){
                printf("Error: cannot divide by zero \n");
                exit(-2);
            }
            answer =(float) firstNum / secondNum;
            break; 
        case 'x':
            answer = firstNum * secondNum;
            break;
        case '%':
            answer = firstNum % secondNum;
            break;
         
        default:
            printf("Error: Invalid operator '%c'\n", sign);
            return 1;
        
    }
    printf("\n The evaluation of the expression %d %s %d = %.2f \n\n",firstNum,&sign,secondNum,answer);

    return 0;
}
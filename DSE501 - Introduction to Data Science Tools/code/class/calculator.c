/* 

*/
#include <stdio.h>
#include <stdlib.h> // for atoi(), atof() etc.


int main(int argc, char const *argv[])
{
	int operand1, operand2;
   char operator;
   float result;

   if (argc > 3){
      operand1 = atoi(argv[1]);
      operand2 = atoi(argv[2]);
      operator = argv[3][0];
      // printf("You entered %d, %d, and %c on command line as argumnets\n", operand1,operand2, operator);

      switch(operator){
         case '+': result = operand1 + operand2; break;
         case '-': result = operand1 - operand2; break;
         case '%': result = operand1 % operand2; break;
         case 'x': result = operand1 * operand2; break;
         case '/': if(operand2 !=0) 
                        result =(float) operand1/operand2;
                   else {
                        printf("Denominator cannot be zero\n"); 
                        exit(-2); 

                   }; break;
         default:
            printf("The operator is not known \n");   
      } // end of switch    
   }else{
      exit(-1);
   }

   printf("%d %c %d = %7.3f\n", operand1, operator, operand2, result);

   return 0;
} // end of main
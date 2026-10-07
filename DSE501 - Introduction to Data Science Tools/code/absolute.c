/*
the following program is suppose to use the sin() function in the math library and write out an input's absolute value over an interval.  So for example if sine(0.6)  is 0.564 then its absolute value is the same (0.564). But if sine(2.4)  is -0.675 then its absolute value is 0.675. 
*/
#include<stdio.h>
#include<math.h> /* has  sin(), abs(), and fabs() */
#include<stdlib.h>
int main(void)
{ 
double interval;
int i;
for(i = 0; i <100; i++)
{
 interval = i/10.0;
 printf("sin( %lf ) = %lf || cosine(%lf) = %lf \t", interval, sin(interval), interval,fabs(cos(interval)));
}


printf("\n+++++++\n");
return 0;
}
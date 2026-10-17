// This is our first program in class.
/* Write a program that takes number of hours worked by
   and number of children an hourly worker has. The tax 
   rate is 27%, per-child allowance is 100 Euro, the hourly
   wage is 20 Euro/hour. If he/she works more than 40 hours,
   he/she is to be paid 50% more. Calculate; gros, netto, and 
   tax by this worker.
*/

#include <stdio.h>
// Let us define our constants firs
#define HOURLY_WAGE 20 
#define TAX_RATE 27
const int CHILD_ALLOWANCE = 100;
const float OVERPAY_RATIO = 1.5;

int main(int argc, char const *argv[])
{
	int numbOfChildren;
	float hours, tax, grossIncome, netIncome, taxableIncome;

	printf("Please enter number of hours you worked\n");
	scanf("%f", &hours);

	printf("Please enter number of children you have\n");
	scanf("%d", &numbOfChildren);

	if (hours > 40)
		grossIncome = HOURLY_WAGE*(40 + OVERPAY_RATIO*(hours-40));
	else
		grossIncome = HOURLY_WAGE*hours;

	// compute the taxable income
	taxableIncome = grossIncome- CHILD_ALLOWANCE*numbOfChildren;
	tax = taxableIncome*TAX_RATE/100;
	netIncome = grossIncome-tax;

	printf("The number of hours you woked is \t: %5.2f\n", hours);
	printf("The number of children y is \t\t: %d\n", numbOfChildren);
	printf("Your gross income is  \t\t \t: %7.3f\n", grossIncome);
	printf("Your taxable income is   \t\t: %7.3f\n", taxableIncome);
	printf("Your tax  is   \t \t\t\t: %7.3f\n", tax);
	printf("Your net income is   \t \t\t: %7.3f\n", netIncome);


	return 0;
}


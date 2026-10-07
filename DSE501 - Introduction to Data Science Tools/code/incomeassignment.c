#include <stdio.h>

#define HOURLY_WAGE 20
#define TAX_RATE 0.27
const int CHILD_ALLOWANCE = 100;
const float OVERPAY_RATIO = 1.5;

int main(){
    int children_count;
    double gross_income=0,taxable_income=0,tax_amount=0, net_income=0,hours;

    printf("%s","This program would calculate your net income\n");
    printf("%s","How many hours do you work: ");
    scanf("%lf",&hours);
    printf("%s","How many children do you have: ");
    scanf("%d",&children_count);

    if(hours<=40){
        gross_income = HOURLY_WAGE * hours;
    }else{
        gross_income = (40*HOURLY_WAGE) + ((hours-40)*OVERPAY_RATIO*HOURLY_WAGE);
    }

   
    taxable_income = gross_income - (children_count*CHILD_ALLOWANCE);
    if(taxable_income<0){
        taxable_income=0;
    }
    

    
    tax_amount = taxable_income * TAX_RATE;    

    net_income = gross_income - tax_amount;

    printf("\n%-14s | %-8s | %-14s | %-14s | %-12s | %-18s |\n", 
           "Hours-worked", "Children", "Gross-Income", "Taxable-Income", "Tax-Amount", "Net-income");
    printf("%-14.2f | %-8d | €%-13.2f | €%-13.2f | €%-11.2f | €%-17.2f |\n", 
           hours, children_count, gross_income, taxable_income, tax_amount, net_income);

    


    return 0;
}
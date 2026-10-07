## Core Concepts

- **Big Data (The 4 Vs):** High Volume, High Velocity, High Veracity, High Variety.
- **RAG:** Retrieval-Augmented Generation.

## Assignment 1: Matrix Multiplication
1. Show that the matrix multiplication $A = B \times C$ produces a time complexity graph of $O(N^3)$.
2. Prove that the matrix multiplication implementation is correct in C by demonstrating that the error margin is $\vert{}\vert{}A - B \times C\vert{}\vert{} < 10^{-15}$.

## C Programming Basics

C is a structured, high-level programming language (HLPL). It is a compiled language that produces a standalone executable.
- `*` denotes the **address** (pointer) of a variable.
- `&` denotes the **content** at the address (reference).
### Standard Input/Output Example

```C
#include <stdio.h>

int main() {
    char name[50]; 
    int age; 
    float weight;
    
    printf("Please enter your name:\n");
    scanf("%s", name); // Arrays decay to pointers, so no '&' is needed
    
    printf("\nNow please enter your age:\n");
    scanf("%d", &age); // '&' passes the memory address
    
    printf("\nHow much do you weigh (in kg)?\n");
    scanf("%f", &weight);
    
    // %.2f limits the output to 2 decimal places
    printf("\nHello %s, you are %d years old and weigh %.2f kg.\n\n", name, age, weight);
    
    return 0;
}
```

## Constructs of Structured HLPLs

- **Variables & Constants:** Memory storage with defined data types.
- **Statements:** Formed from tokens and expressions.
- **Branching (Conditional Execution):** `if`, `if-else`, `switch-case-break`.
- **Loops (Repetition):**
    - `for`
    - `while` (checks condition _before_ execution)
    - `do-while` (executes process once, _then_ checks condition)
- **User-Defined Functions:** Reusable blocks of scoped code.
- **Arrays:** In C, arrays are static (fixed size) and strictly typed.
- **File Handling:** Read, write, and append in both text and binary formats.

## Object-Based vs. Object-Oriented Languages (OOP)

The fundamental difference comes down to **inheritance** and **polymorphism**. While both use objects to encapsulate data and hide internal details (abstraction), only OOP languages can derive new classes from existing ones.

|**Feature**|**Object-Oriented Languages (OOP)**|**Object-Based Languages**|
|---|---|---|
|**Inheritance**|Fully supported. Subclasses inherit properties and methods.|Not supported (or severely limited).|
|**Polymorphism**|Fully supported (e.g., method overriding and overloading).|Not supported.|
|**Object Creation**|Created from user-defined blueprints (Classes).|Relies heavily on built-in objects or custom objects without strict hierarchies.|
|**Primary Focus**|Complex, reusable, scalable architectures.|Standalone entities for rapid task execution.|
|**Examples**|Java, C++, C#, Python, Ruby|Early Visual Basic, VBScript, early JavaScript, Ada|

**OOP Addendum (The 4 Pillars):**
1. Classes/Objects
2. Inheritance
3. Encapsulation
4. Polymorphism
   
## Practice Problem: Hourly Wage & Tax Calculator

**Prompt:** Ask the user for their hours worked and number of children. Calculate and display a summary breakdown of Gross Income, Taxable Income, Tax, and Net Income based on the following rules:
- **Base Pay:** €20/hour (up to 40 hours).
- **Overtime Pay:** €30/hour (for any hours > 40).
- **Tax Incentive:** €100 tax-free deduction per child.
- **Tax Rate:** 27% applied to the taxable income.
### Mathematical Breakdown

- **Gross Income:**
    - If hours $\le 40$: `hours * 20`
    - If hours $> 40$: `(40 * 20) + ((hours - 40) * 30)`
- **Taxable Income:** `Gross Income - (children * 100)` _(If this value is negative, Taxable Income is 0)_
- **Tax Amount:** `Taxable Income * 0.27`
- **Net Income:** `Gross Income - Tax Amount`

```C
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
```
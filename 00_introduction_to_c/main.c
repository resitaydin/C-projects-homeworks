#include <stdio.h>
#include "util.h"


int main() {

    /* A fractional number: 13/7 */
    int num1 = 13, den1 = 7;
    /* A fractional number: 30/11 */
    int num2 = 30, den2 = 11;
    /* An unitilized fractional number */
    int num3, den3;

    printf("First number: ");
    fraction_print(num1, den1);
    printf("\n");

    printf("Second number: ");
    fraction_print(num2, den2);
    printf("\n");

    printf("Addition: ");
    fraction_add(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Subtraction: ");
    fraction_sub(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Multiplication: ");
    fraction_mul(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    printf("Division: ");
    fraction_div(num1, den1, num2, den2, &num3, &den3);
    fraction_print(num3, den3);
    printf("\n");

    /*
     TODO: Complete this code to read two fractional numbers and print their 
             multiplication and division results...
    */
    printf("Enter numerator and denominator of the first fraction:\n");
        scanf("%d %d", &num1,&den1);		//Getting the denominator and numerator from the user.
    printf("Enter numerator and denominator of the second fraction:\n");
        scanf("%d %d", &num2,&den2);  		//Getting the denominator and numerator from the user.
     
     fraction_add(num1, den1, num2, den2, &num3, &den3);
     printf("Addition: ");
     fraction_print(num3, den3);
     printf(" \n");
     
     fraction_sub(num1, den1, num2, den2, &num3, &den3);
     printf("Subtraction: ");
     fraction_print(num3, den3);
     printf(" \n");
        
     fraction_mul(num1, den1, num2, den2, &num3, &den3);
     printf("Multiplication: ");
     fraction_print(num3, den3);
     printf(" \n");

     fraction_div(num1, den1, num2, den2, &num3, &den3);
     printf("Division: ");
     fraction_print(num3, den3);
     printf(" \n");
     
    return(0); 
}

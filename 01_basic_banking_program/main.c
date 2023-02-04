#include <stdio.h>
#include "util.h"

int main(){

    int x,y,z,n;
    char id[30];
    char id_check[30];
    int password;               //Defining some parameters.
    int password_check;
    float cash_amount;

printf("Enter the first integer: ");
    scanf(" %d", &x);                   
printf("Enter the second integer: ");       //Getting inputs from the user.
    scanf(" %d", &y);
printf("Enter the divisor: ");
    scanf(" %d", &z);
    int f_i =find_divisible(x,y,z); //Calling find_divisible function with x,y,z from the user.
    if(f_i!=0)//If any returned from the function except 0
    { 
        printf("The first integer between %d and %d divided by %d is %d\n",x,y,z,f_i);
    }
    else{   //If 0 returned
        printf("There is not any integer between %d and %d can be divided by %d\n",x,y,z);
    }

    printf("Enter the number how many next: ");
        scanf(" %d", &n);
    int nth= find_nth_divisible(n,f_i,z);//Calling find_nth_divisible function with n,f_i,z.

    if(nth<y && nth>x)//Checking for nth to be between x and y
    {
        printf("The %d. integer between %d and %d is %d\n",n+1,x,y,nth);
    }   
    else{
        printf("No possible to find Nth divisible between %d and %d divided by %d!\n",x,y,z);
    } //End of Part1

    //Beginning of Part 2
    printf("Create a customer account by entering your id: ");
            scanf("%s",id);
    int req = validate_identity_number(id);
    //Here, if all conditions are true for any id, 5 returns
    
    
    while(req!=5)//If req(requirements) is different from 5, it keeps asking
    {
        printf("Unvalid id number!\n");
        printf("Create a customer account by entering your id: ");
            scanf("%s",id);
            int req = validate_identity_number(id);
            if(req==5)//If conditions are true, this ends loop
            {
                break;
            }
    }
    printf("Enter a password: \n");
    scanf("%d", &password);
    if(create_customer(id,password)==1)//If 1 returned,it means there is no problem.
    {
        printf("Your account has been created successfully!\n");
    } //End of part 2

    //Part 3
    printf("Enter your id to log in: \n");
            scanf("%s",id_check);
       
    printf("Enter your password: ");
    scanf("%d",&password_check);

    if(check_login(id_check,password_check)==1){
        printf("You've succesfully logged in.\n");
    }
    else{
        printf("Invalid identity number or password!\n");
        return 0;
    } 
    /* Here we asked user to enter their id and password to log in and we check
    if it's true by calling check_login function. If inputs are incorrect then
    we terminate the program. */

    printf("Enter your withdraw amount: \n");
    scanf("%f", &cash_amount);
    float withdrawable = withdrawable_amount(cash_amount);
    printf("Withdrawable amount is %.0f \n", withdrawable);
    /* We asked user to enter their withdraw then we let them know how much of
    them is withdrawable by using withdrawable_amount function. */
}


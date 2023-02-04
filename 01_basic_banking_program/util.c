#include <stdio.h>
#include "util.h"

int find_divisible(int x, int y, int z){
        int counter=0;
        int f_i;
        /*In this part, I checked the numbers which is between x and y,whether they are dividible by z.
        Then, i returned the very first(smallest)one to the main function. */
        for(int i=y; i>x; i--){             
            if(i%z==0){                
                f_i=i;
                    counter++;
            }
        }
        if(counter!=0)
            return f_i;
         else{
            return 0;
         }
}
int find_nth_divisible(int n, int f_i, int z)// I found nth number by adding z*n to first number.
{
    int nth = (f_i) + (z*n);
    return nth;   
}
int validate_identity_number(char identity_number[]){
    int checking=0,n,counter=0,counter1=0,i=0;
    int odd_total=0,even_total=0;
    int total =0;
    while(identity_number[i]!='\0')// I calculated digit numbers of identity number(for first condition)
    {
        counter++;
            i++;
    }
    if(counter==11) // If it contains 11 digits, then it is okay to continue(1st condition)
    {
        checking++;
    }
    for(int i=0; i<11;i++)//Checking if they are digits or not(2nd condition)
    {
        if(identity_number[i]>='0' && identity_number[i]<='9'){
            counter1++;
        }            
    }
    if(counter1==11){
        checking++;
    }
    if(identity_number[0]!='0'){  //Checking for first digit not to be 0(3rd condition)
        checking++;
    }
    for(int i=1; i<10; i=i+2) // Calculating the total of 1,3,5,7,9. numbers
    {
      odd_total= odd_total+identity_number[i];
      odd_total = odd_total - 48;
    }
/*  Here I subtracted 48 because they are considered as char. So there occured their
    ASCII equivalent. I converted them their real values by subtracted 48.
    (Because in ASCII '0'==48,'1'==49)) */

    for(i=0; i<10; i=i+2) //Calculating the total of 0,2,4,6,8. numbers
    {
      even_total= even_total+identity_number[i];
      even_total = even_total - 48;
    }
    if((7*(odd_total)-(even_total))%10==(identity_number[10]-48)) // Checking for last condition. (4th condition)
    {
        checking++;
    }
    for(int i=0; i<10; i++){
        total = total + identity_number[i];
        total = total - 48;
    }
    if((total%10)==identity_number[10]-48)
    /*The remainder of the division by 10 of the result obtained from the sum of 
    the first 10 digits (MOD10) should give the number in the 11th digit.(5th condition) */
    {
        checking++;
    } 
    return checking;
}
int create_customer(char identity_number[], int password){
    FILE *fp;
    fp = fopen("customer.txt","w");
    fprintf(fp,"%s,%d",identity_number,password);
    fclose(fp);
    return 1;
    /* Here, I printed id and password(from the user) into the file named customer.txt */
}
int check_login(char identity_number [], int password){
    char identity_check[20];
    int password_check;
    FILE *pF = fopen("customer.txt","r"); 
    fscanf(pF,"%[^,]%*c %d",identity_check,&password_check); //Reading id and check from the file I already created before.
    fclose(pF);
    for(int i=0;i<11;i++) //Comparing inputs and the information from the file if they're same or not.
    {
        if((identity_number[i]-48)!=(identity_check[i]-48)){
        return 0;
        break;
        }
    }
    if (password_check!=password)//Comparing the passwords.
    {
        return 0;
    }
    else{
        return 1;
    }
}
int withdrawable_amount(float cash_amount) 
{
    float fraction = ((((int)cash_amount%50)%20)%10);//Finding the witdrawable amount by using % with 50,20,10
    float withdrawable = cash_amount - fraction; // For finding integer part.
    return withdrawable; //Returning integer part.
}













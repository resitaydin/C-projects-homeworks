#include <stdio.h>
#include <stdlib.h>
#include "util.h"

int main() {

    int selection;//parameter for selection problem
    float PL,PW,SL,SW; // parameters for problem 1
    float x1,x2,x3; //parameters for problem 2
    unsigned long x4,x5; //parameters for problem 2
    float age;
    float BMI;
    unsigned short smoke; //parameters for problem 3
    int workout_days;
    int junk_monthly;

    /* Ask for the problem selection (1,2,3) .....  */
    printf("Please select a problem to solve(1,2,3): ");
    scanf("%d", &selection);

    if(selection==1){ // Asking these questions if selection is 1
            printf("Enter petal length of iris flower: \n");
            scanf("%f", &PL);
            printf("Enter petal width of iris flower: \n");     //Getting inputs from the user
            scanf("%f", &PW);
            printf("Enter sepal length of iris flower: \n");
            scanf("%f", &SL);
            printf("Enter sepal width of iris flower: \n");
            scanf("%f", &SW);
    char result1 = dt1a(PL,PW,SL,SW);   //calling dt1a by assigning it to result1 and result2
    char result2 = dt1b(PL,PW,SL,SW);
    if(result1=='A'){               //A-A,A-B,A-C cases
        if(result2=='A'){
            printf("%s\n","Setosa");
        }
        else if(result2=='B'){
            printf("%s\n","Setosa");
            printf("%s\n","Versicolor");
        }
        else{
            printf("%s\n","Setosa");
            printf("%s\n","Virginia");
        }
    }
    else if(result1=='B'){  //B-A, B-B, B-C cases

        if(result2=='A'){
            printf("%s\n","Versicolor");
            printf("%s\n","Setosa");
        }
            else if(result2=='B'){
            printf("%s\n","Versicolor");
            }
                else{
            printf("%s\n","Versicolor");
            printf("%s\n","Virginia");
                }
    }
    else{       //C-A, C-B, C-C cases
        if(result2=='A'){
            printf("%s\n","Virginia");
            printf("%s\n","Setosa");
        }
                else if(result2=='B'){
            printf("%s\n","Virginia");
            printf("%s\n","Versicolor");
                }
                    else{
            printf("%s\n","Virginia");
                    }       
        }
    } // End of Problem 1
    if(selection==2){ //Calling second function if selection is 2
    printf("Enter 3 real and 2 binary numbers: ");
    scanf("%f %f %f %ld %lu",&x1,&x2,&x3,&x4,&x5); //Getting inputs from the user
    float result1 = dt2a(x1,x2,x3,x4,x5);
    float result2 = dt2b(x1,x2,x3,x4,x5);
    float dif = result1 - result2;
    if(dif<0) dif = -dif;
        if(result1==result2) printf("result is %.4f ",result1);
            else if(dif<=CLOSE_ENOUGH){     //If difference is smaller than CLOSE_ENOUGH 
        printf("%.4f\n",(result1+result2)/2); //then take its average and print it
            }
                else{
        printf("%.4f\n%.4f\n",result1,result2); //If it's not, just printing each of them individually
                }
    }//End of problem 2
    
    else if(selection==3){
        printf("How old are you?: \n");
        scanf("%f",&age);
        printf("What is your BMI? (weight/height^2): \n");
        scanf("%f",&BMI);
        printf("Do you smoke?: (yes-1,no-0)\n");
        scanf("%hu",&smoke);
        printf("How many days of week do you workout?: (0-7)\n");
        scanf("%d",&workout_days);
        printf("How many days of month do you consume junk/fast food?: (0-30)\n");
        scanf("%d",&junk_monthly);

        int r1= dt3a(age,BMI,smoke,workout_days,junk_monthly); //Returning values
        int r2= dt3b(age,BMI,smoke,workout_days,junk_monthly);

        if(r1==1){  //Comparing the values and printing according to it
            if(r2==1){
                printf("You are a healthy person. \n");
            }
            else{
                printf("You are a healthy person. \n");
                printf("You are not a healthy person. \n");
            }
        }
        else{
            if(r2==1){
                printf("You are not a healthy person. \n");
                printf("You are a healthy person. \n");
            }
            else{
                printf("You are not a healthy person. \n");
            }
        }

    } // End of problem 3
   
    return 0;
}

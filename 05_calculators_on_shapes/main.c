#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

enum shapes {Triangle=1,Quadrilateral,Circle,Pyramid,Cylinder}; //Defining first element of enum as 1 to work easier
enum Calculators {Area=1,Perimeter,Volume};

int select_shape();
int select_calc();
int calculate(int (*select_shape)(),int (*select_calc)());
int calc_triangle(int num);
int calc_quadrilateral(int num);
int calc_circle(int num);
int calc_pyramid(int num);
int calc_cylinder(int num);
void clean_stdin(void) //This function does the same thing with fflush(stdin) function on Windows.
{                      //This basically refreshes the input which we got from the user.
    int c;              
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int main(){
    printf("Welcome to the geometric calculator!\n");
        int k = calculate(&select_shape,&select_calc);  //Calling calculate function
        while(k==0){                                    //I returned 0 in all situations which we're asked to return main menu.
            k = calculate(&select_shape,&select_calc);  //The program returns the main menu repediately until returning something except 0
        }
    return 0;
}
int select_shape(){ 
    int shape;
    int counter1=0; //Counter for printing error message
    int flag=0;
    while(shape!=Triangle && shape!=Quadrilateral && shape!=Circle && shape!=Pyramid && shape!=Cylinder && shape!=0 || flag!=1){
        //These conditions force user to enter valid value which are 0,1,2,3,4,5.
        if(counter1>0){
            printf("Invalid input! Try again.\n");
            clean_stdin(); //Cleaning the input in order to prevent the program from looping infinitely.
        } 
    printf("Select a shape to calculate: \n");
    printf("-----------------------------\n");
    printf("1. Triangle\n2. Quadrilateral\n3. Circle\n4. Pyramid\n5. Cylinder\n0. Exit\n");
    printf("-----------------------------\n");
    printf("Input: ");
    flag = scanf("%d",&shape); /*Scanf function returns 1 if asked value has entered if not returns 0.
                                If the user enters integer, it returns 1. */
    counter1++;
    }
    return shape;
}
int select_calc(){
    int calculator;
    int counter=0;
    int flag=0;
        do{ 
            clean_stdin();  //Cleaning the input in order to prevent the program from looping infinitely.
            if(counter>0) printf("Invalid input! Try again.\n");
        printf("Select calculator: \n");
        printf("-----------------------------\n");
        printf("1. Area\n2. Perimeter\n3. Volume\n0. Exit\n");
        printf("-----------------------------\n");
        printf("Input: ");
        flag = scanf("%d",&calculator);
        counter++;
        }while(calculator!=Area && calculator!=Perimeter && calculator!=Volume && calculator!=0 || flag!=1 );
        //Checking the values if they are valid or not.Also we prevent user from entering any character by using flag
    return calculator;
}
int calculate(int (*select_shape)(),int (*select_calc)()){//select_shape and select_calc are parameters of calculate function.
    int shape = select_shape(); //Calling select_shape function by equalizing it to shape.
    int a,b,c,d,e;
    switch(shape){
            case Triangle:
                    a = calc_triangle(select_calc());
                   if(a==0) return 0; //If returning main menu is required, we return 0 to the main.
                    
                        break;
            case Quadrilateral:   
                   b = calc_quadrilateral(select_calc());
                   if(b==0) return 0; //If main menu is required, we return 0 to the main.
                     
                        break;
            case Circle:
                    c = calc_circle(select_calc());
                    if(c==0) return 0; //If main menu is required, we return 0 to the main.
                   
                        break;
            case Pyramid:
                   d =calc_pyramid(select_calc());
                   if(d==0) return 0; //If returning the main menu is required, we return 0 to the main.
                        break;
            case Cylinder:
                   e =calc_cylinder(select_calc());
                   if(e==0) return 0; //If asking menu is required, we return 0 to the main.
                        break;
            default:
                    break;
    }
}
int calc_triangle(int num){
    float a,b,c;
    int flag1=0,flag2=0,flag3=0;
    int counter1=0;
    while(flag1!=1 || flag2!=1 || flag3!=1 ||a>=b+c || b>=a+c || c>=a+b || a<=0 || b<=0 || c<=0 ){
        //These conditions check if inputs can create a triangle and they make us sure about the values are not negative nor 0 nor character.
         clean_stdin(); //Cleaning up input variables.
            if(counter1>0) printf("ERROR! Please enter a valid entry.\n");
            counter1++;
        switch(num){
        case Area:
            printf("Please enter three sides of Triangle: \n");
            flag1 = scanf("%f",&a);
            flag2 = scanf("%f",&b);
            flag3 = scanf("%f",&c);
            float s= (a+b+c)/2;
            float area = sqrt(s*(s-a)*(s-b)*(s-c));
            if(flag1==1 && flag2==1 && flag3==1 && b+c>a && a+c>b && a+b>c && a>0 && b>0 && c>0){
                /* I put this condition because I got some errors about printing gargabe values when
                 user enters input unvalid values. */
                printf("Area of TRIANGLE:%.2f \n",area);
                return 0; //Returning 0 because we want to return main menu.
            }
                break;
        case Perimeter:
            printf("Please enter three sides of Triangle: \n");
            flag1 = scanf("%f",&a);
            flag2 = scanf("%f",&b);
            flag3 = scanf("%f",&c);
            if(flag1==1 && flag2==1 && flag3==1 && b+c>a && a+c>b && a+b>c && a>0 && b>0 && c>0){
                /* I put this condition because I got some errors about printing gargabe values when
                 user enters input unvalid values. */
                    printf("Perimeter of TRIANGLE:%.2f \n",a+b+c);
                return 0; //To return main menu
            }
            
                break;
        case Volume:
            printf("ERROR!You cannot calculate the volume of a triangle.Please try again.\n ");
                return 0; // To return main menu
                break;
        default:
            exit(1); 
                break;
        }
    }
}
int calc_quadrilateral(int num){
        float a,b,c,d,area;
        int flag1=0,flag2=0,flag3=0,flag4=0;
        int counter=0;
    while(flag1!=1 || flag2!=1 || flag3!=1 ||flag4!=1 || a<=0 || b<=0 || c<=0 || d<=0){

        clean_stdin();  //Cleaning the input values.
        if(counter>0) printf("ERROR! Please enter a valid entry.\n");
            counter++;
        switch(num){
            case Area:
                printf("Please enter four sides of Quadrilateral: \n");
                flag1=scanf("%f",&a);
                flag2=scanf("%f",&b);
                flag3=scanf("%f",&c);
                flag4=scanf("%f",&d);
                float s = (a+b+c+d)/2;
                area = sqrt((s-a)*(s-b)*(s-c)*(s-d));
                if(flag1==1 && flag2==1 && flag3==1 && flag4==1 && a>0 && b>0 && c>0 && d>0){
                    //This checks if inputs are positive and not characters.
                    printf("Area of QUADRILATERAL: %.2f\n",area);
                    return 0;//To return main menu.
                }
                    break;
            case Perimeter:
                printf("Please enter four sides of Quadrilateral: \n");
                flag1=scanf("%f",&a);
                flag2=scanf("%f",&b);
                flag3=scanf("%f",&c);
                flag4=scanf("%f",&d);
                if(flag1==1 && flag2==1 && flag3==1 && flag4==1 && a>0 && b>0 && c>0 && d>0)//To not print any value if values are not valid.
                {
                    printf("Perimeter of QUADRILATERAL :%.2f\n",a+b+c+d);
                    return 0; //To return main menu.
                }
                    break;
            case Volume:
                printf("ERROR!You cannot calculate the volume of a Quadrilateral. Please try again.\n ");
                    return 0; //To return main menu.
                    break;
            default:    
                exit(1); 
                    break;
        }
    }
}
int calc_circle(int num){
    float r;
    int flag=0,counter=0;
    while(r<=0 || flag!=1){
        clean_stdin(); //Cleaning the input values.
        if(counter>0) printf("ERROR! Please enter a valid entry.\n");
            counter++;
        switch(num){
            case Area:
                printf("Please enter the radius of Circle: \n");
                flag = scanf("%f",&r);
                float area = PI*r*r;
                if(flag==1 && r>0){
                    //If values are valid, then we print the value.
                    printf("Area of CIRCLE: %.2f\n",area);
                    return 0; //To come back main menu.
                }
                    break;
            case Perimeter:
                printf("Please enter the radius of Circle: \n");
                flag = scanf("%f",&r);
                float perimeter = 2*PI*r;
                if(flag==1 && r>0){
                //If values are valid, then we print the value.
                    printf("Perimeter of CIRCLE :%.2f\n",perimeter);
                    return 0; //To return main menu.
                }
                    break;
            case Volume:
                printf("ERROR!You cannot calculate the volume of a Circle.Please try again.\n ");
                return 0;   //Returning 0 to come back main menu.
                    break; 
            default:
                exit(1); 
                    break;
        }
    }
}
int calc_pyramid(int num){
    float h,a,l;
    int flag1=0,flag2=0;
    int counter3=0;
    while(h<=0 || a<=0 || l<=0 || flag1!=1 || flag2!=1){
        //It keeps asking for values until user inputs positive integer.
        clean_stdin();  //Cleaning the input values.
        if(counter3>0) printf("ERROR! Please enter a valid entry.\n");
            counter3++;
        switch(num){
            case Area:
                printf("Enter the base side and slant height of a Pyramid:  \n");
                flag1= scanf("%f",&a);
                flag2= scanf("%f",&l);
                float B = a*a;
                float L = 2*a*l;
                    if(a>0 && l>0 && flag1==1 && flag2==1){
                    // Printing the values if they are valid.
                    printf("Base surface Area of a PYRAMID: %.2f\nLateral Surface Area of a PYRAMID: %.2f\nSurface Area of a PYRAMID: %.2f\n",B,L,B+L);
                    return 0; // To come back main menu
                    }
                    break;
            case Perimeter:
                printf("Enter the base side of a PYRAMID: \n");
                flag1 = scanf("%f",&a);
                if(a>0 && flag1==1){
                    // Printing the values if they are valid.
                    printf("Base surface Perimeter of a PYRAMID :%.2f\n",4*a);
                    return 0; // To come back main menu
                }
                    break;
            case Volume:
                printf("Enter the base side and height of a Pyramid:  \n");
                flag1= scanf("%f",&a);
                flag2= scanf("%f",&h);
                float volume =(a*a*h)/3;
                if(h>0 && a>0 && flag1==1 && flag2==1){
                    // Printing the values if they are valid.
                    printf("Volume of a PYRAMID: %.2f\n ",volume);
                    return 0; // To come back main menu
                }
                    break;
            default:
                exit(1);
                    break;
        }           
    }   
}
int calc_cylinder(int num){
    float r,h;
    int counter=0;
    int flag1=0,flag2=0;
    while(r<=0 || h<=0 || flag1!=1 || flag2!=1){
        // It loops until all the values are positive integer.
        clean_stdin();  //Cleaning the input values.
            if(counter>0) printf("ERROR! Please enter a valid entry.\n");
                counter++;
        switch(num){
            case Area:  
                printf("Please enter the radius and height of a  Cylinder: \n");
                flag1 = scanf("%f",&r);
                flag2 = scanf("%f",&h);
                float B = PI*r*r;
                float L = 2*PI*r*h;
                if(r>0 && h>0 && flag1==1 && flag2==1){
                    // Printing the values only if they are valid.
                    printf("Base Surface Area of a CYLINDER: %.2f\nLateral Surface Area of a CYLINDER: %.2f\n",B,L);
                    printf("Surface Area of a CYLINDER: %.2f\n",2*B+L);
                   return 0; //To come back to main menu
                }
                break;
            case Perimeter:
                printf("Please enter the radius and height of a CYLINDER: \n");
                flag1 = scanf("%f",&r);
                flag2 = scanf("%f",&h);
                float perimeter = 2*PI*r;
                if(r>0 && h>0 && flag1==1 && flag2==1){
                    // Printing the values only if they are valid.
                printf("Base Surface Perimeter of a CYLINDER: %.2f\n",perimeter);
                return 0; //To come back to main menu
                }
                break;
            case Volume:    
                printf("Please enter the radius and height of a  Cylinder: \n");
                flag1 = scanf("%f",&r);
                flag2 = scanf("%f",&h);
                float volume = PI*r*r*h;
                if(r>0 && h>0 && flag1==1 && flag2==1){
                    // Printing the values only if they are valid.
                printf("Volume of a CYLINDER: %.2f\n",volume);
                return 0; //To come back to main menu
                }
            default:
                exit(1);
                break;
        }
    }
}
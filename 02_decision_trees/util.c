#include <stdio.h>
#include "util.h"

// Example decision tree - see the HW2 description 
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
} 

char dt1a(float pl,float pw,float sl, float sw){

    char sts = 'A'; //Setosa
    char vrs = 'B'; //Versicolor
    char vrg = 'C'; //Virginia

    if(pl<2.45){
        return sts; 
    }
    else{
        if(pw>=1.75){
            return vrg;
        }
    else{
            if(pl>=4.95){
                return vrg;     //Returning char in each case according to tree we had
            }
            if(pw<1.65){
                return vrg;
            }
            else{
                return vrs;     
            }
        }
    }
}

char dt1b(float pl,float pw,float sl, float sw){
    char sts = 'A'; //Setosa
    char vrs = 'B'; //Versicolor
    char vrg = 'C'; //Virginia

    if(pl<2.55){
        return sts;
    }
    else{
        if(pw>=1.69){
            return vrg;
        }
        else{
            if(pl>=4.85){
                return vrg;     // Returning char in each case according to tree we had
            }
            else{
                return vrs;
            }
        }
    }
}// End of part1 functions

double dt2a(float x1,float x2,float x3,unsigned long x4,unsigned long x5){
    if(x1<31.5){
        if(x2>-2.5){
            return 5.0;
        }
        else{
            if((x1>=x2-01)&&(x1<=x2+0.1)){
                return 2.1;
            }
            else{
                return -1.1;
            }
        }
    }
        else{
            if(x3>=-1 && x3<=2){
                return 1.4;     //Returning to some values according to the tree 2.1
            }
            else{
                if((x4&x5)==1){
                    return -2.23;
                }
                else{
                    return 11.0;
                }
            }
        }
    }

double dt2b(float x1,float x2,float x3,unsigned long x4,unsigned long x5){

    if(x1>12&&x1<22){

            if(x3>5/3){
                return -2.0;
            }
            else{
                if((x3>=x1-0.1)&&(x3<=x1+0.1)){
                    return 1.01;
                }
                else{
                    return -8;      //Returning to some values according to the tree 2.2
                }
            }
    }
            else{
                if((x4&x5)==1){
                    return -1;
                }
                else{
                    if((x2>=-1)&&(x2<=2)){
                        return -1/7;
                    }
                    else{
                        return 0.4714; //Equivalent to sqrt(2)/3
                    }
                }
            }
    }
    int dt3a(float age,float BMI,unsigned short smoke,int workout_days,int junk_monthly){
        if(smoke==1){     //The function of the first decision tree that I had created my own
            if(junk_monthly>10){
                return 0;
            }
            else if(junk_monthly<5){    //returning true or false according to some conditions I determined.
                if(age>40){
                    return 1;
                }
                else{
                    return 1;
                }
            }
            else{
                if(workout_days>2){ //returning true or false according to some conditions I determined.
                    return 1;
                }
                else{
                     return 0;
                }
            }

        }
        else{
            if((BMI>=18.5)&&(BMI<=25)){
                return 1;
            }
            else{
                return 0;
            }
        }

    }

    int dt3b(float age,float BMI,unsigned short smoke,int workout_days,int junk_monthly){
        
        if(junk_monthly>10){ //The function of the second decision tree that I had created my own
            if(smoke==1){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if(junk_monthly<5){
            if(age>40){
                if((BMI>=18.5)&&(BMI<=25)){
                    return 1;
                }
                else{
                   return 0;        //returning true or false according to some conditions I determined.
                }
            }
            else{
                    return 1;
            }
        }
        else{
            if((BMI>=18.5)&&(BMI<=25)){     //returning true or false according to some conditions I determined.
               return 1;
            }
            else{
                return 0;
            }
        }
    }

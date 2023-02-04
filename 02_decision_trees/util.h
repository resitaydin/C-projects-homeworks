#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree 
int dt0(int t, double p, double h, char s, int w); */

char dt1a(float pl,float pw,float sl, float sw);
char dt1b(float pl,float pw,float sl, float sw);

double dt2a(float x1,float x2,float x3,unsigned long x4,unsigned long x5);
double dt2b(float x1,float x2,float x3,unsigned long x4,unsigned long x5);

int dt3a(float age,float BMI,unsigned short smoke,int workout_days,int junk_monthly);
int dt3b(float age,float BMI,unsigned short smoke,int workout_days,int junk_monthly);


#endif /* _UTIL_H_ */

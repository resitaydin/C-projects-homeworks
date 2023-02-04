#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n2*d1 + n1*d2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
   *n3 = n1*d2 - n2*d1;
   *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = d1*n2;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d){
	 int max_num=1;
	 if(*n<0){				//Dividing into 2 situations according to they're negative or positive.
	 *n = -*n;				//for being negative
    for(int i=2; i<=*n; i++){
    	if(*d%i==0 && *n%i==0){
    		max_num=i;			//Finding out GCD of n and d.
    		} 
    	}	
    		*n = -*n/max_num;		//Simplifying n and d by dividing their GCD.
    		*d = *d/max_num;
    		}
    	else{					//for being negative
    for(int i=2; i<=*n; i++){
    	if(*d%i==0 && *n%i==0){
    		max_num=i;			//Finding out GCD of n and d.
    		} 
    	}	
    		*n = *n/max_num;		//Simplifying n and d by dividing their GCD.
    		*d = *d/max_num;
    		}
    		
} /* end fraction_simplify */

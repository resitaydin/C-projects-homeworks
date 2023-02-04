#include <stdio.h>
#include <stdlib.h>
#include "util.c"

int main(){

    int xs,seqlen,currentlen=0;
    printf("Please enter the sequence length: ");
    scanf("%d",&seqlen);
    printf("Please enter the first element: ");
    scanf("%d",&xs);
    int looplen=seqlen/2;
    int h[9]; //Histogram array.
    int digit=1;
    int *loop = (int*)calloc(looplen,sizeof(int)); //Creating loop array.
    check_loop_iterative(&generate_sequence,xs,seqlen,loop,&looplen); //Generating and printing main sequence.
    if(looplen==0){
        printf("No loop found.\n\n");
    }
    if(looplen!=0){ //If there is a loop
        printf("Loop: {"); //Printing loop
        for(int i=0;i<looplen;i++){
            if(i==looplen-1) printf("%d}\n\n",loop[i]);
            else printf("%d, ",loop[i]);
        } 
    }
    hist_of_firstdigits(&generate_sequence,xs,seqlen,h,digit); //Generating histogram sequence.
    printf("Histogram of the sequence: {"); //Printing histogram sequence.
    for(int i=1;i<10;i++){
        if(i==9) printf("%d}\n",h[i]);
        else printf("%d, ",h[i]);
    }
    return 0;
}
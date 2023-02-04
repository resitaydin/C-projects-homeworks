#include <stdio.h>
#include<stdlib.h>
#include "util.h"
void generate_sequence(int xs,int currentlen,int seqlen,int *seq){ //Generating sequence
    *seq=xs; 
    if(currentlen==seqlen-1){ //Base case 1 to stop loop.
        return;
      } 
    if(*(seq+currentlen)%2==0){ //If the number is even we divide it by 2.
        *(seq+currentlen+1) = *(seq+currentlen)/2;
    }
    if(*(seq+currentlen)%2==1){ //If it is odd number, we multiply it by 3 and add 1.
       *(seq+currentlen+1) = *(seq+currentlen)*3+1;
   }
   currentlen++; 
    generate_sequence(xs,currentlen,seqlen,seq);
}
int has_loop(int *arr,int n,int looplen,int *ls,int *le){
    int loop=0;
    int counter=0,counter1=0,counter2=0; 
    printf("Checking if there is a loop of length %d...\n",looplen);
    for(int i=n-1;i>=0;i--){ 
        if(arr[n-1]==1){ // This is the case if last element is 1.
            if(arr[i]==1){
                counter++;
            }
            else if(arr[i]==4){ 
                counter1++;
                *ls=i; //Starting point
            }
            *le = *ls + looplen-1;
        }
        else if(arr[n-1]==2){// This is the case if last element is 2.
            if(arr[i]==2){
                counter++;
            }
            else if(arr[i]==1){
                counter1++;
                *ls=i; //Starting point
            }
             *le = *ls + looplen-1;
        }
        else if(arr[n-1]==4){ // This is the case if last element is 4.
            if(arr[i]==4){
                counter++;
            }
            else if(arr[i]==2){
                counter1++;
                *ls=i; //Starting point
            }
             *le = *ls + looplen-1;
        }
    }
        if(counter>counter1) counter=counter1;
        else counter1=counter;
            if(looplen%3==0 && counter%2==0 && 3*counter/2==looplen ||looplen%3==0 && counter%2==1 && 3*counter/2==looplen+1){
                printf("\n\n\nLoop detected with a length of %d.\n",looplen);
                printf("The indexes of the loop's first occurance: %d (first digit), %d (last digit)\n",*ls,*le);
                return 1;
            }
            else return 0;        
}
void check_loop_iterative(void (*f)(int xs,int currentlen,int seqlen,int *seq),int xs, int seqlen, int *loop,int *looplen){
    int length = *looplen;
    int *seq = (int*)calloc(seqlen,sizeof(int)); //Creating sequence dynamically.
    if(seq==NULL){
        printf("Memory couldn't be allocated!\n");
        exit(1);
    }
    int currentlen=0;
    f(xs,currentlen,seqlen,seq); //Generating sequence
    if(*looplen==seqlen/2){
    printf("Sequence: {"); //Printing sequence
        for(int i=0;i<seqlen;i++){
            if(i==seqlen-1) printf("%d}",seq[i]);
            else printf("%d, ",seq[i]);
        }
         printf("\n\n");  //End of generating and printing sequence.
    }
        //We're gonna check for loop for this sequence.
        int ls,le; 
        int k = has_loop(seq,seqlen,length,&ls,&le);
        //Creating loop array.
            if(seq[seqlen-1]==4){   //If the last element is 4.
                for(int i=0;i<le-ls;i+=3){
                    loop[i]=2;
                    loop[i+1]=1;
                    loop[i+2]=4;
                } 
            }
            else if(seq[seqlen-1]==1){ //If the last element is 1.
                for(int i=0;i<le-ls;i+=3){
                    loop[i]=4;
                    loop[i+1]=2;
                    loop[i+2]=1;
                } 
            }
            else if(seq[seqlen-1]==2){ //If the last element is 2.
                for(int i=0;i<le-ls;i+=3){
                    loop[i]=1;
                    loop[i+1]=4;
                    loop[i+2]=2;
                } 
            }
        if(k==1){
            return; //To stop recursion.
        } 
        length--;
        if(length==1){
            *looplen=0;
            return;
        }
        free(seq); //Unloading seq array.
        *looplen=length;
        check_loop_iterative(&generate_sequence,xs,seqlen,loop,looplen);
}

void hist_of_firstdigits(void (*f)(int,int,int,int*), int xs, int seqlen, int *h, int digit){
    int *seq = (int*)calloc(seqlen,sizeof(int)); //Creating sequence dynamically.
    if(seq==NULL){
        printf("Memory couldn't be allocated!\n");
        exit(1);
    }
    int currentlen=0;
    f(xs,currentlen,seqlen,seq); //Generating sequence
    int new_arr[seqlen];
    for(int i=0;i<seqlen;i++){
        if(seq[i]<10)new_arr[i]= seq[i];
                while(seq[i]>=10){  //Finding first digits of array elements.
                seq[i]= seq[i]/10;
                }   
                new_arr[i]=seq[i];
    }
    free(seq); //Unloading seq array.
    int counter=0;
    for(int i=0;i<seqlen;i++){
        if(new_arr[i]==digit) counter++;
    }
    h[digit]=counter;
    digit++;
    if(digit==10) return; //We count how many numbers in array between 1-9 so we stop at 10.
    hist_of_firstdigits(&generate_sequence,xs,seqlen,h,digit);
}



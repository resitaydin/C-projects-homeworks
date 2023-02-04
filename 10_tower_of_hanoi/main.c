#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// WARNING! This code is not a complete code since i did not have enough time to finish this homework.

//This code can be completed using the algorithm that exists on the internet.

#define STACK_BLOCK_SIZE 10

typedef struct{int *array;int currentsize;int maxsize;}stack;
int push(stack* s,int d);
int pop(stack* s);
stack * init_return(); //Initializes an empty stack.
int init (stack* s); //returns 1 if initialization is successful.
void disk_move_print(int source, int dest, int disk);

int main(){
    int disk_num;
    printf("Enter the disk number: ");
    scanf("%d",&disk_num);
    stack *source,*dest,*assist;
    source = dest = assist = init_return(); // Initializing the holes.
    int a= init(source);
    int b =init(dest);
    int c =init(assist);
    if(a==0 || b==0 || c==0) printf("Error while initialization!\n");
    for (int i = disk_num; i >= 1; i--) push(source, i); //First case.
    printf("Source disk is: ");
    for (int i = 0; i <disk_num; i++) printf("%d ",source->array[i]);
        return 0;
}
stack *init_return(){
    stack* new_hole = (stack*)malloc(sizeof(stack));  //Creating stack structs.
    new_hole->currentsize = -1;
    new_hole->maxsize = STACK_BLOCK_SIZE;
    return new_hole;
}
int init(stack* s){
    s->array = (int*)malloc(sizeof(int)*s->maxsize);  //Creating array dynamically.
    if(s->array!=NULL) return 1;
    else return 0;
}
int push(stack *s,int d){
    if(s->currentsize==s->maxsize) return 0; //If array is full, we return 0 for error message.
    s->currentsize++; //Changing the location of top.
    s->array[s->currentsize] = d;
    s->maxsize++; // Enlarging maxsize of array by 1 each time.
}
int pop(stack *s){
    if(s->currentsize==-1) {
        return 0;
    }
    int top = s->array[s->currentsize];
    s->currentsize--;
    return top;
}
void disk_move_print(int source, int dest, int disk){
    printf("Move the disk %d from '%d' to '%d'\n",disk,source,dest);
}



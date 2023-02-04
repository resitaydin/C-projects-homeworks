#include <stdio.h>
#include <math.h>
int sum (int n1, int n2, int flag);
int multi (int n1, int n2, int flag);
int isprime (int a);
int howmany_num();
void write_file(int a);
void print_menu();
void print_file();
void sort_file();
void copy_temp_to_result();
int main(){
     int operation=0;
    while(1){
        print_menu();
        scanf("%d",&operation);
        if(operation==1){
        int n1,n2,flag_opr,flag; //Part 1 parameters
        printf("Please enter '0' for sum,'1' for multiplication: \n");
        scanf("%d",&flag_opr);
        printf("Please enter '0' to work on even numbers,'1' to work on odd numbers: \n");
        scanf("%d",&flag); 
        printf("Please enter two different numbers: \nNumber 1: \nNumber 2: \n");
        scanf("%d %d",&n1,&n2); 
            switch(flag_opr){
                case 0: 
                sum(n1,n2,flag);
                    break;
                case 1:
                multi(n1,n2,flag);
                    break;
                default:
                printf("Error, invalid number!\n");
                    break;
            } //End of Part 1
        }
        else if(operation==2){
            int num; //Beginning of part 2
        printf("Please enter an integer: \n");
        scanf("%d",&num);
            for(int i=2; i<num; i++){ //Checking for every number between 1-num if they're prime or not.
                if(isprime(i)==0){ //Checking the flag coming from isprime function.
                printf("%d is a prime number.\n",i);
                }
                    else{
                    printf("%d is not a prime number, it is dividible by %d\n",i,isprime(i));
                    }
            }
        }
        else if(operation==3){
        print_file();
        }

        else if(operation==4){
        sort_file();
        copy_temp_to_result();
        print_file();
        
        }
        else if(operation==0){
            break;
        }
        else{
        printf("Error!Invalid number!\n");// Error message in case user enters invalid number which neither of 1,2,3, or 4.
        }
    }
    return 0;
} 
int sum (int n1, int n2, int flag){
    int sum=0;
    for(int i=(n1+1);i<n2;i=i+2){
        if(flag==0){    //flag exists for determining working on even or odd numbers.
            if(i%2==0){ 
                printf("%d ",i);
                sum = sum+i;
                if(i==n2-1 || i==n2-2) break; // To delete last plus sign.
                printf("+ ");
            }
            else{
                i++;
                printf("%d",i);
                sum = sum+i;
                if(i==n2-1 || i==n2-2) break; // To delete last plus sign.
                printf(" + ");
            }
        }
        else if(flag==1){
            if(i%2==1){
                printf("%d ",i);
                sum = sum+i;
                if(i==n2-1 || i==n2-2) break; // To delete last plus sign.
                printf("+ ");   
            }
            else{
                i++;
                printf("%d",i);
                sum = sum+i;
                if(i==n2-1 || i==n2-2) break; // To delete last plus sign.
                printf(" + ");  
            }
        }
    }   
        printf("= %d \n",sum);
        write_file(sum);
}//End of sum function
int multi (int n1, int n2, int flag){
        int prdct=1;
    for(int i=(n1+1);i<n2;i=i+2){
        if(flag==0){
            if(i%2==0){
                printf("%d ",i);
                prdct = prdct*i;
                if(i==n2-1 || i==n2-2) break; // To delete last product sign.
                printf("* ");
            }
            else{
                i++;
                printf("%d ",i);
                prdct = prdct*i;
                if(i==n2-1 || i==n2-2) break;
                printf("* "); // To delete last plus sign.
            }
        }
                else if(flag==1){
            if(i%2==1){
                printf("%d ",i);
                prdct = prdct*i;
                if(i==n2-1 || i==n2-2) break; // To delete last plus sign.
                printf("* ");
            }
            else{
                i++;
                printf("%d ",i);
                prdct = prdct*i;
                if(i==n2-1 || i==n2-2) break; // To delete last plus sign.
                printf("* ");
            }
                }
    }
        printf("= %d \n",prdct);
        write_file(prdct);
}
int isprime (int a){
    int counter=0,least_div=0,flag=0;
    int sqrt_a=sqrt(a); //Finding the square root of a separately.
    for(int i=sqrt(a);i>1;i--){ //Controlling i between 1-sqrt(a).
        if(a%i==0){ //if a can be divided by i, it's not a prime number.
            counter++;
            least_div=i;
        }
    }
    if(counter>=1){ //if counter >=1 it is not a prime number.
        return least_div;   //returning the least divisor of the number which is not a prime.
        }
        else{
            return flag;    //returning flag for being prime.
        }
}
void write_file(int a){
    FILE *fP;
    fP= fopen("result.txt","a");
        if(fP==NULL) printf("Can't open new file! \n"); //In case of any errors occur while opening the file.
    fprintf(fP," %d",a);
    printf("The result is written to the result.txt file.\n ");
    fclose(fP);
}
void print_file(){
    FILE *fP;
    int a;
    fP=fopen("result.txt","r");
    printf("Result: \n");
    while(!feof(fP)){
        fscanf(fP,"%d",&a);//Reading from the file and
        printf("%d ",a);  //printing onto the screen.
    }
    fclose(fP);
}
void print_menu(){  
    printf("\nSelect Operation \n");
    printf("1. Calculate sum/multiplication between two numbers \n");
    printf("2. Calculate prime numbers \n");
    printf("3. Show number sequence in file \n");
    printf("4. Sort number sequence in file \n");
    printf("--------------------------------- \n");
    printf("To exit please press 0 \n");
}
void sort_file(){
        FILE *fp; //File pointers
        FILE *fP;
        int a=0,min1=999999,min2=999999,min3=999999;
        int temp1=0,temp2=0,temp3=0;
        int i=1;
        int counter = howmany_num();
        fp= fopen("result.txt","r"); //opening result.txt file in reading mode.
        fP=fopen("temp.txt","a");     //creating and opening temp.txt file in append mode.
    while(i<=counter/3){
        while(!feof(fp)){   //This loops ends when the file pointer reaches at the end of file.
            fscanf(fp,"%d",&a);
            if(a>temp3){
                    if(a<min1){    //Sorting algorithm for 3 numbers.
                    min3=min2;
                    min2=min1;
                    min1=a;
                    }
                    else if(a<min2){ //Sorting algorithm for 3 numbers.
                    min3=min2;
                    min2=a;
                    }
                    else if(a<min3){ //Sorting algorithm for 3 numbers.
                    min3=a;
                    }   
            }
        }
        fprintf(fP,"%d %d %d ",min1,min2,min3);  //printing the least 3 numbers to temp.txt file.
        temp1=min1,temp2=min2,temp3=min3;
        i++;
    }
        if(counter==2){   //When 2 numbers left in result.txt file
            if(a>temp3){
                if(a<min1){
                    min2=min1;
                    min1=a;
                }
                    else if(a<min2){
                    min2=a;
                    }
            }
          fprintf(fP,"%d %d",min1,min2);    //printing min 1 and min2 to temp.txt
        }
        else if(counter==1){  //When 1 number left in result.txt file
            if(a>temp2){
                min1=a;
            }
            fprintf(fP,"%d",min1);  //printing min 1 to temp.txt
        }
}
    int howmany_num(){ //The function to determine how many numbers exist in result.txt file
        FILE *nP;
        nP=fopen("result.txt","r");
        int counter=0;
        int a;
        while(!feof(nP)){
            fscanf(nP,"%d",&a);
            counter++; //increasing counter for every number
        }
        fclose(nP);
        return counter;
    }
    void copy_temp_to_result(){
        FILE *fp1,*fp2;
        int a;
        fp1=fopen("result.txt","w");
        fp2=fopen("temp.txt","r");
        while(!feof(fp2)){
            fscanf(fp2,"%d",&a);
            fprintf(fp1,"%d ",a);
        }
        fclose(fp1);
        fclose(fp2);
    }

        
    
    


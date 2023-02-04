#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// This program does not use txt as a database for each run.
union Person{ char name[50]; char address[50]; int phone;};
union Loan{float arr[3];}; //Amount,interest rate,period
typedef struct BankAccount{union Person Customer; union Loan Loans[4];}BankAcc;

BankAcc new[50]; //Struct array for maximum 50 customers.
int counter_arr[50]={0};  //Initializing array with 0's.
void menu();
void addCostumer(int i,FILE *fP);
void listCustomers(int counter);
void newLoan(int counter);
float calculateLoan(float amount, int period, float interestRate);
void getReport(int selection,int counter);
void clean_stdin(void) //This function does the same thing with fflush(stdin) function on Windows.
{                      //This basically refreshes the input which we got from the user.
    int c;              
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
int main(){
    int selection=0, select=0, counter=0; 
    while(1){
        menu();
        scanf("%d",&selection);
        if(selection==1){
            if(counter==0)printf("Nothing to list here.\n");
            listCustomers(counter); 
        }
        else if(selection==2){
            FILE *fP = fopen("customer.txt","a"); // Creating customer txt to write.
            addCostumer(counter,fP);
            counter++; //Increasing counter for every new user.
        }
        else if(selection==3) newLoan(counter);
        else if(selection==4){
            printf("1. Customer Detail\n2. Loan Detail\n");
            scanf("%d",&select);
            getReport(select,counter);
        }
        else if(selection==5)break;
        else printf("Invalid number!\n");
    }
    return 0;
}
void menu(){
    printf("=====================================\n"); printf("Welcome to the Bank Management System\n");  
    printf("=====================================\n");      //MENU
    printf("     1. List All Customers\n     2. Add New Customer\n");
    printf("     3. New Loan Application\n     4. Report Menu\n     5. Exit System\n");
}
void addCostumer(int i,FILE *fP){
    int c ;
    if(fP==NULL){
        printf("File error!\n"); exit(1); //If file cannot be opened.
    }
    clean_stdin();
        printf("Enter Customer Phone: ");
    
    scanf("%d",&new[i].Customer.phone);
    fprintf(fP,"%d\n",new[i].Customer.phone);
    clean_stdin();
        printf("Enter Customer Address: ");
    
    scanf("%[^\n]%*c",new[i].Customer.address);
    fprintf(fP,"%s\n",new[i].Customer.address);
    
        printf("Enter Customer Name: ");
            
    scanf("%[^\n]%*c",new[i].Customer.name);   //To read a line with ignoring spaces.
    fprintf(fP,"%s\n",new[i].Customer.name);
    fclose(fP);
}
void listCustomers(int counter){
    for(int i=0;i<counter;i++) printf("Customer %d : %s\n",i+1,new[i].Customer.name); //Listing customers.
}
void newLoan(int counter){
    int c;
    char name[50]; int customer_num=0;
    clean_stdin();
    printf("Enter customer name: ");
    scanf("%[^\n]%*c",name);
    for(int i=0;i<counter;i++){
        if(strcmp(new[i].Customer.name,name)==0)customer_num=i; //Comparing the input with our customer struct.
    }
    counter_arr[customer_num]++;
        if(counter_arr[customer_num]>3){
            printf("You can't have loan anymore!\n"); return;  //If customer has over 3 loans.
        }
        printf("Enter the amount of loan: ");
    scanf("%f",&new[customer_num].Loans[counter_arr[customer_num]].arr[0]); 
        if(new[customer_num].Loans[counter_arr[customer_num]].arr[0]<=0){ //For invalid inputs.
            printf("Unvalid amount!\n"); return;
        }
    float amount = new[customer_num].Loans[counter_arr[customer_num]].arr[0];
        printf("Enter interest rate: ");
    scanf("%f",&new[customer_num].Loans[counter_arr[customer_num]].arr[1]);
        if(new[customer_num].Loans[counter_arr[customer_num]].arr[0]<=0){ //For invalid inputs.
            printf("Unvalid interest rate!\n"); return;
        }
    float interestRate = new[customer_num].Loans[counter_arr[customer_num]].arr[1];
        printf("Enter period: ");
    scanf("%f",&new[customer_num].Loans[counter_arr[customer_num]].arr[2]);
        if(new[customer_num].Loans[counter_arr[customer_num]].arr[2]<=0){ //For invalid inputs.
            printf("Unvalid period!\n"); return;
        }
    int period = (int)new[customer_num].Loans[counter_arr[customer_num]].arr[2];
    float loan=calculateLoan(amount,period,interestRate);
    new[customer_num].Loans[counter_arr[customer_num]].arr[0] = loan; //Updating our array with the loan that we calculated.
}
float calculateLoan(float amount, int period, float interestRate){
    if(period==1) return amount*(1+(interestRate/100));  //Dividing it by 100 because, it is x/100 rate.
    else return (1+(interestRate/100))*calculateLoan(amount,period-1,interestRate);
}
void getReport(int selection,int counter){
    FILE *fp = fopen("customer.txt","r");
    int phone; char address[50]; char name[50];
    if(selection==1){
        for(int i=0;i<counter;i++){
        fscanf(fp,"%d ",&phone);
        fscanf(fp,"%[^\n]%*c",address);  //Reading phone,address and names of customers from the file.
        fscanf(fp,"%[^\n]%*c",name);
        printf("Customer ID = %d\nCustomer Name = %s\n",i+1,name);
        printf("Customer Phone = %d\nCustomer Address = %s\n",phone,address);
            if(counter_arr[i]==1){
                printf("Loan: %.2f\n\n",new[i].Loans[1].arr[0]);  //Printing loan 
            }
            else if(counter_arr[i]==2){
                float loan1= new[i].Loans[1].arr[0];
                float loan2= new[i].Loans[2].arr[0];
                printf("Loans = [%.2f + %.2f ] => %.2f\n\n",loan1,loan2,loan1+loan2);//Printing loans
            }
            else if(counter_arr[i]==3){
                float loan1= new[i].Loans[1].arr[0];
                float loan2= new[i].Loans[2].arr[0];
                float loan3= new[i].Loans[3].arr[0];
                printf("Loans = [%.2f + %.2f + %.2f] => %.2f\n\n",loan1,loan2,loan3,loan1+loan2+loan3);//Printing loans
            }
        }
    }
    else if(selection==2){
        int ID, loan_th, period; float total_loan;
        printf("Enter customer ID: ");
        scanf("%d",&ID);
        printf("Which loan do you want to get report (1,2,3): ");
        scanf("%d",&loan_th);
        period = new[ID-1].Loans[loan_th].arr[2];
        total_loan = new[ID-1].Loans[loan_th].arr[0];
        printf("Total Credit Value: %.2f\n",total_loan);  //Printing detailed credit values.
        for(int i=1;i<period+1;i++) printf("%d. Month Installment = %.2f\n",i,total_loan/period);
    }
}
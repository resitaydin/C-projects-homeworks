#include <stdio.h>
//The program printing the curves on analytical plane
void menu();
void draw_curse(int a,int b,int c);
void draw_into_file(int a,int b,int c);
void red () {
  printf("\033[0;31m");
}
void blue () {
  printf("\033[0;34m");
}
void reset () {
  printf("\033[0m");
}
int main(){
    int oprt;
    while(1){   //Infinite loop for menu
        menu();
        scanf("%d",&oprt);
        int a,b,c;      
        if(oprt==1){
            printf("Please enter the coefficients for the following equation: x=a*(y*y) + b*y + c\n");
            printf("a: ");
            scanf("%d",&a);
            printf("b: ");
            scanf("%d",&b);
            printf("c: ");
            scanf("%d",&c);

            FILE *fp;
            fp=fopen("coefficients.txt","w");
            if(fp==NULL) printf("The file can't be opened!");
            fprintf(fp,"%d\n%d\n%d",a,b,c);
            printf("coefficients.txt file has been created.\n");
            fclose(fp);
        }
        else if(oprt==2){
                int a,b,c;
                FILE *fP;
                fP=fopen("coefficients.txt","r");
                if(fP==NULL) printf("The file does not exist!!\n");
                    fscanf(fP,"%d\n",&a);
                    fscanf(fP,"%d\n",&b);
                    fscanf(fP,"%d\n",&c);
                    printf("Coefficients has been read from the coefficitens.txt file.\n");
                    printf("Printing the graph of x = %d*y*y + %d*y + %d\n",a,b,c);
                    draw_curse(a,b,c);
                    fclose(fP);
        }
        else if(oprt==3){
            int x,y,z;
                FILE *FP;
                FP=fopen("coefficients.txt","r");
                if(FP==NULL) printf("The file does not exist!!\n");
                    fscanf(FP,"%d\n",&x);
                    fscanf(FP,"%d\n",&y);
                    fscanf(FP,"%d\n",&z);
                printf("Coefficients has been read from the coefficitens.txt file.\n");
                draw_into_file(x,y,z);
                printf("The graph of x = %d*y*y + %d*y + %d has been written to graph.txt file\n",x,y,z);
                fclose(FP);
        }
        else if(oprt==4){
            break;
        }
        else{
            printf("Error!Invalid number!\n");
            menu();
            scanf("%d",&oprt);
        }
    }
    return 0;
}

void menu(){
printf("Select an operation...\n");
printf("1 -> Enter the coefficients.\n");
printf("2 -> Draw the graph.\n");
printf("3 -> Print the graph into a .txt file. \n");
printf("4 -> Exit.\n");
printf("Choice: ");
}
void draw_curse(int a,int b,int c){
    
    for(int y=16;y>=-15;y--){
        for(int x=-56;x<=56;x++){
            if(x==a*y*y+b*y+c &&y!=16) { //if equation equal to x
            blue();
            printf("#");
            reset();
            }
            else if(y==16 && x==0) printf("^");
            else if(x==-56 && y==0) printf("<");    //Printing symbols to the terminal
            else if(x==56 && y==0) printf(">");
            else if(x==0) {
            red();
            printf("|");
            reset();
            }
            else if(y==0) {
            red();
            printf("-");
            reset();
            }
            else if(x%10==0 && y==-1 && x<0) printf("\b\b%d",x);    //printing numbers
            else if(x%10==0 && y==-1 && x>0) printf("\b%d",x);
            else if(x==-1 && y==-1) printf("0");                    //printing numbers
            else if(y==5 && x==-1) printf("5");                     //printing numbers
            else if(y==10 && x==-1) printf("\b10");
            else if(y==-10 && x==-1) printf("\b\b-10");             //printing numbers
            else if(y==-5 && x==-1) printf("\b-5");
            else if(y==15 && x==-1) printf("\b15");                 //printing numbers
            else if(y==-15 && x==-1) printf("\b\b-15");
            else printf(" ");
        }
        printf("\n");
    }
}
void draw_into_file(int a,int b,int c){
    FILE *fP;
    fP=fopen("graph.txt","w");

    for(int y=16;y>=-15;y--)
    {
        for(int x=-56;x<=56;x++)
        {
            if(x==a*y*y+b*y+c) fprintf(fP,"#");         //Printing symbols into the file
            else if(y==15 && x==0) fprintf(fP,"^");
            else if(x==-55 && y==0) fprintf(fP,"<");
            else if(x==55 && y==0) fprintf(fP,">");         //Printing symbols into the file
            else if(x==0 && y<15 && y>-15) fprintf(fP,"|");
            else if(y==0 &&x>-55 && x<55) fprintf(fP,"-");      //Printing symbols into the file
            else fprintf(fP," ");
        }
        fprintf(fP,"\n");
    }
    fclose(fP);
}
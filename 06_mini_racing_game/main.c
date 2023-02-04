#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void red () {
  printf("\033[1;31m");
}
void green () {
  printf("\033[1;32m");
}
void yellow () {
  printf("\033[1;33m");
}
void blue () {
  printf("\033[1;34m");
}
void reset () {
  printf("\033[0m");
}
char map [15][30];
void printMap(int x1, int y1,int x2, int y2);
int dice();
int start_game(int dice1,int dice2);
int print_player1();
int print_player2();

int main(){
    int dice_player1=0, dice_player2=0;
    int first_player=0;
    int x1=1,y1=1;
    int x2=3,y2=3;
    int remain=0,remain1=0,remain2=0,check=0;
    int remain3=0,remain4=0,remain5=0,check1=0;
    int winner=0;
    map[1][1] = '1';
    map[3][3] = '2';
    printMap(x1,y1,x2,y2);
    printf("To start the game, players should dice and decide who is going to start first according to it...\n");
    do{
    srand(time(NULL));
    dice_player1 = print_player1();
    srand(time(NULL));
    dice_player2 = print_player2();
    first_player = start_game(dice_player1,dice_player2);  //Determining the player who plays first
    }while(first_player==0);
    while(1){
        if(first_player==1){
            //Beginning of Player1's code section
            srand(time(NULL));
            dice_player1 = print_player1();
            if(check==0){
                if(y1==28){
                    x1 = x1 + dice_player1;
                    if(x1==7){
                        x1=x1-2;
                        yellow();
                        printf("Penalty point for Player1..\n");//Penalty point for Player 1
                        reset(); 
                    }
                    if(x1>=13) check=1;
                }
                if(y1<28){
                y1 = y1 + dice_player1;
                    if(y1==14){
                        y1=y1-2;
                        yellow();
                        printf("Penalty point for Player1..\n");//Penalty point for Player 1
                        reset(); 
                    } 
                }
                if(y1>28){
                    remain = y1-28;
                    x1 = x1 + remain;
                    y1 = 28;
                }
            }
            if(check==1){
                if(x1==13){
                    y1 = y1-dice_player1;
                    if(y1==14){
                        y1 = y1+2;
                        yellow();
                        printf("Penalty point for Player1..\n");//Penalty point for Player 1
                        reset(); 
                    } 
                    if(y1<=1) check=2;
                }
                else if(x1>13){
                    remain1 = x1-13;
                    y1 = y1 - remain1;
                    x1 = 13;
                }
            }
            if(check==2){
                if(y1==1){
                    x1 = x1 - dice_player1;
                    if(x1<=2){
                        check=0;
                        winner=1;
                    } 
                }
                if(y1<1){
                remain2 = 1-y1;
                x1 = x1 - remain2;
                y1=1;
                }
            }
            map [x1][y1] = '1';
            if(winner==1){
                printf("***PLAYER 1 WON THE GAME***\n");
                printMap(x1,y1,x2,y2);
                break;
            }
            //End of Player1's code section
            //Beginning of Player2's code section.
            srand(time(NULL));
            dice_player2 = print_player2();
            if(check1==0){
                if(y2<26){
                    y2 = y2 + dice_player2;
                    if(y2==10 || y2==18){ //Penalty points for Player 2
                        y2 = y2-2;
                        blue();
                        printf("Penalty point for Player2..\n");
                        reset(); 
                    }
                }
                if(y2==26){
                    if(x2<11)  x2 = x2 + dice_player2;
                    if(x2>=11) check1 = 1;
                    if(x2==5 || x2==10){ //Penalty points for Player 2
                        x2=x2-2;
                        blue();
                        printf("Penalty point for Player2..\n");
                        reset(); 
                    }
                }
                else if(y2>26){
                    remain3= y2-26;
                    x2 = x2 + remain3;
                    if(x2==5 || x2==10){ //Penalty points for Player 2
                        x2=x2-2;
                        blue();
                        printf("Penalty point for Player2..\n");
                        reset(); 
                    } 
                    y2=26;
                }
            }
            if(check1==1){
                if(x2==11){
                    if(y2>3) y2 = y2 - dice_player2;
                    if(y2<=3)check1=2;
                    if(y2==10 || y2==18) y2=y2-2;
                }
                if(x2>11){
                    remain4= x2-11;
                    y2 = y2-remain4;
                    x2=11;
                }
            }
            if(check1==2){

                if(y2==3){
                    x2=x2-dice_player2;
                    if(x2<=3){
                        check1=0;
                        winner=2;
                    } 
                } 
                if(y2<3){
                    remain5 = 3-y2;
                    x2 = x2-remain5;
                    y2=3;
                }
            }
            map[x2][y2] = '2';
            if(winner==2){
                printf("***PLAYER 2 WON THE GAME***\n");
                printMap(x1,y1,x2,y2);
                break;
            }
            //End of Player2's code section.
        }
        else if(first_player==2){
            //Beginning of Player2's code section.
            srand(time(NULL));
            dice_player2 = print_player2();
            if(check1==0){
                if(y2<26){
                    y2 = y2 + dice_player2;
                    if(y2==10 || y2==18){ //Penalty points for Player 2
                        y2 = y2-2;
                        blue();
                        printf("Penalty point for Player2..\n");
                        reset(); 
                    }
                }
                if(y2==26){
                    if(x2<11)  x2 = x2 + dice_player2;
                    if(x2>=11) check1 = 1;
                    if(x2==5 || x2==10){ //Penalty points for Player 2
                        x2=x2-2;
                        blue();
                        printf("Penalty point for Player2..\n");
                        reset(); 
                    }
                }
                else if(y2>26){
                    remain3= y2-26;
                    x2 = x2 + remain3;
                    if(x2==5 || x2==10){ //Penalty points for Player 2
                        x2=x2-2;
                        blue();
                        printf("Penalty point for Player2..\n");
                        reset(); 
                    } 
                    y2=26;
                }
            }
            if(check1==1){
                if(x2==11){
                    if(y2>3){
                        y2 = y2 - dice_player2;
                    }
                    if(y2<=3)check1=2;
                    if(y2==10 || y2==18) y2=y2-2;
                }
                if(x2>11){
                    remain4= x2-11;
                    y2 = y2-remain4;
                    x2=11;
                }     
            }
            if(check1==2){
                if(y2==3){
                    x2=x2-dice_player2;
                    if(x2<=3){
                        check1=0;
                        winner=2;
                    }
                } 
                if(y2<3){
                    remain5 = 3-y2;
                    x2 = x2-remain5;
                    y2=3;
                }
            }
            map[x2][y2] = '2';
            if(winner==2){
                printf("***PLAYER 2 WON THE GAME***\n");
                printMap(x1,y1,x2,y2);
                break;
            }//End of Player2's code section.
            //Beginning of Player1's code section.
            srand(time(NULL));
            dice_player1 = print_player1();
            if(check==0){
                if(y1==28){
                    x1 = x1 + dice_player1;
                    if(x1==7){
                        x1=x1-2;
                        yellow();
                        printf("Penalty point for Player1..\n");//Penalty point for Player 1
                        reset(); 
                    }
                    if(x1>=13) check=1;
                }
                if(y1<28){
                y1 = y1 + dice_player1;
                    if(y1==14){
                        y1=y1-2;
                        yellow();
                        printf("Penalty point for Player1..\n");//Penalty point for Player 1
                        reset(); 
                    } 
                }
                if(y1>28){
                    remain = y1-28;
                    x1 = x1 + remain;
                    y1 = 28;
                }
                
            }
            if(check==1){
                if(x1==13) {
                    y1 = y1-dice_player1;
                    if(y1==14){
                        y1 = y1+2;
                        yellow();
                        printf("Penalty point for Player1..\n");//Penalty point for Player 1
                        reset(); 
                    } 
                    if(y1<=1) check=2;
                }
                if(x1>13){
                    remain1 = x1-13;
                    y1 = y1 - remain1;
                    x1 = 13;
                }
            }
            if(check==2){
                if(y1==1){
                    x1 = x1 - dice_player1;
                    if(x1<=2){
                        check=0;
                        winner=1;
                    } 
                }
                if(y1<1){
                remain2 = 1-y1;
                x1 = x1 - remain2;
                y1=1;
                }
            }
            map [x1][y1] = '1';
            if(winner==1){
                printf("***PLAYER 1 WON THE GAME***\n");
                printMap(x1,y1,x2,y2);
                break;
            } //End of Player1's code section.
        }
        printMap(x1,y1,x2,y2); //Printing updated map.
    }
}
void printMap(int x1,int y1,int x2,int y2){
    for(int i=0;i<15;i++){
        for(int j=0;j<30;j++){
            if(i==0 || i==14) map[i][j] = '.';
            else if((i==12 || i==2) && j>1 && j<28) map[i][j] = '.'; 
            else if((i==10 || i==4) && j>3 && j<26) map[i][j] = '.';
            else if((j==29 || j==0) && i>0 && i<14) map[i][j] = ':';
            else if((j==2 || j==27) && i>2 && i<12) map[i][j] = ':';
            else if((j==4 || j==25) && i>4 && i<10) map[i][j] = ':';
            else if(i==1 && j==14 || i==7 && j==28 || i==13 && j==14) map[i][j] = 'X'; // 1st,2nd,3rd penalty points of Player 1
            else if(i==3 && j==10 || i==3 && j==18 || i==5 && j==26) map[i][j] = 'X'; // 1st,2nd,3rd penalty points of Player 2
            else if(i==10 && j==26 || i==11 && j==10 || i==11 && j==18) map[i][j] = 'X'; // 4th,5th,6th penalty points of Player 2
            else if(i==2 && j==1) map[i][j] = '_'; //Finish line for Player 1
            else if(i==4 && j==3) map[i][j] = '_'; //Finish line for Player 2
            else if(x1==i && y1==j);
            else if(x2==i && y2==j);
            else{
                map[i][j] = ' ';
            }
        }
    }      
    for(int i=0;i<15;i++){
        for(int j=0;j<30;j++){
            if(map[i][j] == 'X'){
                red(); //Set the text to the color red
                printf("%c ",map[i][j]);
                reset(); //Resets the text to default color
            }
            else if(map[i][j] == '_' ){
                green(); //Set the text to the color green
                printf("%c ",map[i][j]);
                reset(); //Resets the text to default color
            }
            else if(map[i][j] == '1' ){
                yellow(); //Set the text to the color yellow
                printf("%c ",map[i][j]);
                reset(); //Resets the text to default color
            }
            else if(map[i][j] == '2' ){
                blue(); //Set the text to the color blue
                printf("%c ",map[i][j]);
                reset(); //Resets the text to default color
            }
            else{
                    printf("%c ",map[i][j]);
            }
        }
        printf("\n");
    }
}
int dice(){
    int result;
    result = rand()%6+1;
    return result;
}
int print_player1(){
    char ch1;
    int dice_player1;
    yellow();
    printf("PLAYER1... PRESS Enter to dice\n");
    ch1=fgetc(stdin);
        if(ch1==0x0A){  //Checking the input if it is enter or not.
        dice_player1 = dice();
        printf("DICE: %d\n",dice_player1);
        reset();
        }
        else{
        printf("Please press enter!\n");
        }
        return dice_player1;
}
int print_player2(){
    char ch2;
    int dice_player2;
    blue();
    printf("PLAYER2... PRESS Enter to dice\n");
    ch2=fgetc(stdin);
        if(ch2==0x0A){   //Checking the input if it is enter or not.
        dice_player2 = dice();
        printf("DICE: %d\n",dice_player2);
        reset();
        }
        else{
        printf("Please press enter!\n");
        }
        return dice_player2;
}
int start_game(int dice1,int dice2){   //Printing the one who plays first.
    if(dice1>dice2)
    {
        printf("***PLAYER 1 will start the game...***\n");
        return 1;
    }
    else if(dice2>dice1){
        printf("***PLAYER 2 will start the game...***\n");
        return 2;
    }
    else{
        printf("Same dice value... Please try again.\n");
        return 0;
    }
}

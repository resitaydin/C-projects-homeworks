#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 20
#define MAX 15

void print_board(char board[][MAX]);
void fill_word(char board[][MAX],char words[6][MAX]);
int check_word(char board[][MAX],char word[6],int x,int y);

int main(){

    char board [MAX][MAX];
    char words [6][MAX];
    int x,y;
    char word[6];
    char str[6];
    int k=3;
    int points=0;
    int false=0;
    printf("Answer Key:\n");
    fill_word(board,words);
    for(int i=0;i<7;i++){
    printf("Word %d:%s \n",i+1,words[i]); // Answer key :)
    }
    do{
    if(k==1){   // For correct situations.
        points+=2;
        if(points==14){
            print_board(board);
            printf("You've found all of the words. You won! Your points: 14\n");
            return 0;
        } 
        printf("Founded! You got 2 points. Your total points: %d\n",points);
    }
    else if(k==0){   //For wrong situations.
            false++;
            if(false==1) printf("Wrong choice! You have only 2 lefts\n");
            else if(false==2) printf("“Wrong choice! You have only 1 left\n");
            else if(false==3){
                printf("You ran out of chances. Game is over! Your total points: %d\n",points);
                return 0;
            }
    }
    print_board(board);
    printf("Enter coordinates and word: ");
    scanf("%s",str);
    if(!strcmp(str,":q"))return 0; // If user enters :q we quit the program.
    x = atoi(str);
    scanf("%d",&y);  // y coordinate of point
    scanf("%s",word);  //Getting the word from the user
    k = check_word(board,word,x,y);
    }while(1);
}

void print_board(char board[][MAX]){
    for(int i=0;i<15;i++){  //Printing board function.
        for(int j=0;j<15;j++){
            if(board[i][j]=='X'){
                printf("\033[0;31m"); 
                printf("%c ",board[i][j]);  
                printf("\033[0m");
            }
            else
           printf("%c ",board[i][j]);
        }
        printf("\n");
    }
}
void fill_word(char board[][MAX],char words[6][MAX]){
    srand(time(NULL));
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            board[i][j] =' ';
        }
    }
    //1 for right,2 for left, 3 for up, 4 for down,5 for Southeast,6 for Northwest,7 for Northeast 8 for Southwest.
    //Random number generating...
  srand(time(NULL));
    FILE *fP;
    int temp[7];
    int check;
    for(int i=0;i<7;i++){   
        int random = rand()%50 + 1; // Generating random numbers to read from the file randomly.
        check=0;
        for(int j=0;j<i;++j){
            if(temp[j]==random){
                check=1;  // I ensured the words to be different from each other.
                break;
            }
        }
        if(check==0){
            temp[i]=random;
        }
        else {
            --i;
        }
    } //End of random number generating
    srand(time(NULL));
    int rand_x,rand_y,direction,size;
    int temp1,counter,temp2;
    for(int i=0;i<7;i++){ //Getting the words from the file.
        rand_x = rand()%15;   
        rand_y = rand()%15;  //Generating number x and y numbers.
        direction = rand()%8+1;  //Generating number direction between 1-8.
        fP=fopen("wordlist.txt","r");
        if(fP==NULL){
            printf("The file can't be read!\n");
            exit(1);
        }
        for(int j=0;j<temp[i];j++){
            fscanf(fP,"%s",words[i]);
        }
            size = strlen(words[i]);
        switch(direction){
                case 1: //Right case
                    temp1 = rand_y;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[rand_x][temp1]==' ')counter++;
                            temp1++;
                    }
            if(counter==size && size<=15-rand_y){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y); //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_y++;
                }
            }
            else --i; // This exists for going back to loop.
                break; //End of case 1(RIGHT)

                case 2: //Left Case
                    temp1 = rand_y;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[rand_x][temp1]==' ')counter++;
                            temp1--;
                    }
            if(counter==size && size<=rand_y){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y);  //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_y--;
                }
            }
            else --i;  // This exists for going back to loop.
                        break;//End of case 2(LEFT)

                case 3: //Up case
                    
                    temp2 = rand_x;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[temp2][rand_y]==' ')counter++;
                            temp2++;
                    }
            if(counter==size && size<=15-rand_x){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y);  //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_x++;
                }
            }
            else --i;  // This exists for going back to loop.
                        break; //End of case 3(UP)

                case 4: //Down Case 

                    temp2 = rand_x;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[temp2][rand_y]==' ')counter++;
                            temp2--;
                    }
            if(counter==size && size<=rand_x){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y);  //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_x--;
                }
            }
            else --i;  // This exists for going back to loop.
                    break; //End of case 4(DOWN)

                case 5: //SE case
                    temp1 = rand_y;
                    temp2 = rand_x;
                    counter=0;
                    for(int i=0;i<size;i++){ 
                        if(board[temp2][temp1]==' ')counter++;
                            temp2++;
                            temp1++;
                    }
            if(counter==size && size<=15-rand_x && size<=15-rand_y){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y);   //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_x++;
                        rand_y++;
                }
            }
            else --i;  // This exists for going back to loop.
                    break;//End of case 5 (SE)

                case 6: // NW case
                    temp1 = rand_y;
                    temp2 = rand_x;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[temp2][temp1]==' ')counter++;
                            temp2--;
                            temp1--;
                    }
            if(counter==size && size<=rand_x && size<=rand_y){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y);  //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_x--;
                        rand_y--;
                }
            }
            else --i;  // This exists for going back to loop.
                    break; //End of case 6(NW)

                case 7: //NE case
                    temp1 = rand_y;
                    temp2 = rand_x;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[temp2][temp1]==' ')counter++;
                            temp2--;
                            temp1++;
                    }
            if(counter==size && size<=rand_x && size<=15-rand_y){ // Checking for printing correctly.
            printf("Location: %d %d\n",rand_x,rand_y);   //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_x--;
                        rand_y++;
                }
            }
            else --i;  // This exists for going back to loop.
                    break; //End of case 7(NE)
            
            case 8: //SW case
                    temp1 = rand_y;
                    temp2 = rand_x;
                    counter=0;
                    for(int i=0;i<size;i++){
                        if(board[temp2][temp1]==' ')counter++;
                            temp2++;
                            temp1--;
                    }
            if(counter==size && size<=15-rand_x && size<=rand_y){ // Checking for printing correctly.
                printf("Location: %d %d\n",rand_x,rand_y);   //**ANSWER KEY**
                for(int j=0;j<size;j++){
                    board[rand_x][rand_y] = words[i][j];
                        rand_x++;
                        rand_y--;
                }
            }
            else --i;   // This exists for going back to loop.
                    break; //End of case 8(SW)

                default:
                        break; 
        }
        
        fclose(fP);
    } //End of getting words section.
    srand(time(NULL));
    for(int i=0;i<15;i++){
        for(int j=0;j<15;j++){
            if(board[i][j] ==' ')
            board[i][j] = rand()%26+97;
        }
    }
}//END OF FUNCTION 
int check_word(char board[][MAX],char word[6],int x,int y){
    int size=strlen(word);
    int counter1=0,counter2=0,counter3=0,counter4=0;
    int counter5=0,counter6=0,counter7=0,counter8=0;
    int arr[MAX];
for(int i=1;i<size;i++){
    word[0] = board[x][y];
    if(word[i]==board[x][y+i]){
        counter1++;
        if(counter1==size-1){ // Condition for direction 1
            for(int i=0;i<size;i++) board[x][y+i]='X';
        }
    } 
    if(word[i]==board[x][y-i]){ // Condition for direction 2
        counter2++;
        if(counter2==size-1){
            for(int i=0;i<size;i++) board[x][y-i]='X';
        }
    } 
    if(word[i]==board[x+i][y]){ // Condition for direction 3
        counter3++;
        if(counter3==size-1){
            for(int i=0;i<size;i++) board[x+i][y]='X';
        }
    } 
    if(word[i]==board[x-i][y]){ // Condition for direction 4
        counter4++;
        if(counter4==size-1){
            for(int i=0;i<size;i++) board[x-i][y]='X';
        }
    }  
    if(word[i]==board[x-i][y-i]){ // Condition for direction 5
        counter5++;
        if(counter5==size-1){
            for(int i=0;i<size;i++) board[x-i][y-i]='X';
        }
    } 
    if(word[i]==board[x+i][y+i]){ // Condition for direction 6
        counter6++;
        if(counter6==size-1){
            for(int i=0;i<size;i++) board[x+i][y+i]='X';
        }
    } 
    if(word[i]==board[x-i][y+i]){ // Condition for direction 7
        counter7++;
        if(counter7==size-1){
            for(int i=0;i<size;i++) board[x-i][y+i]='X';
        }
    } 
    if(word[i]==board[x+i][y-i]){  // Condition for direction 8
        counter8++;
        if(counter8==size-1){
            for(int i=0;i<size;i++) board[x+i][y-i]='X';
        }
    }
}
    if(counter1==(size-1)||counter2==(size-1)||counter3==(size-1)||counter4==(size-1)||
    counter5==(size-1)||counter6==(size-1)||counter7==(size-1)||counter8==(size-1)){
        return 1; //Returning 1 for correct situations.
    }
    else return 0; //Returning 0 for wrong situations.
}//END OF CHECK_WORD FUNCTION


    
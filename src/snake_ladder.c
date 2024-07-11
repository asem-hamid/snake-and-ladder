# include <stdio.h>
# include <stdlib.h> // for dice  roll , for exit(0)
# include <time.h>

// To roll the Dice
int diceroll();  

// Player start dice
void startroll1();
int start_dice_rollp1 ; // before getting 1st 1
void startroll2(); 
int start_dice_rollp2 ; // before getting 1st 1

    

// Starting dice check
void startp1();  // before getting 1st 1
void startp2();  // before getting 1st 1



// Actuall game
void gamep1();  // after getting 1st 1
void gamep2();  // after getting 1st 1

int player_1_dice ; // after getting 1st 1  // use as a global variable to save memory on  stack level
int player_2_dice ; // after getting 1st 1  // use as a global variable to save memory on  stack level



int player_1_cell ; // current cell after roll
int player_2_cell ; // current cell after roll


int cellcheck(int *player_cell, int player_dice, int player_number); // current cell after roll
 


void snake (int *player_cell);
void ladder (int *player_cell);



void reminder (int player_cell);



void board( );

#define ROW 10
#define COL 10



int main(){

    // Seed the random number generator with the current time
    srand(time(NULL));

    board(  );

    startroll1();

return 0;

}




int diceroll(){
    
    int dice_roll;

    // Generate a random number between 1 and 6
    dice_roll = (rand() % 6) + 1;

    return dice_roll;

}


void startroll1(){
    
    int startrollp1;
    printf("Player 1, to roll your dice, enter 1: ");

    while (scanf("%d", &startrollp1) != 1 || startrollp1 != 1) {

        printf("Invalid input. Player 1, you have to enter 1 to roll your dice: ");
        while (getchar() != '\n'); // Clear input buffer

    }

    startp1();

}



void startp1(){

    start_dice_rollp1 = diceroll();
    printf("Player 1 your dice is %d\n\n",start_dice_rollp1);

    if (start_dice_rollp1 == 1){

        printf("Player 1 , you can now start your game !\n");
        gamep1() ;

    }
    else{

       if(start_dice_rollp2 == 1){

          gamep2();

       }
       else{
                        
          startroll2();

       }       

    }

}



void startroll2(){
    
    int startrollp2;
    printf("Player 2, to roll your dice, enter 9: ");

    while (scanf("%d", &startrollp2) != 1 || startrollp2 != 9) {

        printf("Invalid input. Player 2, you have to enter 9 to roll your dice: ");
        while (getchar() != '\n'); // Clear input buffer

    }

    startp2();

}

 

void startp2(){

    start_dice_rollp2 = diceroll();
    printf("Player 2 your dice is %d\n\n",start_dice_rollp2);

    if (start_dice_rollp2 == 1){

        printf("Player 2 , you can now start your game !\n");
        gamep2() ;

    }
    else{

       if(start_dice_rollp1 == 1){

        gamep1();

       }
       else{
                        
        startroll1();
        
       }

    }

}





void gamep1(){
    
    int rollp1;
    printf("Player 1 to roll you dice enter 1.\n Player 1 : ");

    while (scanf("%d", &rollp1) != 1 || rollp1 != 1) {

        printf("Invalid input. Player 1, you have to enter 1 to roll your dice: ");
        while (getchar() != '\n'); // Clear input buffer

    }

    player_1_dice = diceroll();
    printf("Player 1 your dice is %d\n",player_1_dice);
    printf("You are in cell no %d \n\n", cellcheck (&player_1_cell , player_1_dice, 1) );
    reminder (player_1_cell);
    board(  );

    if(start_dice_rollp2 == 1){

      gamep2();

    }
    else{

       startroll2();

    }

}


void gamep2(){
    
    int rollp2;
    printf("Player 2 to roll you dice enter 9.\n Player 2 : ");

    while (scanf("%d", &rollp2) != 1 || rollp2 != 9) {

        printf("Invalid input. Player 2, you have to enter 9 to roll your dice: ");
        while (getchar() != '\n'); // Clear input buffer

    }
       
    player_2_dice = diceroll();
    printf("Player 2 your dice is %d\n",player_2_dice);
    printf("You are in cell no %d \n\n", cellcheck (&player_2_cell , player_2_dice, 2) );
    reminder (player_2_cell);
    board(  );

    if(start_dice_rollp1 == 1){

      gamep1();

    }
    else{

       startroll1();

    }

}




int cellcheck(int *player_cell, int player_dice, int player_number) {

    *player_cell += player_dice;


    if (*player_cell == 100) {

        printf("Player %d wins the game\n", player_number);

        exit(0);
    } 
    else if (*player_cell > 100) {

        printf("You can't go beyond 100\n");

        *player_cell -= player_dice;

        return *player_cell;
    } 
    else if (*player_cell == 18 || *player_cell == 30 || *player_cell == 49 || 
             *player_cell == 77 || *player_cell == 92 || *player_cell == 99) {

        printf("Oh no, player %d, you got bitten by a snake!\n", player_number);

        snake(player_cell); // here player_cell is a pointer we don't have to add &player_cell

        return *player_cell;
    } 
    else if (*player_cell == 19 || *player_cell == 26 || *player_cell == 40 || 
             *player_cell == 46 || *player_cell == 65) {

        printf("Wow, player %d, you got a ladder!\n", player_number);

        ladder(player_cell); // here player_cell is a pointer we don't have to add &player_cell

        return *player_cell;
    } 
    else {

        return *player_cell;
    }
}




void snake(int *player_cell) {
    switch (*player_cell) {
        case 18: *player_cell =  6; break;
        case 30: *player_cell =  9; break;
        case 49: *player_cell = 26; break;
        case 77: *player_cell = 60; break;
        case 92: *player_cell = 71; break;
        case 99: *player_cell = 75; break;
        default: break;
    }
}


void ladder(int *player_cell) {
    switch (*player_cell) {
        case 19: *player_cell = 36; break;
        case 26: *player_cell = 67; break;
        case 40: *player_cell = 62; break;
        case 46: *player_cell = 69; break;
        case 65: *player_cell = 83; break;
        default: break;
    }
}



void reminder (int player_cell){


    if (player_cell == 12)
        printf("Remember, there is a snake at cell no 18\n\n");
    else if (player_cell >= 13 && player_cell <= 17)
        printf("Remember, there is a snake at cell no 18 and a ladder at cell no 19\n\n");
    else if (player_cell == 18)
        printf("Remember, there is a ladder at cell no 19\n\n");
    else if (player_cell >= 20 && player_cell <= 23)
        printf("Remember, there is a ladder at cell no 26\n\n");
    else if (player_cell >= 24 && player_cell <= 25)
        printf("Remember, there is a snake at cell no 30 and a ladder at cell no 26\n\n");
    else if (player_cell >= 26 && player_cell <= 29)
        printf("Remember, there is a snake at cell no 30\n\n");
    else if (player_cell >= 34 && player_cell <= 39)
        printf("Remember, there is a ladder at cell no 40\n\n");
    else if (player_cell >= 40 && player_cell <= 42)
        printf("Remember, there is a ladder at cell no 46\n\n");
    else if (player_cell >= 43 && player_cell <= 45)
        printf("Remember, there is a snake at cell no 49 and a ladder at cell no 46\n\n");
    else if (player_cell >= 46 && player_cell <= 48)
        printf("Remember, there is a snake at cell no 49\n\n");
    else if (player_cell >= 59 && player_cell <= 64)
        printf("Remember, there is a ladder at cell no 65\n\n");
    else if (player_cell >= 71 && player_cell <= 76)
        printf("Remember, there is a snake at cell no 77\n\n");
    else if (player_cell >= 86 && player_cell <= 91)
        printf("Remember, there is a snake at cell no 92\n\n");
    else if (player_cell >= 93 && player_cell <= 98)
        printf("Remember, there is a snake at cell no 99\n\n");


}





void board( ){

    int board[ROW][COL] = {
        {100, 99, 98, 97, 96, 95, 94, 93, 92, 91},
        {81, 82, 83, 84, 85, 86, 87, 88, 89, 90},
        {80, 79, 78, 77, 76, 75, 74, 73, 72, 71},
        {61, 62, 63, 64, 65, 66, 67, 68, 69, 70},
        {60, 59, 58, 57, 56, 55, 54, 53, 52, 51},
        {41, 42, 43, 44, 45, 46, 47, 48, 49, 50},
        {40, 39, 38, 37, 36, 35, 34, 33, 32, 31},
        {21, 22, 23, 24, 25, 26, 27, 28, 29, 30},
        {20, 19, 18, 17, 16, 15, 14, 13, 12, 11},
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

    };

    int found = 0; 


    // mark current cell of players
    for(int i = 0;i < ROW;i++ ){

        for(int j = 0;j < COL;j++){

            if(board[i][j] == player_1_cell && board[i][j] == player_2_cell ){   // if both player land on same cell 

                board[i][j] = -3 ;  // marking the cell index 

                found = 2;
                break;    // break the current col loop
            }
            else if(board[i][j] == player_1_cell ){

                board[i][j] = -1 ;  // marking the cell index 
                
                found++;
                if (found == 2) {   
                    break; // break the current col loop
                }

            }
            else if (board[i][j] == player_2_cell ){

                board[i][j] = -2 ;  // marking the cell index 

                found++;
                if (found == 2) {  
                    break; // break the current col loop
                }

            }
        }
        

        if (found == 2) {  // break the row loop
            break;
        } 

    }


    // Printing the current board
    printf("\t\tCurrent Board\n");

    for(int i = 0;i < ROW;i++ ){

        for(int j = 0;j < COL;j++){


            if(board[i][j] == -1){

                printf("%4s", "P1");
                
            }
            else if(board[i][j] == -2){

                printf("%4s", "P2");

            }
            else if(board[i][j] == -3){

                printf("%6s", "Both");

            }
            else{

                printf("%4d", board[i][j]);

            }

        }

        printf("\n");

    }

    printf("\n");

}


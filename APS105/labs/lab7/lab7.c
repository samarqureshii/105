//
// Author: Samar Qureshi
//

//#include "reversi.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char ItoC(int i){ //converting from int to char
    return i + 97;
}

int CtoI(char ch){ //converting from char to int
    return ch - 97;
}

bool isValidCoord(char str[3], int n){ //checks if letter coordinates are valid on our grid
//    printf("coord one in decimal %d \n",CtoI(str[1]));
//    printf("coord two in decimal %d \n",CtoI(str[2]));
    if(CtoI(str[1]) >= 0 && CtoI(str[1]) < n && CtoI(str[2]) >= 0 && CtoI(str[2]) < n){
        if(str[0] == 'B' || str[0] == 'W'){
            return true;
        }
    }
    return false;
}

void printBoard(char board[][26], int n) {
    printf("  "); //board position at [0][0]
    
    for(int i = 0; i < n; i++){
        printf("%c", ItoC(i)); //printing the first row of the alphabetical coordinates
    }
    
    for(int i = 0; i < n; i++){
        printf("\n%c ", ItoC(i)); //printing the first "column" of the alphabetical coordinates
        for(int ii = 0; ii < n; ii++){
            printf("%c", board[i][ii]); //printing out the actual board
        }
        
    }
    
    printf("\n");
}

void initialize(char board[][26], int n){ //create empty board and assign config
    for (int i = 0; i < n; i++) {
        for (int ii = 0; ii < n; ii++) {
            board[i][ii] = 'U';
        }
    }
    
    board[n/2][n/2] = 'W';
    board[n/2 - 1][n/2 - 1] = 'W';
    board[n/2 - 1][n/2] = 'B';
    board[n/2][n/2 - 1] = 'B';
    
    
    printBoard(board, n);
    
}

void config(char board[][26], int n){ // board config
    char st[3] = {'0','0','0'}; //input string
    printf("Enter board configuration:\n");
    
    do{
        scanf("%s", st);
        
        if(st[0] == '!' || !isValidCoord(st, n)){
            break;
        }
        
        board[CtoI(st[1])][CtoI(st[2])] = st[0]; //keep assigning colour to coordinate
        
    }while(st[0] != '!' && isValidCoord(st, n));
        
}

bool positionInBounds(int n, int row, int col) { //check if position is valid
    if(row < n && row >= 0 ){
        if(col < n && col >= 0){
            return true;
        }
    }
    
    return false;
}

bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) { //checks for legality by going through position
    //go to the next position
    row+=deltaRow;
    col+=deltaCol;
    
    //if newly incremented position is legal
    if(positionInBounds(n, row, col)){
        if(board[row][col] != colour && board[row][col] != 'U'){
            
            while(positionInBounds(n, row, col)){
                row+=deltaRow;
                col+=deltaCol;
                
                if(positionInBounds(n, row, col) && board[row][col] == colour){
                    return true;
                }
                
                else if(board[row][col] == 'U'){
                    return false;
                }
                
                if(!positionInBounds(n,row,col)){
                    break;
                }
                
            }
            
        }
    }
    
    return false;
}

void flip(char board[][26], char st[3], int n){ //flipping the pieces
    const int directions[8][2]={{-1,-1},
                                {-1, 0},
                                {-1, 1},
                                {0, -1},
                                {0, 1},
                                {1, -1},
                                {1, 0},
                                {1, 1}}; //all if the 8 directions
    
    board[CtoI(st[1])][CtoI(st[2])] = st[0]; //changing the colour at initial row and col
    
    for(int d = 0; d < n; d++){ //changing colour at all row and col in legal/possible direction
        
        if(checkLegalInDirection(board, n, CtoI(st[1]), CtoI(st[2]), st[0], directions[d][0], directions[d][1])){
            int row = CtoI(st[1]) + directions[d][0];
            int col = CtoI(st[2]) + directions[d][1];
            
            while(positionInBounds(n, row, col) && board[row][col] != st[0]){
                board[row][col] = st[0]; //changing the colour of every tile in that row
                
                row+=directions[d][0];
                col+=directions[d][1];
                
            }
            
        }
        
    }
    
}

void showMoves(char board[][26], int n, char colour){ //show all possible player positions
    const int directions[8][2]={{-1,-1},
                                {-1, 0},
                                {-1, 1},
                                {0, -1},
                                {0, 1},
                                {1, -1},
                                {1, 0},
                                {1, 1}}; //all if the 8 directions
    
    //st[0] = colour
    //st[1] = row
    //st[2] = col
    
    printf("Available moves for %c:\n", colour); //do this for black and white because racism is bad
    
    //for every position
    for(int row = 0; row < n; row ++){
        for(int col = 0; col < n; col ++){
        
            for(int d = 0; d < 8; d++){ //iterate through every possible direction pair
                //showing everywhere we can make a valid move
                if(checkLegalInDirection(board, n, row, col, colour, directions[d][0], directions[d][1]) && board[row][col] == 'U'){
                    printf("%c%c\n", ItoC(row), ItoC(col));
                    break;
                }
            }
            
        }
    }
    
}

void makeMove(char board[][26], int n){ //user makes a move
    bool flag = false;
    const int directions[8][2]={{-1,-1},
                                {-1, 0},
                                {-1, 1},
                                {0, -1},
                                {0, 1},
                                {1, -1},
                                {1, 0},
                                {1, 1}}; //all if the 8 directions
    
    char st[3];
    //st[0] = colour
    //st[1] = row
    //st[2] = col
    printf("Enter a move:\n");
    scanf("%s", st);
    
    //printf("about to enter the fors\n");

    for(int row = 0; row < n; row ++){
//        printf("inside the first for \n");

        for(int col = 0; col < n; col ++){
            //printf("inside the second for \n");

            for(int d = 0; d < 8; d++){ //iterate through every possible direction pair
                //if chosen move is undefined and the direction is legal
                //printf("inside the third for \n");
                if(checkLegalInDirection(board, n, CtoI(st[1]), CtoI(st[2]), st[0], directions[d][0], directions[d][1])){
                    if(board[CtoI(st[1])][CtoI(st[2])] == 'U' && isValidCoord(st, n)){
                        printf("Valid move.\n");
                            
                        flip(board, st, n);
                            
                        printBoard(board, n);
                        flag = true;
                        
                    }
                }
            }
            
        }
    }
    
    if(!flag){
        printf("Invalid move.\n");
        printBoard(board, n);
    }
    

}



int main(void) {
    
    //step 1, initializing the board
    int n; //board dimension
        
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    
    char board[26][26];
    initialize(board, n);
    
    //step 2, describe board config
    config(board, n);
    printBoard(board,n); //print new board
    
    //step 3, print list of available moves for White and Black player (possible positions)
    showMoves(board, n, 'W'); //show all moves for white
    showMoves(board, n, 'B'); //show all moves for black
    
    //step 4, ask user to input a move, check for validity
    makeMove(board, n);
    
    //step 5, print final board config then terminate
//    printBoard(board,*n);

  return 0;
    
}

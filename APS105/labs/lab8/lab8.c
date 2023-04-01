/**
* @file reversi.c
* @author Samar
* @brief This file is used for APS105 Lab 8. 2023W version
* @date 2023-03-14
*
*/

#if !defined(TESTER_P1) && !defined(TESTER_P2)
#include "reversi.h"
#endif


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

void flip(char board[][26], int n, int row, int col, char colour){ //flipping the pieces
    const int directions[8][2]={{-1,-1},
                                {-1, 0},
                                {-1, 1},
                                {0, -1},
                                {0, 1},
                                {1, -1},
                                {1, 0},
                                {1, 1}}; //all if the 8 directions
    
    board[row][col] = colour; //changing the colour at initial row and col
    
    for(int d = 0; d < n; d++){ //changing colour at all row and col in legal/possible direction
        
        if(checkLegalInDirection(board, n, row, col, colour, directions[d][0], directions[d][1])){
            int r = row + directions[d][0];
            int c = col + directions[d][1];
            
            while(positionInBounds(n, row, col) && board[row][col] != colour){
                board[r][c] = colour; //changing the colour of every tile in that row
                
                r+=directions[d][0];
                c+=directions[d][1];
                
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

bool validMoveCheck(char board[][26], int n, int row, int col, char colour, int i){ //user enters a move to check the validity
    //bool flag = false;
    const int directions[8][2]={{-1,-1},
                                {-1, 0},
                                {-1, 1},
                                {0, -1},
                                {0, 1},
                                {1, -1},
                                {1, 0},
                                {1, 1}}; //all if the 8 directions
    

    for(int d = 0; d < 8; d++){ //iterate through every possible direction pair
        if(checkLegalInDirection(board, n, row, col, colour, directions[d][0], directions[d][1])){
            flip(board, n, row, col, colour);
            if(i == 0){
                printBoard(board, n);
            }
            
            return true;
        }
    }
    
    if(i == 0){
        return false;
    }
    return false;

}


int makeMove(char board[26][26], int n, char turn, int *row, int *col) { //for the user to make a move
    const int directions[8][2]={{-1,-1},
                                {-1, 0},
                                {-1, 1},
                                {0, -1},
                                {0, 1},
                                {1, -1},
                                {1, 0},
                                {1, 1}}; //all of the 8 directions
    
    int score[1] = {0}; //find and return move that gives highest score
    int flips[1] = {0}; //count the number of potential flips for one move then compare to score
    

    for(int i = 0; i< n; i++){ //iterate through every row and column on the board
        for(int j = 0; j< n; j++){
            for(int k = 0; k < 8 && board[i][j] == 'U' ; k++){ //check for empty space on the board
                
                //potential row and col moves for the board, but will not modify actual *row and *col
                int r = i;
                int c = j;
                
                //temporary row and col
                r+=directions[k][0];
                c+=directions[k][1];
                
                //if newly incremented position is legal
                if(positionInBounds(n, r, c)){
                    if(board[r][c] != turn && board[r][c] != 'U'){
                        (flips[0])++;
                        
                        while(positionInBounds(n, r, c)){
                            r+=directions[k][0];
                            c+=directions[k][1];
                            
                            if(positionInBounds(n, r, c) && board[r][c] == turn){
                                break;
                            }
                            
                            else if(board[r][c] == 'U'){
                                break;
                            }
                            
                            if(!positionInBounds(n,r,c)){
                                break;
                            }
                            (flips[0])++;
                        }
                        
                    }
                }
                
                
                //does this move give us the highest score?
                if(flips[0] > score[0]){
                    score[0] = flips[0];
                    *row = i;
                    *col = j;
                }
                
                flips[0] = 0; //reset
            }
        }
    }
    
    return *score;
}

#ifndef TESTER_P2

int main(void) {
    //step 1, initializing the board
    int n; //board dimension
    int row = 0, col = 0; //current row and col
    char cmpt, user; //colour the computer and user are playing
    char board[26][26];
    int turn; //to keep track of which player is moving
    bool userFlag = true, cmptFlag = true;
    char coord [3]; //coordinate to move to
        
    printf("Enter the board dimension: ");
    scanf("%d", &n);
    
    printf("Computer plays (B/W): "); //what colour will the computer play?
    scanf(" %c", &cmpt);
    
    //deciding which player goes first, black always goes first
    if(cmpt == 'W'){
        user = 'B';
        turn = 0; //user goes first
    }else{
        user = 'W';
        turn = 1; //computer goes first
    }
    
    initialize(board, n); //print out initial board
    
    
    //switching between players
    while(cmptFlag || userFlag){ //while either the computer or user can make a move
        
        if(turn % 2 ==0){ //user can make a move
            if(makeMove(board, n, user, &row, &col) > 0){
                printf("Enter move for colour %c (RowCol):", user);
                scanf("%s", coord);
                
                userFlag = true;
                
                if(!validMoveCheck(board, n, CtoI(coord[0]), CtoI(coord[1]), user, 0)){
                    break;
                }
                
                else if(board[CtoI(coord[0])][CtoI(coord[1])] != 'U'){
                    break;
                }
            }
            
            else{ //if user cannot make a move
                if(userFlag){
                    if(makeMove(board, n, cmpt, &row, &col) > 0 && cmptFlag){ //check that the computer can still move
                        printf("%c has no valid move.\n", user);
                    }
                    
                    userFlag = false;
                }
            }
            

        }
        
        else if(turn % 2 == 1 && (makeMove(board, n, cmpt, &row, &col) > 0 || cmptFlag)){ //computer makes a move
            if(makeMove(board, n, cmpt, &row, &col) > 0){
                validMoveCheck(board, n, row, col, cmpt, 1);
                cmptFlag = true;
                
                printf("Computer places %c at %c%c.\n", cmpt, ItoC(row), ItoC(col));
                printBoard(board,n); //try to move this into validMoveCheck
            }
            
            else{ //cmptFlag = true
                if(cmptFlag){
                    if(userFlag && makeMove(board, n, user, &row, &col) > 0){
                        printf("%c player has no valid move.\n", cmpt);
                    }
                    
                    cmptFlag = false;
                }
                
            }

        }
        
        turn++; //to keep track of turns
    
    } //end of big while
    
    //ending to the game
    int B = 0, W = 0; //counting score for each player
    
    if(!cmptFlag && !userFlag){ //if game ends by none of the players being able to move
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'B'){
                    B++;
                }
                
                else if(board[i][j] == 'W'){
                    W++;
                }
                
                
            }
        }
        
        
    }
    
    else{ //if game ends by invalid move
        printf("Invalid move.\n");
        printf("%c player wins.", cmpt);
    }
    
    
    return 0;

}
#endif

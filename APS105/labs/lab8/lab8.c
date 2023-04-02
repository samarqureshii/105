///**
//* @file reversi.c
//* @author Samar
//* @brief This file is used for APS105 Lab 8. 2023W version
//* @date 2023-03-14
//*
//*/
//
//#if !defined(TESTER_P1) && !defined(TESTER_P2)
//#include "reversi.h"
//#endif
//
//
//#include <stdbool.h>
//#include <stdio.h>
//#include <stdlib.h>
//
//char ItoC(int i){ //converting from int to char
//    return i + 97;
//}
//
//int CtoI(char ch){ //converting from char to int
//    return ch - 97;
//}
//
//bool isValidCoord(char str[3], int n){ //checks if letter coordinates are valid on our grid
////    printf("coord one in decimal %d \n",CtoI(str[1]));
////    printf("coord two in decimal %d \n",CtoI(str[2]));
//    if(CtoI(str[1]) >= 0 && CtoI(str[1]) < n && CtoI(str[2]) >= 0 && CtoI(str[2]) < n){
//        if(str[0] == 'B' || str[0] == 'W'){
//            return true;
//        }
//    }
//    return false;
//}
//
//void printBoard(char board[][26], int n) {
//    printf("  "); //board position at [0][0]
//
//    for(int i = 0; i < n; i++){
//        printf("%c", ItoC(i)); //printing the first row of the alphabetical coordinates
//    }
//
//    for(int i = 0; i < n; i++){
//        printf("\n%c ", ItoC(i)); //printing the first "column" of the alphabetical coordinates
//        for(int ii = 0; ii < n; ii++){
//            printf("%c", board[i][ii]); //printing out the actual board
//        }
//
//    }
//
//    printf("\n");
//}
//
//void initialize(char board[][26], int n){ //create empty board and assign config
//    for (int i = 0; i < n; i++) {
//        for (int ii = 0; ii < n; ii++) {
//            board[i][ii] = 'U';
//        }
//    }
//
//    board[n/2][n/2] = 'W';
//    board[n/2 - 1][n/2 - 1] = 'W';
//    board[n/2 - 1][n/2] = 'B';
//    board[n/2][n/2 - 1] = 'B';
//
//
//    printBoard(board, n);
//
//}
//
//void config(char board[][26], int n){ // board config
//    char st[3] = {'0','0','0'}; //input string
//    printf("Enter board configuration:\n");
//
//    do{
//        scanf("%s", st);
//
//        if(st[0] == '!' || !isValidCoord(st, n)){
//            break;
//        }
//
//        board[CtoI(st[1])][CtoI(st[2])] = st[0]; //keep assigning colour to coordinate
//
//    }while(st[0] != '!' && isValidCoord(st, n));
//
//}
//
//bool positionInBounds(int n, int row, int col) { //check if position is valid
//    if(row < n && row >= 0 ){
//        if(col < n && col >= 0){
//            return true;
//        }
//    }
//
//    return false;
//}
//
//
//bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol) { //checks for legality by going through position
//    //go to the next position
//    row+=deltaRow;
//    col+=deltaCol;
//
//    //if newly incremented position is legal
//    if(positionInBounds(n, row, col)){
//        if(board[row][col] != colour && board[row][col] != 'U'){
//
//            while(positionInBounds(n, row, col)){
//                row+=deltaRow;
//                col+=deltaCol;
//
//                if(positionInBounds(n, row, col) && board[row][col] == colour){
//                    return true;
//                }
//
//                else if(board[row][col] == 'U'){
//                    return false;
//                }
//
//                if(!positionInBounds(n,row,col)){
//                    break;
//                }
//
//            }
//
//        }
//    }
//
//    return false;
//}
//
//void flip(char board[][26], int n, int row, int col, char colour){ //flipping the pieces
//    const int directions[8][2]={{-1,-1},
//                                {-1, 0},
//                                {-1, 1},
//                                {0, -1},
//                                {0, 1},
//                                {1, -1},
//                                {1, 0},
//                                {1, 1}}; //all if the 8 directions
//
//    board[row][col] = colour; //changing the colour at initial row and col
//
//    for(int d = 0; d < 8; d++){ //changing colour at all row and col in legal/possible direction
//
//        if(checkLegalInDirection(board, n, row, col, colour, directions[d][0], directions[d][1])){
//            int r = row + directions[d][0];
//            int c = col + directions[d][1];
//
//            while(board[r][c] != colour){
//                board[r][c] = colour;
//                r+=directions[d][0];
//                c+=directions[d][1];
//            }
//
//        }
//
//    }
//
//}
//
//void showMoves(char board[][26], int n, char colour){ //show all possible player positions
//    const int directions[8][2]={{-1,-1},
//                                {-1, 0},
//                                {-1, 1},
//                                {0, -1},
//                                {0, 1},
//                                {1, -1},
//                                {1, 0},
//                                {1, 1}}; //all if the 8 directions
//
//    //st[0] = colour
//    //st[1] = row
//    //st[2] = col
//
//    printf("Available moves for %c:\n", colour); //do this for black and white because racism is bad
//
//    //for every position
//    for(int row = 0; row < n; row ++){
//        for(int col = 0; col < n; col ++){
//
//            for(int d = 0; d < 8; d++){ //iterate through every possible direction pair
//                //showing everywhere we can make a valid move
//                if(checkLegalInDirection(board, n, row, col, colour, directions[d][0], directions[d][1]) && board[row][col] == 'U'){
//                    printf("%c%c\n", ItoC(row), ItoC(col));
//                    break;
//                }
//            }
//
//        }
//    }
//
//}
//
//bool checkAndFlip(char board[][26], int n, int row, int col, char colour, int i){ //user enters a move to check the validity
//    //bool flag = false;
//    const int directions[8][2]={{-1,-1},
//                                {-1, 0},
//                                {-1, 1},
//                                {0, -1},
//                                {0, 1},
//                                {1, -1},
//                                {1, 0},
//                                {1, 1}}; //all if the 8 directions
//
//
//    for(int d = 0; d < 8; d++){ //iterate through every possible direction pair
//        if(checkLegalInDirection(board, n, row, col, colour, directions[d][0], directions[d][1])){
//
//            flip(board, n, row, col, colour);
//
//            if(i == 0){
//                printBoard(board, n);
//            }
//
//            return true;
//        }
//    }
//
//    if(i == 0){
//        return false;
//    }
//    return false;
//
//}
//
//int currentScore(char board[26][26], int n, char turn){ //return current score of whatever colour
//    int s = 0;
//
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//
//        }
//    }
//
//    return s;
//}
//
//
//int makeMove(char board[26][26], int n, char turn, int *row, int *col) {
//    int maxScore = 0;
//    int currentScore = 0;
//    const int directions[8][2]={{-1,-1},
//                                {-1, 0},
//                                {-1, 1},
//                                {0, -1},
//                                {0, 1},
//                                {1, -1},
//                                {1, 0},
//                                {1, 1}};
//
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) {
//            if(board[i][j] == 'U') { //check for empty space on the board
//                currentScore = 0;
//                for(int k = 0; k < 8; k++) { //check for all directions
//                    int r = i + directions[k][0];
//                    int c = j + directions[k][1];
//                    int flips = 0;
//                    bool valid = false;
//
//                    while(positionInBounds(n, r, c) && board[r][c] != 'U' && board[r][c] != turn) {
//                        flips++;
//                        r += directions[k][0];
//                        c += directions[k][1];
//
//                        if(positionInBounds(n, r, c) && board[r][c] == turn) {
//                            valid = true;
//                            break;
//                        }
//                    }
//
//                    if(valid) {
//                        currentScore += flips;
//                    }
//                }
//
//                if(currentScore > maxScore) {
//                    maxScore = currentScore;
//                    *row = i;
//                    *col = j;
//                }
//            }
//        }
//    }
//
//    return maxScore;
//}
//
//#ifndef TESTER_P2
//
//int main(void) {
//    //step 1, initializing the board
//    int n; //board dimension
//    int row = 0, col = 0; //current row and col
//    char cmpt, user; //colour the computer and user are playing
//    char board[26][26];
//    int turn; //to keep track of which player is moving
//    bool userFlag = true, cmptFlag = true;
//    char coord [3]; //coordinate to move to
//
//    printf("Enter the board dimension: ");
//    scanf("%d", &n);
//
//    printf("Computer plays (B/W): "); //what colour will the computer play?
//    scanf(" %c", &cmpt);
//
//    //deciding which player goes first, black always goes first
//    if(cmpt == 'W'){
//        user = 'B';
//        turn = 1; //user goes first
//    }else{
//        user = 'W';
//        turn = 0; //computer goes first
//    }
//
//    initialize(board, n); //print out initial board
//
//
//    //switching between players
//    while(cmptFlag || userFlag){ //while either the computer or user can make a move
//
//        if(turn % 2 == 1){ //user can make a move
//            if(makeMove(board, n, user, &row, &col) > 0){
//                printf("Enter move for colour %c (RowCol): ", user);
//                scanf(" %s", coord);
//
//                userFlag = true;
//
//                if(board[CtoI(coord[0])][CtoI(coord[1])] != 'U' ){
//                    break;
//                }
//
//                if(!checkAndFlip(board, n, CtoI(coord[0]), CtoI(coord[1]), user, 0)){
//                    break;
//                }
//            }
//
//            else{ //if user cannot make a move
//                if(userFlag){
//                    if(makeMove(board, n, cmpt, &row, &col) > 0 && cmptFlag){ //check that the computer can still move
//                        printf("%c has no valid move.\n", user);
//                    }
//
//                    userFlag = false;
//                }
//            }
//
//
//        }
//
//        else if(turn % 2 == 0){ //computer's move
//            if( (makeMove(board, n, cmpt, &row, &col) > 0 || cmptFlag)){ //computer makes a move
//                if(makeMove(board, n, cmpt, &row, &col) > 0){
//                    cmptFlag = true;
//                    checkAndFlip(board, n, row, col, cmpt, 1);
//
//                    printf("Computer places %c at %c%c.\n", cmpt, ItoC(row), ItoC(col));
//                    printBoard(board,n);
//                }
//
//                else{ //cmptFlag = true
//                    if(cmptFlag){
//                        if(userFlag && makeMove(board, n, user, &row, &col) > 0){
//                            printf("%c player has no valid move.\n", cmpt);
//                        }
//
//                        cmptFlag = false;
//                    }
//
//                }
//
//            }
//        }
//
//        turn++; //to keep track of turns
//
//    } //end of big while
//
//    //ending to the game
//    int B = 0, W = 0; //counting score for each player
//
//    if(!cmptFlag && !userFlag){ //if game ends by none of the players being able to move
//        for(int i = 0; i < n; i++){
//            for(int j = 0; j < n; j++){
//                if(board[i][j] == 'B'){
//                    B++;
//                }
//
//                else if(board[i][j] == 'W'){
//                    W++;
//                }
//
//
//            }
//        }
//
//        if(B>W){
//            printf("B player wins.");
//        }
//
//        else if(W>B){
//            printf("W player wins.");
//        }
//
//        else{
//            printf("Draw!");
//        }
//    }
//
//    else{ //if game ends by invalid move
//        printf("Invalid move.\n");
//        printf("%c player wins.", cmpt);
//    }
//
//
//    return 0;
//
//}
//#endif

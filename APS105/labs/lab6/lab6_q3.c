#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Part 3: 4 marks
// Using calculateScoreInDir, it checks for each row/col,
// if it sees a line of 1's resulting from that startRow and startCol
// that is equal to difficulty level! Amazing it should return gameOver
bool gameStatus(int Size, char userArray[][Size], int difficultyLevel);

// You need to have implemented to proceed! But on Examify, we will add ours
void printBoard(int Size, char grid[][Size]);
bool validRowCol(int row, int col, int Size);
void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);

int lab6_q3(void) {
  const int maxDim = 23;
  int Size = 0, difficultyLevel = 0;
  printf("Enter size and difficulty level: ");
  scanf("%d %d", &Size, &difficultyLevel);

  int copy[maxDim][maxDim] = {
      {1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1},
      {1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1},
      {0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0},
      {1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
      {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0},
      {1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
      {1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1},
      {1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1},
      {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0},
      {1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
      {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1},
      {1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1},
      {0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1},
      {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0},
      {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1},
      {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0},
      {1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1},
      {1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1}};

  char grid[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      grid[row][col] = copy[row][col] + '0';
    }
  }

  int userInputRow = 0, userInputCol = 0;

  // test gameStatus
  char userArray[Size][Size];
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      userArray[row][col] = '-';
    }
  }
  bool gameOver = true;
  int steps = 0;
  do {
    printf("Enter row and col: ");
    scanf("%d %d", &userInputRow, &userInputCol);

    userArray[userInputRow][userInputCol] = grid[userInputRow][userInputCol];
    printBoard(Size, userArray);
    gameOver = gameStatus(Size, userArray, difficultyLevel);
    steps++;
  } while (!gameOver && steps < Size * Size);
  if (steps == Size * Size) {
    printf("Not a valid game!");
  } else {
    printf("Game over!");
  }

  return 0;
}

//bool gameStatus(int Size, char userArray[][Size], int difficultyLevel) {
//  // you will need to call calculateScoreInDir
//    for(int row = 0; row < Size; row ++){
//        for(int col = 0; col < Size; col++){
//            if(calculateScoreInDir(row, col, 0, Size, userArray) == difficultyLevel){
//                return true;
//            }
//
//            else if(calculateScoreInDir(row, col, 1, Size, userArray) == difficultyLevel){
//                return true;
//            }
//
//            else if(calculateScoreInDir(row, col, 2, Size, userArray) == difficultyLevel){
//                return true;
//            }
//
//            else if(calculateScoreInDir(row, col, 3, Size, userArray) == difficultyLevel){
//                return true;
//            }
//        }
//    }
//
//    return false;
//
//}
//
//int calculateScoreInDir(int row, int col, int direction, int Size, char userArray[][Size]) {
//    int sum = 0, OGrow = row, OGcol = col;
//
//    if((int)userArray[row][col] == 48){ //if initial coord = 0
//        return sum;
//    }
//
//
//        //keep adding 1 to the score until we hit a 0 or if the coordinate does not exist
//
//        while(validRowCol(row, col, Size) && (int)userArray[row][col] == 49){ //as long as we are within the boundaries of the grid
//
////            if((int)userArray[row][col] == 49){
////                sum++;
////            }else { //if we hit a 0
////                break;
////            }
//            sum++;
//            updateRowCol(&row, &col, direction, true); //forward
//
//        }
//
//        //start again from original coordinate to go backwards
//        row = OGrow;
//        col = OGcol;
//        sum--;
//        while(validRowCol(row, col, Size) && (int)userArray[row][col] == 49){ //as long as we are within the boundaries of the grid
//            //printf("userArray[row][col]: %d", userArray[row][col]);
//
////            if((int)userArray[row][col] == 49){
////                sum++;
////            }else{ //if we hit a 0
////                break;
////            }
//            sum++;
//            updateRowCol(&row, &col, direction, false); //backward
//        }
//
//        return sum;
//
//
//}
//
//bool validRowCol(int row, int col, int Size) {
//  // from part 1
//    if(row <= (Size-1) && row >= 0 && col <= (Size-1) && col >= 0){
//        return true;
//    }
//
//    else{
//        return false;
//    }
//}
//
//void updateRowCol(int* row, int* col, int dir, bool forward) {
//    if(forward){ //direction is forward
//        if(dir == 0){
//            (*row)--;
//        }
//
//        else if(dir == 1){
//            (*row)--;
//            (*col)++;
//        }
//
//        else if(dir == 2){
//            (*col)++;
//        }
//
//        else if(dir == 3){
//            (*row)--;
//            (*col)--;
//        }
//    }
//
//    else { //direction is not forward
//        if(dir == 0){
//            (*row)++;
//        }
//
//        else if(dir == 1){
//            (*row)++;
//            (*col)--;
//        }
//
//        else if(dir == 2){
//            (*col)--;
//        }
//
//        else if(dir == 3){
//            (*row)++;
//            (*col)++;
//        }
//    }
//}
//
//void printBoard(int Size, char grid[][Size]) { //similar to p1
//    for(int i = 0; i<Size; i++){
//        for(int j = 0; j<Size; j++){
//            if(grid[i][j] == 48){ // 0
//                printf("0");
//            }
//
//            else if(grid[i][j] == 49){ // 1
//                printf("1");
//            }
//
//            else if(grid[i][j] == 45){ // -
//                printf("-");
//            }
//        }
//        printf("\n");
//    }
//}

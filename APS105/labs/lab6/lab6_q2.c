#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void updateRowCol(int* row, int* col, int dir, bool forward);
int calculateScoreInDir(int row, int col, int direction, int Size,
                        char userArray[][Size]);
bool validRowCol(int row, int col, int Size);

int lab6_q2(void) {
  const int maxDim = 23;
  int Size = 0;
  printf("Enter size: ");
  scanf("%d", &Size);

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
    
//printing the array to check
//    printf("lets check this silly guy");
//    for(int i = 0; i< Size; i++){
//        for(int j = 0; j< Size; j++){
//            printf("%d", grid[i][j]);
//        }
//        printf("\n");
//    }

  // call calculateScoreInDir here to check if it works as expected!
  for (int row = 0; row < Size; row++) {
    for (int col = 0; col < Size; col++) {
      printf("Row: %d, Col: %d, in direction\n", row, col);
      printf(" 0 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 0, Size, grid));
      printf(" 1 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 1, Size, grid));
      printf(" 2 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 2, Size, grid));
      printf(" 3 ");
      printf("Score: %d.\n", calculateScoreInDir(row, col, 3, Size, grid));
    }
  }

  return 0;
}

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
//        
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

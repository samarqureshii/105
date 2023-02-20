#include <stdbool.h>
#include <stdio.h>
void calculateScore(int[], const int, int[], int[], const int, int*,
                    int*);  // calculate the score of each user
int main(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
    
  printf("Enter boxes content: ");
    
  for (int i = 0; i < BoxesNum; i++) {
    scanf("%d", &boxes[i]);
  }
    
  printf("Enter player 1 choices: ");
    
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userOne[i]);
  }
    
  printf("Enter player 2 choices: ");
    
  for (int i = 0; i < ChoicesNum; i++) {
    scanf("%d", &userTwo[i]);
  }
    
  int userOneScore = 0, userTwoScore = 0;
    
  calculateScore(boxes, BoxesNum, userOne, userTwo, ChoicesNum, &userOneScore, &userTwoScore);
    
  printf("Player 1: %d.\nPlayer 2: %d.\n", userOneScore, userTwoScore);
    
  return 0;
}

void calculateScore(int boxes[], const int BoxesNum, int userOne[],int userTwo[], const int ChoicesNum, int* score1, int* score2) {
  // Get the score of each user
    
    for(int i = 0; i< BoxesNum; i++){ //iterating through box content
        if(boxes[i] == -10 || boxes[i] == 10){ //if we find a bomb or candy in the boxes
            printf("Found %d in boxes[%d].\n", boxes[i], i);
            int j,k;
            
            for(j = 0; j<ChoicesNum; j++){ //iterating through player 1's choices
                if(userOne[j] == i){
                    printf("Found index %d in player 1.\n", i);
                    break;
                }
            }
            
            for(k = 0; k<ChoicesNum; k++){ //iterating through player 2's choices
                if(userTwo[k] == i){
                    printf("Found index %d in player 2.\n", i);
                    break;
                }
            }
            
            if(j == 5 && k == 5){
                continue;
            }
            
            if(j == 5){
                if(boxes[i] < 0){
                    *score2 += -10;
                    printf("-10 from player 2 score.\n");
                }
                
                else{
                    *score2 += 10;
                    printf("+10 to player 2 score.\n");
                }
            }
            
            else if(k == 5){
                if(boxes[i] < 0){
                    *score1 += -10;
                    printf("-10 from player 1 score.\n");
                }
                
                else{
                    *score1 += 10;
                    printf("+10 to player 1 score.\n");
                }
            }
            
            else{
                
                if(boxes[i] < 0){
                    *score1 += -10;
                    *score2 += -10;
                    printf("-10 from player 1 score.\n-10 from player 2 score.\n");
                }
                
                else{
                    *score1 += 5;
                    *score2 += 5;
                    printf("+5 to players 1 and 2 scores.\n");
                }
            }
    }
    
    }
    
}






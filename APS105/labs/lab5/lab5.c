#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum);
void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum, const int BoxesNum);
void populateBoxes(int boxes[], const int BoxesNum);

int main_lab5(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int boxes[BoxesNum], userOne[ChoicesNum], userTwo[ChoicesNum];
  populateBoxes(boxes, BoxesNum);
  takeUserChoices(userOne, userTwo, ChoicesNum, BoxesNum);
  return 0;
}

void takeUserChoices(int userOne[], int userTwo[], const int ChoicesNum,
                     const int BoxesNum) {
  // Can check if the inputs are distinct and if they are between 1 and BoxesNum
  // - 1
  do {
    printf("Player 1, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userOne[choiceInd]);
    }
  } while (!validateChoices(userOne, ChoicesNum, BoxesNum));
    
  do {
    printf("Player 2, please enter distinct box choices between 0 and 19: ");
    for (int choiceInd = 0; choiceInd < ChoicesNum; choiceInd++) {
      scanf("%d", &userTwo[choiceInd]);
    }
  } while (!validateChoices(userTwo, ChoicesNum, BoxesNum));
    
}


//part 1
void populateBoxes(int boxes[], const int BoxesNum) {
    for(int i = 0; i<BoxesNum; i++){
        boxes[i] = ((rand() % 3)-1)*10; //generating boxes
        printf("%d: %d, ", i, boxes[i]); //printing the content of the boxes
    }
    printf("\n");
}

bool validateChoices(int choices[], const int ChoicesNum, const int BoxesNum) { //BoxesNum is the number of elements in the array (20)
    //ChoicesNum is the number of choices the user has (5)
  bool valid = true;
    
    for(int i = 0; i<ChoicesNum-1; i++){
        if(choices[i] == choices[i+1]){
            valid = false;
        }
    }
    
    for(int j = 0; j<ChoicesNum; j++){
        if(choices[j] < 0 || choices[j] > (BoxesNum-1)){
            valid = false;
        }
    }
    
  // Check if elements in choices is distinct
  return valid;
}

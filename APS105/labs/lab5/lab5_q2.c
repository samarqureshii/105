#include <stdio.h>

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]);
int frequentBox(int histogram[], const int BoxesNum);

int lab5_q2(void) {
  const int BoxesNum = 20;
  const int ChoicesNum = 5;
  int userOne[ChoicesNum], userOneHisto[BoxesNum];
  
    for (int i = 0; i < BoxesNum; i++) {
        userOneHisto[i] = 0;
    }
    
  int numOfTimes = 0;
    
  while (numOfTimes <= 5) {
    printf("Enter choices: ");
    
      for (int i = 0; i < 5; i++) {
          scanf("%d", &userOne[i]);
      }
      
    appendStatistics(userOne, ChoicesNum, userOneHisto);
    numOfTimes++;
  }
    
  printf("The smallest and most frequently used box is: %d\n", frequentBox(userOneHisto, BoxesNum));
    
  return 0;
}

void appendStatistics(int userChoice[], const int ChoicesNum, int histogram[]) {
    //if segmentation fault occurs, then for loop to initialize each array with 0s
    
    for(int i = 0; i<20; i++){ //going through the histogram
        for(int j = 0; j<ChoicesNum; j++){ //going through userChoice
            if (userChoice[j] == i){
                histogram[i]++;
            }
        }
        
        //printing histogram
        printf("%d: %d, ", i, histogram[i]);
    }
    
    printf("\n");
}

int frequentBox(int histogram[], const int BoxesNum) {
  // Return the index having the maximum number in histogram
    int max = 0;
    
    for(int i = 0; i<BoxesNum; i++){
        if(histogram[i] > max){
            max = i;
        }
    }
    
    return max;
}

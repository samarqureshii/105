#include <stdbool.h>
#include <stdio.h>

bool isShuffled(int);
int getNumDigits(int);
int getSmallestDigit(int);
bool lookForDigit(int, int);

int lab4_q3(void) {
  int num;
  printf("Enter the number to check: ");
  scanf("%d", &num);
    
  if (isShuffled(num)) {
    printf("Shuffled!");
  }
  
  else {
    printf("Not shuffled!");
  }
  return 0;
}

bool isShuffled(int shuffledOrder) {
  bool isShuffled = true;
    
  int numOfDigits = getNumDigits(shuffledOrder);
  int smallestDigit = getSmallestDigit(shuffledOrder);

  for (int i = 0; i <= numOfDigits-1; i++) {
      
    if (!lookForDigit(shuffledOrder, smallestDigit + i)) {
        //if the digit is not inside the shuffled order
        printf("\n %d is not inside of %d", smallestDigit + i, shuffledOrder);
      isShuffled = false;
    }
      
    else {
        isShuffled = true;
    }

  }
    
  return isShuffled;
}

int getNumDigits(int num) { //returns number of digits
  int count = 0;
    
  while (num != 0) {
    num = num / 10;
    count++;
  }
    
  return count;
}

int getSmallestDigit(int num) {
  int smallestDigit = num%10; //start off with last digit of the number
  int digit = 0;
    
  while (num > 0) {
    digit = num % 10; //get the last digit of the number
      
    if (smallestDigit > digit) {
      smallestDigit = digit;
    }
      
    num = num / 10; //truncate the last digit
  }
  return smallestDigit;
}

bool lookForDigit(int num, int searchDigit) {
  int digit = 0;
  bool foundDigit = false;

  while (num != 0 && !foundDigit) {
    digit = num % 10;

    if (digit == searchDigit) {
      foundDigit = true;
    }
    num /= 10;
  }
  return foundDigit;
}

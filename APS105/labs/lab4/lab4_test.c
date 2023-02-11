////
////  lab4_test.c
////  APS105
////
////  Created by Samar Qureshi on 2023-02-11.
////
//
//#include <stdio.h>
//#include <stdbool.h>
//
//int getNumDigits(int);
//int getSmallestDigit(int);
//bool lookForDigit(int, int);
//
//int main(){
//    int num = 293847;
//    int searchDigit = 2;
//    
//}
//
//bool isShuffled(int shuffledOrder) {
//  bool isShuffled = true;
//  int numOfDigits = getNumDigits(shuffledOrder);
//  int smallestDigit = getSmallestDigit(shuffledOrder);
//    
//  for (int place = 1; place <= numOfDigits && isShuffled; place++) {
//      
//    if (!lookForDigit(shuffledOrder, smallestDigit + place)) {
//      isShuffled = false;
//    }
//      
//  }
//    
//  return isShuffled;
//}
//
//bool lookForDigit(int num, int searchDigit) {
//  int digit = 0;
//  bool foundDigit = false;
//
//  while (num != 0 || foundDigit) {
//    digit = num % 10;
//
//    if (digit == searchDigit) {
//      foundDigit = true;
//    }
//    num /= 10;
//  }
//  return foundDigit;
//}
//
//int getNumDigits(int num) { //returns number of digits
//  int count = 0;
//    
//  while (num != 0) {
//    num = num / 10;
//    count++;
//  }
//    
//  return count;
//}
//
//int getSmallestDigit(int num) {
//  int smallestDigit = num%10; //start off with last digit of the number
//  int digit = 0;
//    
//  while (num > 0) {
//    digit = num % 10; //get the last digit of the number
//      
//    if (smallestDigit > digit) {
//      smallestDigit = digit;
//        printf("\nSmallest digit after iteration is %d", smallestDigit);
//    }
//      
//    num = num / 10; //truncate the last digit
//  }
//  return smallestDigit;
//}
//
//

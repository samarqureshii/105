//
//  lab4.c
//  APS105
//
//  Created by Samar Qureshi on 2023-02-08.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

//functions for q1
int getAscendingOrderedDigits(int);
int getNumber(void);
int reverseNumber(int);
int getDigits(int);

int lab4_q1(void){ //q1
    int num = getNumber();
    int ascend = 0, descend = 0, diff = num, counter = 1;
    
    while(num!=-1){

        while(diff != 6174){
            printf("Number %d: %d", counter, diff);
            ascend = getAscendingOrderedDigits(num);
            descend = reverseNumber(ascend);

            if(ascend > descend){
                diff = ascend - descend;
            }
            
            else{
                diff = descend - ascend;
            }
            num = diff;
            counter ++;
            printf("\n");
        }
        
        printf("Number %d: %d", counter, 6174);
        printf("\nKaprekar's Constant was reached in %d iteration(s).\n", counter-1);

        

        num = getNumber(); //step 1
        diff = num; //reset difference
        counter = 1; //reset counter

    }
    
    return 0;
}

int getAscendingOrderedDigits(int number) { //DO NOT SUBMIT on examify
    //returns a number containing the same digits as the input parameter, put in increasing order
    
    int digits[10] = {0}; //create an array that will store each of the digits as a single index
    
    while (number > 0) { //store each digit in each index
        digits[number % 10]++;
        number /= 10;
    }
    
    int i = 0;
    
    //sorting the digits
    while (i < 10) { //sorting the digits
        if (digits[i] > 0) {
            number *= 10;
            number += i;
            digits[i]--;
        }
        
        else {
            i++;
        }
        
    }
    
    return number;
}



int getNumber(void){ //prompts user to enter a number and returns the given number
    //checks for any bad forms of data
    
    //assume that: input is correct number of values, user does not enter any of the same digit numbers (i.e., 1111), user supplies positive integers, no result will ever be larger than the largest int value
    int input = 0;
    bool flag = true;
    do{
        printf("Enter a number (-1 to stop): ");
        scanf("%d", &input);
        
        if(input == -1){ //if the user wants to exit the while loop in main method
            return -1; //premature return
        }
        
        else if(getDigits(input) > 4){ //if input is too large
            printf("Error: the number is too large.\n");
        }
        
        else if(getDigits(input) < 4){ //input is too small
            printf("Error: the number is too small.\n");
        }
        
        else { //input was valid
            flag = false;
        }
        
//        printf("\n");
        
    }while (flag); //keeps asking user for input until input is valid
    
    return input;
}

int reverseNumber(int num){ //reverses any four digit number
    int rev = 0;
    
    while(num!=0){
        rev = (rev*10) + (num%10);
        num/=10;
    }
    
    if(getDigits(rev) == 1){ //if reversed number is like 0001
        rev*=1000;
    }
    
    else if(getDigits(rev) == 2){ //if reversed number is like 0011
        rev*=100;
    }
    
    else if(getDigits(rev) == 3){ //if reversed number is like 0111
        rev*=10;
    }
    
    return rev;
}

int getDigits(int num) { //returns number of digits
  int count = 0;
    
  while (num != 0) {
    num = num / 10;
    count++;
  }
    
  return count;
}

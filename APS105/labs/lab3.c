//
//  lab3.c
//  APS105
//
//  Created by Samar Qureshi on 2023-02-01.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>


int biggestDigit(int num){ //find the largest digit in any number
    int large = 0;
    
    while(num!=0){
        int n = num % 10; //extracting the digits
        large = fmax(n, large);
        num = num/10;
    }
    
    return large;
}

int convertToDecimal(int num, int base){ //converts a number in any base from 2-10 TO decimal (base 10)
    int ans = 0, power = 1;
    
    while(num!=0){ //iterate through all the digits and multiply them by their respective weights
        int r = num%10;
        num/=10;
        
        ans+=r*power;
        power*=base;
        
    }
    
    return ans; //returns the number in base 10
}

int convertFromDecimal(int num, int base){ //converts a number FROM decimal to any base (from 2-10)
    int ans = 0;
    int power = 0;
    int rem;
    
    while(num>0){
        rem = num%base;
        ans+=rem*pow(10, power);
        num/=base;
        power++;
    }
    
    return ans; //returns the number in the desired output base
}

int lab3_q1(void){ //q1
    char op = 0;
    int inBase, num1, num2, outBase;
    
    while (op!= '$'){
        printf("Give input ($ to stop): ");
        scanf(" %c %d %d %d %d", &op, &inBase, &num1, &num2, &outBase);
        
        //TESTING
//        printf("in base %d", inBase);
//        printf("\nout base %d", outBase);
//        printf("\nbiggest digit 1: %d", biggestDigit(num1));
//        printf("\n biggest digit 2: %d \n", biggestDigit(num2));
//
        if(op!= '+' && op!= '-' && op!= '*' && op!='/'){ //if operator is not valid
            //printf("Operator: %c", op);
            
            if(op == '$'){
                break;
            }
            printf("Invalid operator\n");
        }

        else if(inBase<2 || outBase<2 || inBase >10 || outBase>10){ //invalid input/output base
            printf("Invalid base\n");
        }

        else if(biggestDigit(num1) >= inBase || biggestDigit(num2) >= inBase){ //invalid operand
            //check to see if any of the digits are >= the base entered
            printf("Invalid digits in operand\n");
        }
        
        else{ //if the input is valid
            //display LH side of operation
            printf("%d %c %d (base %d) = ", num1, op, num2, inBase);
            
            //convert both numbers from inBase to base 10
            num1 = convertToDecimal(num1, inBase);
            num2 = convertToDecimal(num2, inBase);
            
            //display middle portion of operation
            
            printf("%d %c %d = ", num1, op, num2);
            
            //perform operation in base 10
            int postOp = 0; //the concat. of the two numbers post-operation
            
            if(op == '+'){
                postOp  = num1+num2;
            }
            
            else if(op == '-'){
                postOp = num1-num2;
            }
            
            else if(op == '*'){
                postOp = num1*num2;
            }
            
            else if(op == '/'){
                postOp = num1/num2;
            }
            
        
            //convert the result of the operation to the outBase
            printf("%d (base %d)\n", convertFromDecimal(postOp, outBase), outBase);
        }

    }
    
    return 0;
    
}

int lab3(void){ //q2
    int r, x;
    printf("Enter the radius of the circle: ");
    scanf("%d", &r);
    
    for(int y = -r; y<=r; y++){ //go through every row
        x = sqrt(pow(r,2)-pow(y,2));
        
        for(int i = -r; i<=r; i++){ //go through every entry in a singular row
            if (abs(i) <= abs(x)){
                printf("o");
            }
            
            else{
                printf(".");
            }
        }
        
        printf("\n");
    }
    
    return 0;
}

int lab3_q3(void) { //q3
  char userChar;
  int sum = 0, sign = +1;
  bool number = true;
  printf("Enter sequence of characters with numbers to add: ");
    
  do {
    scanf(" %c", &userChar);
    if (number) { //user is expected to enter a number
        
      while (userChar < '0' || userChar > '9') { //if int is not valid
        printf("Invalid! Re-enter number.\n");
        scanf(" %c", &userChar);
      }

      number = false;
      sum += sign * (userChar - '0'); //converting the char into an int, multiplying by the sign
        if(sum<0){
            break;
        }
    }
      
      scanf(" %c", &userChar);
     //user is expected to enter a char
      if(!number){
          while (userChar != '+' && userChar != '-') { //if char is not valid
            printf("Invalid! Re-enter sign.\n");
            scanf(" %c", &userChar);
          }

          if (userChar == '+') {
            sign = 1;
          }

          else if (userChar == '-'){
            sign = -1;
          }
          
          number = true;
      }
      
//      printf("sum after the iteration: %d \n", sum);
//      printf("sign after the iteration: %d \n", sign);
  
  } while (sum > 0);
  printf("Sum fell below zero.\n");
  return 0;
}



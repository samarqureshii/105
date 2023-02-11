//
//  lab4_q2.c
//  APS105
//
//  Created by Samar Qureshi on 2023-02-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

//function declaration
int enterOrder(void);
void drawGrid(int []);


int main(void){
    int order = enterOrder();
    
    while(order!=-1){
        int arr[4]; //each index of the array stores a coefficient
        for(int i = 0; i<4; i++){ //initialize the array
            arr[i] = 0;
        }
        
        for(int i = 0; i<=order; i++){
            printf("Enter coefficient of x^%d: ", i);
            scanf("%d", &arr[i]); //each coefficient is stored in an array
        }
        
        drawGrid(arr);
        
        order = enterOrder();
    }
    
    return 0;
}

int enterOrder(void){ //ensures user enters valid order
    int order = 0;
    do{
        printf("Enter the order of the function: ");
        scanf("%d", &order);
        
        if(order == -1){
            return -1;
        }
        
        else if(order > 3 || order < 0){
            printf("The order must be between [0, 3].\n");
        }
        
    } while (order > 3 || order < 0);
    
    return order;
}

void drawGrid(int arr[]){
    int factor0 = arr[0];
    int factor1 = arr[1];
    int factor2 = arr[2];
    int factor3 = arr[3];
    
    if(arr[0] == 0){ //if coeff for x^0 is 0
        factor0 = 0;
    }
    
    if(arr[1] == 0){ //coeff for x^1 is 0
        factor1 = 0;
    }
    
    if(arr[2] == 0){ //coeff for x^2 is 0
        factor2 = 0;
    }
    
    if(arr[3] == 0){ //coeff for x^3 is 0
        factor3 = 0;
    }
    
    for(int i = 10; i>=-10; i--){ //go through every row (each y value)

        for(int j = -10; j<=10; j++){ //go through every entry in the row (each x value)
            int y = (factor0*pow(j,0)) + (factor1*pow(j,1) + (factor2*pow(j,2)) + (factor3*pow(j,3)));
            
            if(i == y){ //if the current y value matches the function based on current x value
                printf(" * ");
            }
            
            else if(j == 0){ //drawing the y axis
                printf(" | ");
            }
            
            else if(i == 0){ //drawing the x axis
                printf(" - ");
            }
            
            else if(i == 0 && j == 0){ //drawing the origin
                printf (" - ");
            }
            
            
            else{ //empty space
                printf("   ");
            }
            
        }
        
        printf("\n");
    }
}





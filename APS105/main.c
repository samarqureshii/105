//This file is used to test and run code 

#include <stdio.h>

int main(void) {
    int num, d1, d2, d3, d4;
    printf("Enter number to convert to base 2: ");
    scanf("%d", &num);
    
    d4 = (num%2);
    d3 = (num/2)%2;
    d2 = ((num/2)/2)%2;
    d1 = (((num/2)/2)/2)%2;
    
    printf("The four digits of that number are as follows:");
    printf("\nMost significant digit: %d", d1);
    printf("\nNext digit: %d", d2);
    printf("\nNext digit: %d", d3);
    printf("\nLeast significant digit: %d", d4);

    
    return 0;
}

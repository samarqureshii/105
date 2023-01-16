//
//  lab1.c
//  APS105
//
//  Created by Samar Qureshi on 2023-01-14.
//

#include <stdio.h>

int lab1_q1(void) {
    // insert code here...
    printf("C uses escape sequences for a variety of purposes. \n Some common ones are: \n");
    printf("\t to print \", use \\ ");
    printf("\" \n");
    printf("\t to print  \\, use  \\");
    printf("\\ \n");
    printf("\t to jump to a new line, use \\");
    printf("n \n");
    return 0;
}

//Enter the conversion rate: 0.17<enter>
//Enter the amount to be converted (in foreign currency): 245.00<enter>
//
//The amount in Canadian Dolars is: 41.65

int lab1_q2(void) {
    double rate, amount;
    
    printf("Enter the conversion rate: ");
    scanf("%lf", &rate);
    
    printf("\nEnter the amount to be converted (in foreign currency): ");
    scanf("%lf", &amount);
    
    amount = amount * rate;
    
    printf("\nThe amount in Canadian Dollars is: %.2lf\n", amount);
    
    return 0;
}

//Enter number to convert to base 2: 13<enter>
//The four digits of that number are as follows:
//Most significant digit: 1
//Next digit: 1
//Next digit: 0
//Least significant digit: 1

int lab1_q3(void){
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

int lab1_q4(void){
    const double CmPerInch = 2.54;
    const double CmPerMetre = 100.00;
    const int InchesPerFoot = 12;
    const int InchesPerYard = 36;
    
    double distance;
    printf("Please provide a distance in metres: ");
    scanf("%lf", &distance);
    
    double distanceInInches = distance * CmPerMetre / CmPerInch;
//    printf("%lf is the distance in inches \n", distanceInInches);
    
    // truncate fractional part to get # of inches
    int inches = distanceInInches;
    distanceInInches = distanceInInches - inches;
    
    int yards = inches / InchesPerYard;
    
    // how many inches are left after extracting yards
    inches = inches % InchesPerYard;
    int feet = inches / InchesPerFoot;
    
    // how many inches are left after extracting feet
    inches = inches % InchesPerFoot;
    
    printf("%d yards, %d feet, %d inches, %.2f inches remainder\n", yards, feet, inches, distanceInInches);
    
    return 0;
}

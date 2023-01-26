

#include <stdio.h>
#include <math.h>

int lab2_q1(void) { //q1
    double X, Y;
    const double PI = 3.14159265359;
    
    printf("Enter X: ");
    scanf("%lf", &X);
    printf("Enter Y: ");
    scanf("%lf", &Y);
    
    double H = sqrt(pow(X,2) + pow(Y,2)); //hypotenuse
    double theta =asin(Y/H)*(180/PI); //convert to rad
    
    printf("The Hypotenuse Length is: %.1lf\n", H);
    printf("The Angle Theta is: %.1lf degrees\n", theta);
    return 0;
}

int lab2_q2(void) { //q2
    double x,y;
    
    printf("Enter the x-coordinate in floating point: ");
    scanf("%lf", &x);
    printf("Enter the y-coordinate in floating point: ");
    scanf("%lf", &y);
    printf("\n");
    
    if(x==0 && y ==0){ //if coord is at the origin
        printf("(%.2f, %.2f) is at the origin.", x, y);
    }
    
    else if (x==0){ //if coord is on the x axis
        printf("(%.2f, %.2f) is on the y axis.", x, y);
    }
    
    else if (y==0){ //if coord is on the y axis
        printf("(%.2f, %.2f) is on the x axis.", x, y);
    }
    
    else if(x>0 && y>0){ //if coord is quad 1
        printf("(%.2f, %.2f) is in quadrant I.", x, y);
    }
    
    else if(x<0 && y>0){ //if coord is quad 2
        printf("(%.2f, %.2f) is in quadrant II.", x, y);
    }
    
    else if(x<0 && y<0){ //if coord is quad 3
        printf("(%.2f, %.2f) is in quadrant III.", x, y);
    }
    
    else { //if coord is in quad 4
        printf("(%.2f, %.2f) is in quadrant IV.", x, y);
    }
    return 0;
}

int lab2_q3(void){ //q3
    double weight, height, BMI;
    char c1, c2;
    
    printf("Enter the body weight: ");
    //handle and convert input in kilograms or pounds
    scanf("%lf %c %c", &weight, &c1, &c2); //simultaneous digit and char scanning

    
    if(c1 == 'l' && c2 == 'b'){ //if the user enters weight in pounds
        weight/=2.205; //convert from pounds to kilos5
    }
    
    
    printf("Enter the height: ");
    //handle and convert input in inches, feet, or meters
    scanf("%lf %c %c", &height, &c1, &c2); //simultaneous digit and char scanning
    
    if(c1 == 'i' && c2 == 'n'){ //if user enters height in inches
        height/=39.37; //convert from inches to meters
    }
    
    else if(c1 == 'f' && c2 == 't'){ //if user enters height in feet
        height/=3.281; //convert from feet to meters
    }
    
    else{
        printf("Invalid input!");
    }
    
    BMI = weight/pow(height,2);
    printf("\nThe Body Mass Index (BMI) is: %.1f", BMI);
    printf("\nCategory:");
    
    //classify weight category
    if(BMI < 18.5){
        printf(" Underweight");
    }

    else if(BMI >=18.5 && BMI <25){
        printf(" Healthy Weight");
    }

    else if(BMI >=25 && BMI <30){
        printf(" Overweight");
    }
    
    else if (BMI >=30){
        printf(" Obesity");
    }

    return 0;
}

int main(void) {
    int encComb;
    printf("Enter an encrypted 4-digit combination: ");
    scanf("%d", &encComb);
    // Determine the 4 digits of the encrypted combinaiton.
    int d4, d3, d2, d1;
    encComb = encComb / 1000;
    d4 = encComb % 1000;
    encComb = encComb / 100;
    d3 = encComb % 100;
    encComb = encComb / 10;
    d2 = encComb % 10;
    d1 = encComb;
    // printing the decryped combination: d4 and d1 are swaped. d3 and d2 are
    // are 9's complemented
    printf("\nThe real combination is: %d%d%d%d\n", d1, 9 - d3, 9 - d2, d4);
    return 0;
}


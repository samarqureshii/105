

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

int main (void){ //q3
    
    printf("Enter the body weight: ");
    //handle and convert input in kilograms or pounds
    
    printf("Enter the height: ");
    //handle and convert input in inches, feet, or meters
    
    printf("The Body Mass Index (BMI) is: ");
    //BMI = (weight in kilos) divided by (height in m)^2
    
    //classify category of weight
    
    return 0;
}


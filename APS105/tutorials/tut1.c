// input is 3.376 meters
//3 yards, 2 feet, 0 inches, 0.91 inches remainder

#include <stdio.h>

int tut1(void) {
    
    const int secondsPerDay = 80400;
    const int secondsPerHour = 3600;
    const int secondsPerMinute = 60;
    const int minutesPerDay = 1440;
    const int minutesPerHour = 60;
    const int hoursPerDay = 24;
    
    printf("Enter the day in the month: ");
    double day;
    scanf("%lf", &day);
    day = day-1;
    
    printf("\nEnter the hour in the day: ");
    double hour;
    scanf("%lf", &hour);
    
    printf("\nEnter the minute in the hour: ");
    double minute;
    scanf("%lf", &minute);
    
    printf("\nEnter the second in the hour: ");
    double second;
    scanf("%lf", &second);
    
    int seconds = day*secondsPerDay + hour*secondsPerHour + minute*secondsPerMinute + second;
    double minutes = day*minutesPerDay + hour*minutesPerHour + minute + (second/secondsPerMinute);
    double hours = day*hoursPerDay + hour + (minute/minutesPerHour) + (second/secondsPerHour);
    double days = day + (hour/hoursPerDay) + (minute/minutesPerDay) + (second/secondsPerDay);
    
    printf("Do you know that time is precious?\n  %d seconds, or %.2lf minutes, or %.2lf hours, or %.2lf days have elapsed since the beignning of the month. \n", seconds, minutes, hours, days);
    
    return 0;
}

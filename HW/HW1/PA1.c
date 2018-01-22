// PA1.c -- James Kajon
#include <stdio.h>

/**
 * Determins if the given year is a leep year based on the conditions of the Gregorian calender
 * 
 * @param year the year to check
 * @return if the year is a leep year returns 1, else 0
 */
int isLeapYear(int year) {
    return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
}

/**
 * Calulates the day of the week January starts on for the given year.
 * 
 * @param year the year to calculate for
 * @return the day of the week as an int (Sunday=0, Monday=1,...)
 */
int calculateStartingWeekDay(int year) {
    int leep4, leep100, leep400;    // the number of days added or removed from the calender due to each of leep year rules
    leep4 = (year - 1) / 4;
    leep100 = (year - 1) / 100;
    leep400 = (year - 1) / 400;
    return (year + leep4 - leep100 + leep400) % 7;
}

/**
 * Use the given month id to print a lable for the month and
 * get the number of days in that month.
 * 
 * @param year the year the calender is for
 * @param month the number corresponding to the month to print and return days for
 * 
 * @return the number of days in the given month
 */
int printMonthName(int year, int month) {
    int days;   // number days in the given month
    switch (month) {    // finds the name and number of days for the given month
        case 0 :
            printf("January %d\n", year);
            days = 31;
            break;
        case 1 :
            printf("February %d\n", year);
            if (isLeapYear(year)) {
                days = 29;
                break;
            }
            days = 28;
            break;
        case 2 :
            printf("March %d\n", year);
            days = 31;
            break;
        case 3 :
            printf("April %d\n", year);
            days = 30;
            break;
        case 4 :
            printf("May %d\n", year);
            days = 31;
            break;
        case 5 :
            printf("June %d\n", year);
            days = 30;
            break;
        case 6 :
            printf("July %d\n", year);
            days = 31;
            break;
        case 7 :
            printf("August %d\n", year);
            days = 31;
            break;
        case 8 :
            printf("September %d\n", year);
            days = 30;
            break;
        case 9 :
            printf("October %d\n", year);
            days = 31;
            break;
        case 10 :
            printf("November %d\n", year);
            days = 30;
            break;
        case 11 :
            printf("December %d\n", year);
            days = 31;
            break;
    }
    return days;
}

/**
 * Print out the calender for the given month
 * 
 * @param year the year the calender is for
 * @param month the number corresponding to the month to print
 * @param startingWeekDay number of the day of the week (Sunday=0, Monday=1,...)
 * @return the next month's starting day of the week
 */
int printMonth (int year, int month, int startingWeekDay) {
    int days = printMonthName(year, month);   // number of days in the month

    printf("\nSun  Mon  Tue  Wed  Thu  Fri  Sat\n");    // print days of week lable
    // Pre-condition: indent is 0 which would have to be less than startingWeekDay
    for (int indent = 0; indent < startingWeekDay; indent++) {
        // indent: the number indent that is will print to indent the first day of the month
        // indent the first day by 5 spaces per day of the week that already happended in that week
        /* loop invariant : is true only if indents are needed. will eventualy terminate
                when the number of indents done is equal to the id of the starting day*/
        printf("     ");
    }   // for indent
    // Post-condition: indent is equal to startingWeekDay

    // Pre-condition: d is 1 which is less than or equal to days
    for (int d = 1; d <= days; d++) {   // d: the curent date to print
        // generate days from 1 up to and including the number of days in the month
        /* loop invariant : is initially true because each month has more than 0 days. 
                will eventually terminate when the day is equal to the days in the month*/
        printf("%3d  ", d);     // print the date with formating
        if ((d + startingWeekDay) % 7 == 0) {   // split weeks by new lines
            printf("\n");
        }
    }   // for d
    // Post-condition: d is one greater than days

    printf("\n\n");

    return (days + startingWeekDay) % 7;
}

/**
 * Print out the calender of the given year
 * 
 * @param year the year the calender is for
 * @param startingWeekDay the day of the week the year starts on (Sunday=0, Monday=0,...)
 */
void printCalender(int year, int startingWeekDay) {

    printf("\n\n   ***   CALENDAR for %d   ***\n\n", year);
    // Pre-condition: m is zero which is less than the hardcoded 12
    for (int m = 0; m < 12; m++) {  // m: the curent month to print
        // loops though months 0=Jan, 1=Feb, ...
        /* loop invariant : is initaly true because m is initialized to 0 and checked 
                if less than 12. will stay true until m is 11 which represents December*/
        startingWeekDay = printMonth(year, m, startingWeekDay);
    }   // for m
    // Post-condition: m is 12 which is not less the the hardcoded 12
}

/**
 * Ask the user for a year. Exit if the year is invalid 
 * else print the calender for the given year
 * @return 0 to show the program executed without a problem
 */
int main(void) {
    int year;   // the year the user will input

    printf("                        MONTHLY CALENDAR\n\n");
    printf("Please enter year for this calendar:- ");
    scanf("%d", &year);

    if (year <= 0) {
        printf("ERROR: The year must be above zero, you entered %d\n", year);
        return -1;
    }

    printCalender(year, calculateStartingWeekDay(year));

    return 0;
}



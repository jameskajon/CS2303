// calendar.c -- James Kajon
#include <stdio.h>

int shift = 1; // init to day of week of January; Sunday = 0
//const char months[][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
//const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int startingWeekDay;

int isLeapYear(int year) {
    return (year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0));
}


int calculateStartingWeekDay(int year) {
    int janStart, leep4, leep100, leep400;
    leep4 = (year - 1.0)/ 4.0;
    leep100 = (year - 1.0)/ 100.0;
    leep400 = (year - 1.0)/ 400.0;
    janStart = (year + leep4 - leep100 + leep400) % 7;
    return janStart;

}

int printMonth (char *month, int year) {
    printf("%s %d\n", month, year);
}


int printCalender(int year, int startingWeekDay) {

    printf("\n\n   ***   CALENDAR for %d   ***\n\n", year);

    for (int m = 0; m < 12; m++) {
        int days;	// number of days in the month

        switch (m) {
            case 0 :
                printMonth("January", year);
                days = 31;
                break;
            case 1 :
                printMonth("February", year);
                if (isLeapYear(year)) {
                    days = 29;
                    break;
                }
                days = 28;
                break;
            case 2 :
                printMonth("March", year);
                days = 31;
                break;
            case 3 :
                printMonth("April", year);
                days = 30;
                break;
            case 4 :
                printMonth("May", year);
                days = 31;
                break;
            case 5 :
                printMonth("June", year);
                days = 30;
                break;
            case 6 :
                printMonth("July", year);
                days = 31;
                break;
            case 7 :
                printMonth("August", year);
                days = 31;
                break;
            case 8 :
                printMonth("September", year);
                days = 30;
                break;
            case 9 :
                printMonth("October", year);
                days = 31;
                break;
            case 10 :
                printMonth("November", year);
                days = 30;
                break;
            case 11 :
                printMonth("December", year);
                days = 31;
                break;
        }

        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for (int indents = 0; indents < startingWeekDay; indents++) {
            printf("     ");
        }
        int d;

        //3123, 4314, 2323 issue !!!

        for (d = 1; d <= days; d++) {
            printf("%5d", d);
            if ((d + startingWeekDay) % 7 == 0) {
                printf("\n");
            }
        }
        startingWeekDay = (d + startingWeekDay - 1) % 7;

        printf("\n\n");
    }
    return 0;
}


int main(void) {
    int year;

    printf("                        MONTHLY CALENDAR\n\n");
    printf("Please enter year for this calendar:- ");
    scanf("%d", &year);

    if (year <= 0) {
        printf("ERROR: The year must be above zero, you entered %d\n", year);
        return -1;
    }


    int startingWeekDay = calculateStartingWeekDay(year);
    printCalender(year, startingWeekDay);

    return 0;
}



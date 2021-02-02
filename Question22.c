#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Code made for exam.

struct Date {
    int month, day, year;
};
struct Time {
    int hour, minute;
};

int main(){
    struct Date currentDate, birthDate;
    struct Time currentTime, timeOfBirth, timeDifference;
    int totaldays = 0;

    printf("AGE CALCULATOR \n");

    printf("Enter birth date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &birthDate.month, &birthDate.day, &birthDate.year);
    printf("Enter time of birth in 24hr format (hh:mm): ");
    scanf("%d:%d", &timeOfBirth.hour, &timeOfBirth.minute);

    // time_t is arithmetic time type
    time_t now;

    // Obtain current time
    // time() returns the current time of the system as a time_t value
    time(&now);

    struct tm *local = localtime(&now);

    currentTime.hour = local->tm_hour; // get hours since midnight (0-23)
    currentTime.minute = local->tm_min; // get minutes passed after the hour (0-59)
    currentDate.day = local->tm_mday; // get day of month (1 to 31)
    currentDate.month = local->tm_mon + 1; // get month of year (0 to 11)
    currentDate.year = local->tm_year + 1900; // get year since 1900

    totaldays = getDateDifference(birthDate, currentDate);

    if (currentTime.hour > timeOfBirth.hour) {
        getTimeDifference(currentTime, timeOfBirth, &timeDifference); // Difference between start and stop time
    } else {
        getTimeDifference(timeOfBirth, currentTime, &timeDifference);
    }

    printf("\nYour %d days and %d hrs old.\n", totaldays, timeDifference.hour);

    return 0;
}

// This function returns number of days between two given dates
// Reference: https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/
int getDateDifference(struct Date birthDate, struct Date currentDate) {
    // COUNT TOTAL NUMBER OF DAYS BEFORE FIRST DATE 'birthDate'
    // initialize count using years and day
    long int n1 = birthDate.year*365 + birthDate.day;

    // Add days for months in given date
    for (int i=0; i<birthDate.month - 1; i++) {
        if (i == 0) {
            n1 += 31;
        } else if (i == 1) {
            n1 += 28;
        } else if (i == 2) {
            n1 += 31;
        } else if (i == 3) {
            n1 += 30;
        } else if (i == 4) {
            n1 += 31;
        } else if (i == 5) {
            n1 += 30;
        } else if (i == 6) {
            n1 += 31;
        } else if (i == 7) {
            n1 += 31;
        } else if (i == 8) {
            n1 += 30;
        } else if (i == 9) {
            n1 += 31;
        } else if (i == 10) {
            n1 += 30;
        } else if (i == 11) {
            n1 += 31;
        }
    }

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'currentDate'
    long int n2 = currentDate.year*365 + currentDate.day;

    for (int i=0; i<currentDate.month - 1; i++) {
        if (i == 0) {
            n2 += 31;
        } else if (i == 1) {
            n2 += 28;
        } else if (i == 2) {
            n2 += 31;
        } else if (i == 3) {
            n2 += 30;
        } else if (i == 4) {
            n2 += 31;
        } else if (i == 5) {
            n2 += 30;
        } else if (i == 6) {
            n2 += 31;
        } else if (i == 7) {
            n2 += 31;
        } else if (i == 8) {
            n2 += 30;
        } else if (i == 9) {
            n2 += 31;
        } else if (i == 10) {
            n2 += 30;
        } else if (i == 11) {
            n2 += 31;
        }
    }

    // return difference between two counts
    return (n2 - n1);
}

// This function returns the difference between two given time period
// Reference: https://www.programiz.com/c-programming/examples/time-structure
void getTimeDifference(struct Time start, struct Time stop, struct Time *timeDifference) {
   while (stop.minute > start.minute) {
      --start.hour;
      start.minute += 60;
   }

   timeDifference->minute = start.minute - stop.minute;
   timeDifference->hour = start.hour - stop.hour;
}

#include <stdio.h>

// Code for the custom Age Calculator.

struct Date {
    int month, day, year;
};
struct Time {
    int hour, minute;
};

// Store number of days in all months from January to Dec.
const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
    char answer;
    struct Date currentDate, birthDate;
    struct Time currentTime, timeOfBirth, timeDifference;
    int totaldays = 0, counter = 0, leapYears[50];

    do {
        printf("AGE CALCULATOR \n");
        printf("\nEnter current date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &currentDate.month, &currentDate.day, &currentDate.year);
        printf("Enter current time in 24hr format (hh:mm): ");
        scanf("%d:%d", &currentTime.hour, &currentTime.minute);
        printf("Enter birth date (mm/dd/yyyy): ");
        scanf("%d/%d/%d", &birthDate.month, &birthDate.day, &birthDate.year);
        printf("Enter time of birth in 24hr format (hh:mm): ");
        scanf("%d:%d", &timeOfBirth.hour, &timeOfBirth.minute);

        totaldays = getDateDifference(birthDate, currentDate);

        if (currentTime.hour > timeOfBirth.hour) {
            getTimeDifference(currentTime, timeOfBirth, &timeDifference); // Difference between start and stop time
        } else {
            getTimeDifference(timeOfBirth, currentTime, &timeDifference);
        }

        printf("\nYour %d days, %d hrs, %d min old.\n", totaldays, timeDifference.hour, timeDifference.minute);

        printf("\nDo you want to try again? (Y/N)\n");
        printf("Answer: ");
        scanf(" %c", &answer);
        printf("\n");
    } while (answer == 'Y' || answer == 'y');

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
        n1 += monthDays[i];
    }

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(birthDate);

    // SIMILARLY, COUNT TOTAL NUMBER OF DAYS BEFORE 'currentDate'
    long int n2 = currentDate.year*365 + currentDate.day;

    for (int i=0; i<currentDate.month - 1; i++) {
        n2 += monthDays[i];
    }

    n2 += countLeapYears(currentDate);

    // return difference between two counts
    return (n2 - n1);
}

// This function counts number of leap years before the given date
// Reference: https://www.geeksforgeeks.org/find-number-of-days-between-two-given-dates/
int countLeapYears(struct Date d) {
    int years = d.year;

    // Check if the current year needs to be considered
    // for the count of leap years or not
    if (d.month <= 2) {
        years--;
    }

    // An year is a leap year if it is a multiple of 4,
    // multiple of 400 and not a multiple of 100.
    return years / 4 - years / 100 + years / 400;
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

#include <stdio.h>

// Print the custom pyramid. I presented two solutions: the PrintF and the For-loop solution.

int main() {
    char choice;
    char answer;

    do {
        printf("SOLUTIONS \n");
        printf("1. PrintF solution \n");
        printf("2. For-loop solution \n");
        printf("Choose the number of the solution you want: ");
        scanf(" %c", &choice);

        printf("\n");
        if (choice == '1') {
            firstSolution();
        } else if (choice == '2') {
            secondSolution();
        } else {
            printf("Invalid answer. Please try again!\n");
        }

        printf("\nDo you want to try again? (Y/N)\n");
        printf("Answer: ");
        scanf(" %c", &answer);
        printf("\n");
    } while (answer == 'Y' || answer == 'y');

    return 0;
}

void firstSolution() {
    printf("* \n");
    printf("** \n");
    printf("*** \n");
    printf("**** \n");
    printf("***** \n");
    printf("****** \n");
    printf("*** \n");
    printf("*** \n");
}

void secondSolution() {
    for(int i = 1; i <= 8; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 7 && j == 1) {
                j+=4;
            } else if (i == 8 && j == 1) {
                j+=5;
            }

            printf("*");
        }
        printf("\n");
    }
}

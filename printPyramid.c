#include <stdio.h>

// Code for printing Normal and Inverted Pyramid.

int main() {
    char answer;
    char pyramid;

    do {
        printf("PYRAMID PRINTER \n");
        printf("A. Normal Pyramid \n");
        printf("B. Inverted Pyramid \n");
        printf("Choose the pyramid you want: ");
        scanf(" %c", &pyramid);

        switch (pyramid) { // switch accepts lowercase and uppercase of A and B.
            case 'A':
            case 'a': // if case match run pyramidPrint function
                pyramidPrint('A'); // pass the value of A into the pyramidPrint function to print Normal Pyramid
                break;
            case 'B':
            case 'b':
                pyramidPrint('B'); // pass the value of B into the pyramidPrint function to print Inverted Pyramid
                break;
            default:
                printf("Invalid answer. Please try again!\n");
        }

        printf("\nDo you want to try again? (Y/N)\n");
        printf("Answer: ");
        scanf(" %c", &answer);
        printf("\n");
    } while (answer == 'Y' || answer == 'y');

    return 0;
}

//pyramidPrint function with variable pyramid as char type
void pyramidPrint(char pyramid) { // char pyramid holds the value of what pyramid to print which was passed in the pyramidPrint function
    char choice;

    printf("\nSOLUTIONS \n");
    printf("1. PrintF solution \n");
    printf("2. For-loop solution \n");
    printf("Choose the number of the solution you want: ");
    scanf(" %c", &choice);

    printf("\n");
    if (choice == '1') { // if true run printF solution for printing Pyramid
        if (pyramid == 'A') { // if true print normal pyramid else inverted pyramid
            printfNormalPyramid();
        } else {
            printfInvertedPyramid();
        }
    } else if (choice == '2') { // if true run for-loop solution for printing Pyramid
        if (pyramid == 'A') { // if true print normal pyramid else inverted pyramid
            forLoopNormalPyramid();
        } else {
            forLoopInvertedPyramid();
        }
    } else {
        printf("Invalid answer. Please try again!\n");
    }
}

// printF solution for printing normal Pyramid
void printfNormalPyramid() {
    printf("        * \n");
    printf("      * * * \n");
    printf("    * * * * * \n");
    printf("  * * * * * * * \n");
    printf("* * * * * * * * * \n");
}

// printF solution for printing inverted Pyramid
void printfInvertedPyramid() {
    printf("* * * * * * * * * \n");
    printf("  * * * * * * * \n");
    printf("    * * * * * \n");
    printf("      * * * \n");
    printf("        * \n");
}

// Reference for Pyramid for-loop Printing
// Link: https://www.programiz.com/c-programming/examples/pyramid-pattern

// for-loop solution for printing normal Pyramid
void forLoopNormalPyramid() {
    int space, j, rows = 5; // Rows of the pyramid is set to 5

    for (int i = 1, j = 0; i <= rows; ++i, j = 0) {
        for (space = 1; space <= rows-i; ++space) {
            printf("  ");
        }

        while(j != 2*i-1) { // k != 2 x i - 1
            printf("* ");
            ++j;
        }
        printf("\n");
    }
}

// for-loop solution for printing inverted Pyramid
void forLoopInvertedPyramid() {
    int i, j, space, rows = 5; // Rows of the pyramid is set to 5

    for (i = rows; i >= 1; --i) {
        for (space = 0; space < rows - i; ++space) {
            printf("  ");
        }
        for (j = i; j <= 2 * i - 1; ++j) {
            printf("* ");
        }
        for (j = 0; j < i - 1; ++j) {
            printf("* ");
        }
        printf("\n");
   }
}


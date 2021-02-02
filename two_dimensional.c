#include <stdio.h>

// Code for storing students grade in different classes in a multidimensional array.

int main() {
    int grades[3][30];
    int totalStudents = 0;
    int sizeOfStudents[2];
    char answer;


    printf("STUDENT GRADER FOR TEACHERS\n");

    for(int i = 0; i < 3; i++) {
        printf("\nClass %d \n", i+1);

        printf("Total number of students (max=30): ");
        scanf("%d", &totalStudents);

        sizeOfStudents[i] = totalStudents;

        for(int j = 0; j < totalStudents; j++) {
            printf("\nStudent %d \n", j+1);

            printf("Grade: ");
            scanf("%d", &grades[i][j]);
        }

    }

    printf("\nDo you want to print the grades of the students in the 3 classes?");
    printf("\nAnswer [y/n]: ");
    scanf(" %c", &answer);

    if (answer == 'y') {
        printf("\nPRINTING THE STUDENTS GRADES IN 3 CLASSESS");
        for (int i = 0; i < 3; i++) {
            printf("\n\nClass %d \n", i+1);

            for(int j = 0; j < sizeOfStudents[i]; j++) {
                printf("\nStudent %d \n", j+1);

                printf("Grade: %d", grades[i][j]);
            }
        }
        printf("\n");
    } else {
        printf("\nThe end. Thank you.\n");
    }


    return 0;
}

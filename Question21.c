#include <stdio.h>

// Code made for exam.

int main() {
    int quizSize, labSize, quizScore[100], labActivityScore[100], examScore[100], quizItems[100], labActivityItems[100], examItems[100];
    int totalQuizItems = 0;
    int totalLabItems = 0;
    int totalQuizScore = 0;
    int totalLabScore = 0;
    int examSize = 3;
    float quizAverage, labAverage, examTotal, totalPoints = 0.00;

    printf("Enter the total number of quizes: ");
    scanf("%d", &quizSize);
    for (int i = 1; i <= quizSize; i++) {
        printf("\nEnter Quiz %d score: ", i);
        scanf("%d",&quizScore[i]);
        printf("Enter total items: ");
        scanf("%d",&quizItems[i]);
    }

    printf("\nEnter the total number of lab activities: ");
    scanf("%d", &labSize);
    for (int i = 1; i <= labSize; i++) {
        printf("\nEnter Lab %d score: ", i);
        scanf("%d",&labActivityScore[i]);
        printf("Enter total items: ");
        scanf("%d",&labActivityItems[i]);
    }

    printf("\nMAJOR EXAMS\n");
    for (int i = 1; i <= examSize; i++) {
        printf("\nEnter Exam %d score: ", i);
        scanf("%d",&examScore[i]);
        printf("Enter total items: ");
        scanf("%d",&examItems[i]);
    }

    for(int i = 1; i <= quizSize; i++) {
      totalQuizScore += quizScore[i];
      totalQuizItems += quizItems[i];
    }

    for(int i = 1; i <= labSize; i++) {
      totalLabScore += labActivityScore[i];
      totalLabItems += labActivityItems[i];
    }

    for(int i = 1; i <= examSize; i++) {
      examTotal += (((examScore[i]/examItems[i])*100)*0.20);
    }

    quizAverage = ((totalQuizScore/totalQuizItems)*100)*0.10;
    labAverage = ((totalLabScore/totalLabItems)*100)*0.30;

    totalPoints = examTotal + labAverage + quizAverage;

    printf("\nYour Final Grade is: %.2f", totalPoints);

    return 0;
}

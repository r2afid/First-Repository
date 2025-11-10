#include <stdio.h>

int main() {
    float marks1, marks2, marks3, marks4, marks5, average;
    char grade;

    printf("Enter marks for 5 subjects (out of 100):\n");
    scanf("%f%f%f%f%f", &marks1, &marks2, &marks3, &marks4, &marks5);

    average = (marks1 + marks2 + marks3 + marks4 + marks5) / 5;

    if (average >= 90)
        grade = 'A';
    else if (average >= 80)
        grade = 'B';
    else if (average >= 70)
        grade = 'C';
    else if (average >= 60)
        grade = 'D';
    else
        grade = 'F';

    printf("\nAverage Marks: %.2f\n", average);
    printf("Grade: %c\n", grade);

    return 0;
}

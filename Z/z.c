#include <stdio.h>
#include <stdlib.h>

const int MAX_STUDENTS = 100;
const int MAX_NAME = 50;

struct Student {
    int id;
    char name[50];
    float grade;
};

int main() {
    int n;
    printf("Enter the number of students (1-%d): ", MAX_STUDENTS);
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter a number.\n");
        return 1;
    }

    if (n < 1 || n > MAX_STUDENTS) {
        printf("Invalid number of students. Enter 1-%d.\n", MAX_STUDENTS);
        return 1;
    }

    struct Student *students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\n--- Student %d ---\n", i + 1);
        printf("Enter ID: ");
        if (scanf("%d", &students[i].id) != 1) {
            printf("Invalid ID.\n");
            free(students);
            return 1;   
        }

        printf("Enter name: ");
        scanf(" %49[^\n]", students[i].name);

        printf("Enter grade (0-100): ");
        if (scanf("%f", &students[i].grade) != 1) {
            printf("Invalid grade.\n");
            free(students);
            return 1;
        }

        if (students[i].grade < 0 || students[i].grade > 100) {
            printf("Invalid grade. Grade must be between 0 and 100.\n");
            free(students);
            return 1;
        }
    }

    printf("\n========== STUDENT RECORDS ==========\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("ID : %d\n", students[i].id);
        printf("Name : %s\n", students[i].name);
        printf("Grade : %.2f\n", students[i].grade);
    }

    free(students);
    return 0;
}
#include <stdio.h>

#define MAX 100

int rollNo[MAX];
char name[MAX][50];
int presentDays[MAX];

int studentCount = 0;
int totalClasses = 0;

void addStudent() {
    if (studentCount >= MAX) {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter roll number: ");
    scanf("%d", &rollNo[studentCount]);

    printf("Enter student name: ");
    scanf(" %[^\n]", name[studentCount]);

    presentDays[studentCount] = 0;
    studentCount++;

    printf("Student added successfully.\n");
}

void displayStudents() {
    int i;

    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    printf("\nRoll No\tName\n");

    for (i = 0; i < studentCount; i++) {
        printf("%d\t%s\n", rollNo[i], name[i]);
    }
}

void markAttendance() {
    int i;
    char status;

    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    totalClasses++;

    printf("\nEnter P for Present or A for Absent\n");

    for (i = 0; i < studentCount; i++) {
        printf("%s: ", name[i]);
        scanf(" %c", &status);

        if (status == 'P' || status == 'p') {
            presentDays[i]++;
        }
    }

    printf("Attendance marked successfully.\n");
}

void showReport() {
    int i;
    float percentage;

    if (studentCount == 0) {
        printf("No students available.\n");
        return;
    }

    if (totalClasses == 0) {
        printf("No attendance marked yet.\n");
        return;
    }

    printf("\nAttendance Report\n");
    printf("Total Classes: %d\n\n", totalClasses);

    printf("Roll No\tName\t\tPresent\tPercentage\n");

    for (i = 0; i < studentCount; i++) {
        percentage = (presentDays[i] * 100.0) / totalClasses;

        printf("%d\t%-15s%d\t%.2f%%\n",
               rollNo[i],
               name[i],
               presentDays[i],
               percentage);
    }
}

void searchStudent() {
    int number;
    int i;

    printf("Enter roll number: ");
    scanf("%d", &number);

    for (i = 0; i < studentCount; i++) {
        if (rollNo[i] == number) {
            printf("\nStudent Found\n");
            printf("Roll Number: %d\n", rollNo[i]);
            printf("Name: %s\n", name[i]);
            printf("Present Days: %d\n", presentDays[i]);

            if (totalClasses > 0) {
                printf("Attendance: %.2f%%\n",
                       (presentDays[i] * 100.0) / totalClasses);
            }

            return;
        }
    }

    printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Attendance Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Mark Attendance\n");
        printf("4. Show Attendance Report\n");
        printf("5. Search Student\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                markAttendance();
                break;

            case 4:
                showReport();
                break;

            case 5:
                searchStudent();
                break;

            case 6:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}
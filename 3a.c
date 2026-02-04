#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50

// Structure to store student information
struct Student {
    int rollNo;
    char name[NAME_LEN];
    float marks;
};

// Function to safely read a string (avoids buffer overflow)
void readString(char *str, int size) {
    if (fgets(str, size, stdin) != NULL) {
        size_t len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0'; // Remove newline
        }
    }
}

// Function to input student details
void inputStudents(struct Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("\n--- Enter details for Student %d ---\n", i + 1);

        // Roll number input
        printf("Enter Roll Number: ");
        while (scanf("%d", &students[i].rollNo) != 1 || students[i].rollNo <= 0) {
            printf("Invalid input. Enter a positive integer for Roll Number: ");
            while (getchar() != '\n'); // Clear input buffer
        }
        while (getchar() != '\n'); // Clear buffer after number input

        // Name input
        printf("Enter Name: ");
        readString(students[i].name, NAME_LEN);
        while (strlen(students[i].name) == 0) {
            printf("Name cannot be empty. Enter Name: ");
            readString(students[i].name, NAME_LEN);
        }

        // Marks input
        printf("Enter Marks (0-100): ");
        while (scanf("%f", &students[i].marks) != 1 || students[i].marks < 0 || students[i].marks > 100) {
            printf("Invalid input. Enter Marks between 0 and 100: ");
            while (getchar() != '\n'); // Clear buffer
        }
        while (getchar() != '\n'); // Clear buffer
    }
}

// Function to display student details
void displayStudents(struct Student students[], int count) {
    printf("\n===== Student Records =====\n");
    printf("%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    printf("---------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int n;

    printf("Enter number of students (1-%d): ", MAX_STUDENTS);
    while (scanf("%d", &n) != 1 || n <= 0 || n > MAX_STUDENTS) {
        printf("Invalid input. Enter a number between 1 and %d: ", MAX_STUDENTS);
        while (getchar() != '\n'); // Clear buffer
    }
    while (getchar() != '\n'); // Clear buffer

    // Input and display student records
    inputStudents(students, n);
    displayStudents(students, n);

    return 0;
}

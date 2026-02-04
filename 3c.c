#include <stdio.h>
#include <string.h>

// Define a structure to hold student details
struct Student {
    char name[50];
    int age;
    float marks;
};

// Function to update student details using a pointer (call by reference)
void updateStudent(struct Student *s) {
    if (s == NULL) {
        printf("Invalid student pointer.\n");
        return;
    }

    // Modify the structure members directly
    printf("\n--- Updating Student Details ---\n");
    printf("Enter new name: ");
    scanf(" %[^\n]", s->name); // Read string with spaces
    printf("Enter new age: ");
    scanf("%d", &s->age);
    printf("Enter new marks: ");
    scanf("%f", &s->marks);
}

// Function to display student details
void displayStudent(const struct Student *s) {
    if (s == NULL) {
        printf("Invalid student pointer.\n");
        return;
    }

    printf("\n--- Student Details ---\n");
    printf("Name  : %s\n", s->name);
    printf("Age   : %d\n", s->age);
    printf("Marks : %.2f\n", s->marks);
}

int main() {
    struct Student stu;

    // Initial student details
    strcpy(stu.name, "John Doe");
    stu.age = 20;
    stu.marks = 85.5;

    // Display initial details
    displayStudent(&stu);

    // Pass structure by reference to update details
    updateStudent(&stu);

    // Display updated details
    displayStudent(&stu);

    return 0;
}

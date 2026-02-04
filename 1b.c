#include <stdio.h>
typedef struct {
   char name[50];
   int age;
   float gpa;
} Student;
int main() {
   Student s1 = {"Alice", 21, 8.9};
   printf("Name: %s\nAge: %d\nGPA: %.2f\n", s1.name, s1.age, s1.gpa);
   return 0;
}
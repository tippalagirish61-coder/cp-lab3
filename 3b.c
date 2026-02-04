#include <stdio.h>
struct Person {
   int age;
   float weight;
};
int main() {
   struct Person person1, *personPtr;
   // Assign pointer to the address of person1
   personPtr = &person1;
   // Input values using pointer
   printf("Enter age: ");
   scanf("%d", &personPtr->age);
   printf("Enter weight: ");
   scanf("%f", &personPtr->weight);
   // Display values using pointer
   printf("\nDisplaying:\n");
   printf("Age: %d\n", personPtr->age);
   printf("Weight: %.2f\n", personPtr->weight);
   return 0;
}
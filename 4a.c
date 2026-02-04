#include <stdio.h>
#include <stdlib.h>
int main() {
   int *ptr = (int *)malloc(5 * sizeof(int)); // Allocates heap memory
   if (ptr == NULL) {
       printf("Allocation Failed\n");
       exit(0);
   }
   for (int i = 0; i < 5; i++)
       ptr[i] = i + 1; // Initialize manually
   for (int i = 0; i < 5; i++)
       printf("%d ", ptr[i]);
   free(ptr); // Release heap memory
   return 0;
}
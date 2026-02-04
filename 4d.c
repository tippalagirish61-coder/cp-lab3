#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

int main() {
    int n, i;
    int *arr = NULL; // Pointer to hold dynamically allocated memory

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for n integers
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) { // Always check if malloc succeeded
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            free(arr); // Free before exiting
            return 1;
        }
    }

    // Display elements
    printf("You entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    arr = NULL; // Good practice to avoid dangling pointer

    printf("Memory successfully freed.\n");

    return 0;
}

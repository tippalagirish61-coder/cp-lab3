#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = NULL;
    int n, new_n;
    int i;

    // Step 1: Ask user for initial size
    printf("Enter initial number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size. Must be a positive integer.\n");
        return 1;
    }

    // Step 2: Allocate memory using malloc
    arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Step 3: Input elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input. Exiting.\n");
            free(arr);
            return 1;
        }
    }

    // Step 4: Ask for new size
    printf("Enter new number of elements: ");
    if (scanf("%d", &new_n) != 1 || new_n <= 0) {
        printf("Invalid size. Must be a positive integer.\n");
        free(arr);
        return 1;
    }

    // Step 5: Resize memory using realloc
    int *temp = realloc(arr, new_n * sizeof(int));
    if (temp == NULL) {
        printf("Memory reallocation failed. Keeping old memory.\n");
        free(arr);
        return 1;
    }
    arr = temp;

    // Step 6: If size increased, take new inputs
    if (new_n > n) {
        printf("Enter %d more integers:\n", new_n - n);
        for (i = n; i < new_n; i++) {
            if (scanf("%d", &arr[i]) != 1) {
                printf("Invalid input. Exiting.\n");
                free(arr);
                return 1;
            }
        }
    }

    // Step 7: Display final array
    printf("Final array elements:\n");
    for (i = 0; i < new_n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Step 8: Free memory
    free(arr);

    return 0;
}

#include <stdio.h>

struct student
{
    int id;
    char name[20];
    float marks;
};

int main()
{
    struct student S1 = {101, "AAA", 95.5};
    struct student S2 = {102, "BBB", 90};

    printf("Student 1 details:\n");
    printf("ID NO: %d\n", S1.id);
    printf("NAME : %s\n", S1.name);
    printf("Marks: %.2f\n\n", S1.marks);

    printf("Student 2 details:\n");
    printf("ID NO: %d\n", S2.id);
    printf("NAME : %s\n", S2.name);
    printf("Marks: %.2f\n", S2.marks);

    return 0;
}
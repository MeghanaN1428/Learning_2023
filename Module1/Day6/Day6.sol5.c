#include <stdio.h>

struct Student {
    char name[50];
    int age;
};

void swapFields(struct Student* student1, struct Student* student2) {
    // Swap name
    char tempName[50];
    strcpy(tempName, student1->name);
    strcpy(student1->name, student2->name);
    strcpy(student2->name, tempName);

    // Swap age
    int tempAge = student1->age;
    student1->age = student2->age;
    student2->age = tempAge;
}

int main() {
    struct Student student1 = { "John", 20 };
    struct Student student2 = { "Alice", 22 };

    printf("Before swapping:\n");
    printf("Student 1: Name = %s, Age = %d\n", student1.name, student1.age);
    printf("Student 2: Name = %s, Age = %d\n", student2.name, student2.age);

    swapFields(&student1, &student2);

    printf("\nAfter swapping:\n");
    printf("Student 1: Name = %s, Age = %d\n", student1.name, student1.age);
    printf("Student 2: Name = %s, Age = %d\n", student2.name, student2.age);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void displayArray(const struct Student* students, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }
}

int main() {
    struct Student students[10];  // Array size can be adjusted accordingly

    // Assuming the array of structures is initialized before displaying
    // You can use the previous code snippet to initialize the array

    displayArray(students, sizeof(students) / sizeof(students[0]));

    return 0;
}
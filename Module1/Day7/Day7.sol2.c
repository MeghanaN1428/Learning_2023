#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void initializeArray(struct Student* students, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main() {
    struct Student students[10];  // Array size can be adjusted accordingly

    initializeArray(students, sizeof(students) / sizeof(students[0]));

    // Print the initialized array of structures
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    return 0;
}
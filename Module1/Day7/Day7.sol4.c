#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

int compareMarksDesc(const void* a, const void* b) {
    const struct Student* studentA = (const struct Student*)a;
    const struct Student* studentB = (const struct Student*)b;

    if (studentA->marks < studentB->marks)
        return 1;
    else if (studentA->marks > studentB->marks)
        return -1;
    else
        return 0;
}

void sortArrayDescending(struct Student* students, int arraySize) {
    qsort(students, arraySize, sizeof(struct Student), compareMarksDesc);
}

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

    // Assuming the array of structures is initialized before sorting
    // You can use the previous code snippet to initialize the array

    sortArrayDescending(students, sizeof(students) / sizeof(students[0]));

    displayArray(students, sizeof(students) / sizeof(students[0]));

    return 0;
}
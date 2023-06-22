#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(const char* inputString, struct Student* students, int arraySize) {
    char rollnoStr[10];
    char name[20];
    char marksStr[10];

    // Copy the input string to avoid modifying the original string
    char inputCopy[100];
    strcpy(inputCopy, inputString);

    // Tokenize the input string
    char* token = strtok(inputCopy, " ");

    // Extract roll number
    if (token != NULL) {
        strcpy(rollnoStr, token);
        token = strtok(NULL, " ");
    }

    // Extract name
    if (token != NULL) {
        strcpy(name, token);
        token = strtok(NULL, " ");
    }

    // Extract marks
    if (token != NULL) {
        strcpy(marksStr, token);
    }

    // Convert strings to appropriate data types and initialize the array of structures
    for (int i = 0; i < arraySize; ++i) {
        students[i].rollno = atoi(rollnoStr);
        strcpy(students[i].name, name);
        students[i].marks = atof(marksStr);
    }
}

int main() {
    const char* inputString = "1001 Aron 100.00";
    struct Student students[10];  // Array size can be adjusted accordingly

    parseString(inputString, students, sizeof(students) / sizeof(students[0]));

    // Print the initialized array of structures
    for (int i = 0; i < sizeof(students) / sizeof(students[0]); ++i) {
        printf("Roll No: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    return 0;
}
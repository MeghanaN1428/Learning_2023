#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int marks;
} Student;

typedef struct {
    Student* students;
    int count;
} Class;

void add_student(Class* class, const char* name, int marks) {
    Student student;
    strcpy(student.name, name);
    student.marks = marks;

    class->students = realloc(class->students, (class->count + 1) * sizeof(Student));
    class->students[class->count] = student;
    class->count++;
}

float calculate_average_marks(const Class* class) {
    int total_marks = 0;
    for (int i = 0; i < class->count; i++) {
        total_marks += class->students[i].marks;
    }
    return (float)total_marks / class->count;
}

void print_students_above_below_average(const Class* class) {
    float average_marks = calculate_average_marks(class);
    printf("Average Marks: %.2f\n", average_marks);
    printf("Students scoring above average:\n");
    for (int i = 0; i < class->count; i++) {
        if (class->students[i].marks > average_marks) {
            printf("%s\n", class->students[i].name);
        }
    }
    printf("Students scoring below average:\n");
    for (int i = 0; i < class->count; i++) {
        if (class->students[i].marks < average_marks) {
            printf("%s\n", class->students[i].name);
        }
    }
}

int main() {
    Class class;
    class.students = NULL;
    class.count = 0;

    // Reading and adding students
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char name[50];
        int marks;
        printf("Enter the name of student %d: ", i + 1);
        scanf("%s", name);
        printf("Enter the marks of student %d: ", i + 1);
        scanf("%d", &marks);
        add_student(&class, name, marks);
    }

    // Computing and printing average marks and students above/below average12
    
    print_students_above_below_average(&class);

    // Freeing allocated memory
    free(class.students);

    return 0;
}
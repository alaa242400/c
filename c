#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define a struct to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grade;
} Student;

// Function to add a new student
void add_student(Student **students, int *student_count) {
    (*student_count)++;
    *students = realloc(*students, (*student_count) * sizeof(Student));

    if (*students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter the student's name: ");
    getchar(); // To consume the newline character left in the buffer
    fgets((*students)[*student_count - 1].name, MAX_NAME_LENGTH, stdin);
    (*students)[*student_count - 1].name[strcspn((*students)[*student_count - 1].name, "\n")] = 0; // Remove newline

    printf("Enter the student's age: ");
    scanf("%d", &(*students)[*student_count - 1].age);

    printf("Enter the student's grade: ");
    scanf("%f", &(*students)[*student_count - 1].grade);

    printf("Student added successfully!\n\n");
}

// Function to display all students
void display_students(Student *students, int student_count) {
    if (student_count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("Displaying all students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("Student %d:\n", i + 1);
        printf("  Name:  %s\n", students[i].name);
        printf("  Age:   %d\n", students[i].age);
        printf("  Grade: %.2f\n\n", students[i].grade);
    }
}

// Function to save students to a file
void save_students_to_file(Student *students, int student_count, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < student_count; i++) {
        fprintf(file, "%s,%d,%.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    fclose(file);
    printf("Students saved to file '%s'.\n", filename);
}

int main() {
    Student *students = NULL;
    int student_count = 0;
    int choice;

    while (1) {
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Display students\n");
        printf("3. Save students to file\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(&students, &student_count);
                break;
            case 2:
                display_students(students, student_count);
                break;
            case 3:
                save_students_to_file(students, student_count, "students.txt");
                break;
            case 4:
                free(students);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

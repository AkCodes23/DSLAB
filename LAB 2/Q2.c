#include <stdio.h>
#include <string.h>

struct Student
{
    char name[50];
    int rollNo;
    char grade;
};

void readStudent(struct Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Enter name, roll number, and grade for student %d: ", i + 1);
        scanf("%s %d %c", students[i].name, &students[i].rollNo, &students[i].grade);
    }
}

void displayStudents(struct Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Student %d: Name: %s, Roll No: %d, Grade: %c\n", i + 1, students[i].name, students[i].rollNo, students[i].grade);
    }
}

void sortStudentsByRollNo(struct Student *students, int n)
{
    struct Student temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (students[j].rollNo > students[j + 1].rollNo)
            {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    readStudent(students, n);

    printf("\nStudent information before sorting:\n");
    displayStudents(students, n);

    sortStudentsByRollNo(students, n);

    printf("\nStudent information after sorting by roll number:\n");
    displayStudents(students, n);

    return 0;
}

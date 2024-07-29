#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    char name[50];
    int rollNo;
    char grade;
    char branch[50];
};

void writeStudentRecords(struct Student *students, int n, const char *filename)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        fprintf(file, "%s %d %c %s\n", students[i].name, students[i].rollNo, students[i].grade, students[i].branch);
    }

    fclose(file);
}

void storeBranchWise(const char *filename)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        return;
    }

    struct Student student;
    char line[200];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "%s %d %c %s", student.name, &student.rollNo, &student.grade, student.branch);

        char branchFilename[100];
        sprintf(branchFilename, "%s.txt", student.branch);

        FILE *branchFile = fopen(branchFilename, "a");
        if (branchFile == NULL)
        {
            perror("Failed to open branch file");
            continue;
        }

        fprintf(branchFile, "%s %d %c %s\n", student.name, student.rollNo, student.grade, student.branch);
        fclose(branchFile);
    }

    fclose(file);
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter name, roll number, grade, and branch for student %d: ", i + 1);
        scanf("%s %d %c %s", students[i].name, &students[i].rollNo, &students[i].grade, students[i].branch);
    }

    const char *filename = "students.txt";
    writeStudentRecords(students, n, filename);
    storeBranchWise(filename);

    printf("Student records have been written to %s and stored branch-wise in separate files.\n", filename);

    return 0;
}

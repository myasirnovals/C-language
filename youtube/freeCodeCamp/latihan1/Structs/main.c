#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[50];
    char major[50];
    int age;
    double gpa;
};

int main()
{
    struct Student student1;
    student1.age = 18;
    student1.gpa = 4.5;
    strcpy(student1.name, "Muhamad Yasir Noval");
    strcpy(student1.major, "Teknik Informatika");

    struct Student student2;
    student2.age = 20;
    student2.gpa = 4.9;
    strcpy(student2.name, "Pam");
    strcpy(student2.major, "Arts");

    printf("%.2f\n", student1.gpa);
    printf("%s\n", student1.name);

    return 0;
}

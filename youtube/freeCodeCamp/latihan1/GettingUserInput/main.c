#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
        int age;
        printf("Enter your age: ");
        scanf("%d", &age);
        printf("You are %d years old", age);

        double gpa;
        printf("Enter your gpa: ");
        scanf("%lf", &gpa);
        printf("your gpa is %f", gpa);

        char grade;
        printf("Enter your grade");
        scanf("%c", &grade);
        printf("Your grade is %c", grade);
    */

    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    printf("Your name is %s", name);

    return 0;
}

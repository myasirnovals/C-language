#include <stdio.h>
#include <stdlib.h>

int main()
{
    sayHi("Yasir", 18);
    sayHi("Tom", 27);
    sayHi("Oscar", 30);

    return 0;
}

void sayHi(char name[], int age)
{
    printf("Hello %s, you are %d\n", name, age);
}

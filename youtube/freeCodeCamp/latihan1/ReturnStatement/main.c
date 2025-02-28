#include <stdio.h>
#include <stdlib.h>

double cube(double num);

int main() {
    printf("Answer: %f", cube(3.0));

    return 0;
}

double cube(double num) {
    return num * num * num;
}

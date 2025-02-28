#include <stdio.h>
 
int main() {
    int angka[5] = {1, 8, 5, 3, 7};
    
    int x = 8;
    int panjangArray = sizeof angka / sizeof angka[0];
    int isHasElement = 0;
    
    for (int i = 0; i < panjangArray; i++) {
        if (angka[i] == x) {
            isHasElement = 1;
            break;
        }
    }
    
    if (isHasElement) {
        printf("%d ada dalam array.\n", x);
    } else {
        printf("%d tidak ada dalam array.\n", x);
    }
}

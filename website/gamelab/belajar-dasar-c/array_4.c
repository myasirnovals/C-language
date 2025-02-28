#include <stdio.h>

void main(){
    int angka[5] = {1, 8, 5, 3, 7};
    
    int panjang = sizeof(angka) / sizeof(int);
    printf("Panjang array adalah: %i\n", panjang);
}

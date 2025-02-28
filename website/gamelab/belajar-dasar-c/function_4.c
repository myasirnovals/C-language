#include <stdio.h>

int jumlah(int a, int b){
    return a + b;
}

int kurang(int a, int b){
    return a - b;
}

int kali(int a, int b){
    return a * b;
}

int bagi(int a, int b){
    return a / b;
}


void main() {
    int a = 20;
    int b = 4;
    int hasil;

    hasil = jumlah(a, b);
    printf("%i + %i = %i \n", a, b, hasil);
 
    hasil = kurang(a, b);
    printf("%i - %i = %i \n", a, b, hasil);

    hasil = kali(a, b);
    printf("%i * %i = %i \n", a, b, hasil);

    hasil = bagi(a, b);
    printf("%i / %i = %i \n", a, b, hasil);
}

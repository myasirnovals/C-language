#include <stdio.h>

int main(void) {
    int a = 7;
    int b = 17;
    int c = 27;
    
    int hasil;
    
    hasil = (a>b) && (a>c);
    
    printf("(a>b) && (a>c) adalah %d \n", hasil);
}

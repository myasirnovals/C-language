#include <stdio.h>

int main(void) {
   int a = 22;
   int b = 5;
   
   int hasil;
   
   hasil = a + b;
   printf("Hasil dari a + b = %i \n", hasil);
   
   hasil = a - b;
   printf("Hasil dari a – b = %i \n", hasil);
   
   hasil = a * b;
   printf("Hasil dari a * b = %i \n", hasil);
   
   hasil = a / b;
   printf("Hasil dari a / b = %i \n", hasil);
   
   hasil = a % b;
   printf("Hasil dari a modulus b = %i \n", hasil);
}

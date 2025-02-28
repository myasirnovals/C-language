#include <stdio.h>

void main(){
    int hari = 12;
    
    switch (hari) {
        case 1:
            printf("Nilai hari = 1\n");
            printf("Maka, hari = Senin");
            break;
        case 2:
            printf("Nilai hari = 2\n");
            printf("Maka, hari = Selasa");
            break;
        case 3:
            printf("Nilai hari = 3\n");
            printf("Maka, hari = Rabu");
            break;
        case 4:
            printf("Nilai hari = 4\n");
            printf("Maka, hari = Kamis");
            break;
        case 5:
            printf("Nilai hari = 5\n");
            printf("Maka, hari = Jumat");
            break;
        case 6:
            printf("Nilai hari = 6\n");
            printf("Maka, hari = Sabtu");
            break;
        case 7:
            printf("Nilai hari = 7\n");
            printf("Maka, hari = Minggu");
            break;
        default:
            printf("Nilai hari = %i\n", hari);
            printf("Maka, hari = tidak valid");
    }

}

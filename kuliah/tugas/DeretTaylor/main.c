#include <stdio.h>
#include <time.h>

double e (int x, int n) {
    // Kamus
    static double pow, fact;
    double result;

    // Algoritma
    pow = 1;
    fact = 1;

    if (n == 0) {
        return 1;
    } else {
        result = e(x, n-1);
        pow = pow * x;
        fact = fact * n;

        return result + pow / fact;
    }
}

// double e(int x, int n) {
//     // Kamus
//     double pow = 1;
//     double fact = 1;
//     double result = 1;
//
//     // Algoritma
//     for (int i = 1; i <= n; i++) {
//         pow = pow * x;
//         fact = fact * i;
//         result += pow / fact;
//     }
//
//     return result;
// }

int main(void) {
    clock_t start_time, end_time;
    double execution_time;

    int i = 1;

    while (i <= 10) {
        // waktu mulai
        start_time = clock();

        // proses looping
        printf("%lf \n", e(1,5));

        // waktu selesai
        end_time = clock();

        // hitung waktu eksekusi
        execution_time = (double) (end_time - start_time) / CLOCKS_PER_SEC * 1000;

        // tampilkan waktu
        printf("Time: %f milidetik \n", execution_time);

        i++;
    }

    return 0;
}

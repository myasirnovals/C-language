#include <stdio.h>

int main() {
    int jam = 22;

    if (jam < 10) {
      printf("Selamat pagi");
    } else if (jam < 14) {
      printf("Selamat siang");
    } else if (jam < 18) {
      printf("Selamat sore");
    } else {
      printf("Selamat malam");
    }
}

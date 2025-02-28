#include <stdio.h>
#include "boolean.h"

#define nMax 10

typedef struct {
    long int pin;
    long int saldo;
} Nasabah;

typedef struct {
    int Ti[nMax + 1];
    long int Tl[nMax + 1];
    Nasabah Tn[nMax + 1];
    int neff;
} Tab;

void CreateTab(Tab *T);

void AddElmNas(Tab *T, long int x, long int y);

void AddElmLi(Tab *T, long int x);

void CekPin(Tab T, long int x, int *y);

void TarikTunai(Tab *T, long int x);

boolean CukupUang(long int x);

boolean KemExit(int x);

int main() {
    //kamus
    boolean A, B;
    int n, i, idx;
    long int s, p, k, PinUser;
    long int ATMTOT, Tsaldo;
    Tab Nas, JumUang;

    CreateTab(&Nas);
    CreateTab(&JumUang);
    ATMTOT = 0;
    idx = 0;

    printf("=============== REGRISTASI ===============");
    printf("\n\nMasukan pin dan saldo Nasabah\n");
    printf("\nSilahkan ketik 999 untuk menghentikan input\n");

    printf("\nMasukan pin Nasabah : ");
    scanf("%ld", &p);
    printf("\nMasukan Saldo Nasabah : ");
    scanf("%ld", &s);

    while (p != 999 && s != 999) {
        AddElmNas(&Nas, p, s);
        printf("\nMasukan pin Nasabah : ");
        scanf("%ld", &p);
        printf("\nMasukan Saldo Nasabah : ");
        scanf("%ld", &s);
    }


    printf("\n\n1.LANJUTKAN KE ATM");
    printf("\n2.EXIT");
    printf("\n\nPILIH OPSI : ");
    scanf("%d", &n);
    B = KemExit(n);


    while (B) {
        printf("========================= ATM SEDERHANA =========================");
        printf("\n\n");
        printf("MASUKAN PIN : ");
        scanf("%ld", &PinUser);
        CekPin(Nas, PinUser, &idx);
        if (idx > 0) {
            A = true;
            B = false;
        } else if (idx == -1) {
            printf("=========================== ADMIN ===========================");
            printf("\n\n");

            printf("Masukan saldo Atm perlembar");

            printf("Masukan Jumlah Lembar Seratus Ribu : ");
            scanf("%ld", &k);
            AddElmLi(&JumUang, k);
            printf("Masukan Jumlah Lembar Lima Puluh Ribu : ");
            scanf("%ld", &k);
            AddElmLi(&JumUang, k);
            printf("Masukan Jumlah Lembar Dua Puluh Ribu : ");
            scanf("%ld", &k);
            AddElmLi(&JumUang, k);
            printf("Masukan Jumlah Lembar Sepuluh Ribu :");
            scanf("%ld", &k);
            AddElmLi(&JumUang, k);
            printf("Masukan Jumlah Lembar Lima Ribu : ");
            scanf("%ld", &k);
            AddElmLi(&JumUang, k);
            printf("\n\n");
            printf("\n\n1.LANJUTKAN KE ATM");
            printf("\n2.EXIT");
            printf("\n\nPILIH OPSI : ");
            scanf("%d", &n);
            A = KemExit(n);
            B = false;
        } else {
            printf("========================= ATM SEDERHANA =========================");
            printf("\n\n");
            printf("PIN ANDA SALAH");
            printf("\n1.KEMBALI");
            printf("\n2.EXIT");
            printf("\n\nMASUKAN OPSI : ");
            scanf("%d", &n);
            B = KemExit(n);
            A = false;
        }

        while (A) {
            for (i = 1; i <= JumUang.neff; i++) {
                ATMTOT = ATMTOT + JumUang.Tl[i];
            }

            printf("========================= ATM SEDERHANA =========================");
            printf("\n\n");
            printf("\n1.TARIK TUNAI");
            printf("\n2.CEK SALDO ATM");
            printf("\n3.CEK SALDO");
            printf("\n4.KEMBALI");
            printf("\n5.EXIT");
            printf("\n\nMASUKAN OPSI : ");
            scanf("%d", &n);
            if (n == 1) {
                printf("========================= ATM SEDERHANA =========================");
                printf("\n========================== TARIK TUNAI ==========================");
                printf("\n\n");
                printf("MOHON MASUKAN KELIPATAN 5.000");
                printf("\nMASUKAN SALDO YANG AKAN DI TARIK : ");
                scanf("%ld", &Tsaldo);
                if (Tsaldo % 5000 == 0) {
                    if (Tsaldo <= ATMTOT) {
                        if (Tsaldo <= Nas.Tn[idx].saldo) {
                            Nas.Tn[idx].saldo = Nas.Tn[idx].saldo - Tsaldo;
                            TarikTunai(&JumUang, Tsaldo);
                            printf("\n\nLembar uang yang keluar\n");
                            printf("\nLembar 100.000 : %d", JumUang.Ti[1]);
                            printf("\nLembar 50.000  : %d", JumUang.Ti[2]);
                            printf("\nLembar 20.000  : %d", JumUang.Ti[3]);
                            printf("\nLembar 10.000  : %d", JumUang.Ti[4]);
                            printf("\nLembar 5.000   : %d", JumUang.Ti[5]);
                            printf("\n\n");

                            printf("\n1.KEMBALI");
                            printf("\n2.EXIT");
                            printf("\n\nMASUKAN OPSI : ");
                            scanf("%d", &n);
                            A = KemExit(n);
                        } else {
                            printf("========================= ATM SEDERHANA =========================");
                            printf("\n\n");
                            printf("SALDO ANDA KURANG\n");
                            printf("\n1.KEMBALI");
                            printf("\n2.EXIT");
                            printf("\n\nMASUKAN OPSI : ");
                            scanf("%d", &n);
                            A = KemExit(n);
                        }
                    } else {
                        printf("========================= ATM SEDERHANA =========================");
                        printf("\n\n");
                        printf("MOHON MAAF SALDO PADA ATM KURANG\n");
                        printf("\n1.KEMBALI");
                        printf("\n2.EXIT");
                        printf("\n\nMASUKAN OPSI : ");
                        scanf("%d", &n);
                        A = KemExit(n);
                    }
                } else {
                    printf("========================= ATM SEDERHANA =========================");
                    printf("\n\n");
                    printf("INVALID SALDO YANG DIMASUKAN BUKAN KELIAPATAN 5.000\n");
                    printf("\n1.KEMBALI");
                    printf("\n2.EXIT");
                    printf("\n\nMASUKAN OPSI : ");
                    scanf("%d", &n);
                    A = KemExit(n);
                }
            } else if (n == 2) {
                printf("========================= ATM SEDERHANA =========================");
                printf("\n\n");
                printf("----------------------------------------------");
                printf("\nSALDO ATM\n");
                printf("\nSaldo ATM 100.000 : %ld", JumUang.Tl[1]);
                printf("\nSaldo ATM 50.000  : %ld", JumUang.Tl[2]);
                printf("\nSaldo ATM 20.000  : %ld", JumUang.Tl[3]);
                printf("\nSaldo ATM 10.000  : %ld", JumUang.Tl[4]);
                printf("\nSaldo ATM 5.000   : %ld", JumUang.Tl[5]);
                printf("\n----------------------------------------------");
                printf("\n\n");
                printf("\n1.KEMBALI");
                printf("\n2.EXIT");
                printf("\n\nMASUKAN OPSI : ");
                scanf("%d", &n);
                A = KemExit(n);
            } else if (n == 3) {
                printf("========================= ATM SEDERHANA =========================");
                printf("\n=========================== CEK SALDO ===========================");
                printf("\n\n");
                printf("SALDO ANDA SAAT INI :\n");
                printf("%ld", Nas.Tn[idx].saldo);
                printf("\n1.KEMBALI");
                printf("\n2.EXIT");
                printf("\n\nMASUKAN OPSI : ");
                scanf("%d", &n);
                A = KemExit(n);
            } else if (n == 4) {
                B = true;
                A = false;
            } else {
                B = false;
                A = B;
            }
        }
    }


    return 0;
}


void CreateTab(Tab *T) {
    (*T).neff = 0;
}

void AddElmNas(Tab *T, long int x, long int y) {
    if ((*T).neff < nMax) {
        (*T).neff = (*T).neff + 1;
        (*T).Tn[(*T).neff].pin = x;
        (*T).Tn[(*T).neff].saldo = y;
    }
}

void AddElmLi(Tab *T, long int x) {
    if ((*T).neff < nMax) {
        (*T).neff++;
        (*T).Tl[(*T).neff] = x;
    }
}

void CekPin(Tab T, long int x, int *y) {
    //kamus lokal
    int i;

    for (i = 1; i <= T.neff; i++) {
        if (x == T.Tn[i].pin) {
            *y = i;
            break;
        } else if (x == 999) {
            *y = -1;
            break;
        }
    }
}

void TarikTunai(Tab *T, long int x) {
    //kamus lokal
    int i;
    boolean A;

    A = true;
    for (i = 1; i <= (*T).neff; i++) {
        (*T).Ti[i] = 0;
    }
    while (A) {
        if (CukupUang((*T).Tl[1]) && x >= 100000) {
            x = x - 100000;
            (*T).Tl[1] = (*T).Tl[1] - 100000;
            (*T).Ti[1] = (*T).Ti[1] + 1;
        } else if (CukupUang((*T).Tl[2]) && x >= 50000) {
            x = x - 50000;
            (*T).Tl[2] = (*T).Tl[2] - 50000;
            (*T).Ti[2] = (*T).Ti[2] + 1;
        } else if (CukupUang((*T).Tl[3]) && x >= 20000) {
            x = x - 20000;
            (*T).Tl[3] = (*T).Tl[3] - 20000;
            (*T).Ti[3] = (*T).Ti[3] + 1;
        } else if (CukupUang((*T).Tl[4]) && x >= 10000) {
            x = x - 10000;
            (*T).Tl[4] = (*T).Tl[4] - 10000;
            (*T).Ti[4] = (*T).Ti[4] + 1;
        } else if (CukupUang((*T).Tl[5]) && x >= 5000) {
            x = x - 5000;
            (*T).Tl[5] = (*T).Tl[5] - 5000;
            (*T).Ti[5] = (*T).Ti[5] + 1;
        } else if (x < 5000) {
            A = false;
        }
    }
}

boolean KemExit(int x) {
    //kamus lokal
    boolean pass;
    if (x == 1) {
        pass = true;
    } else {
        pass = false;
    }

    return pass;
}

boolean CukupUang(long int x) {
    //kamus lokal
    boolean cukup;

    if (x > 0) {
        cukup = true;
    } else {
        cukup = false;
    }

    return cukup;
}

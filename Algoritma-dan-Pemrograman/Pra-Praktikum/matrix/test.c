#include <stdio.h>

int main() {
    int X = 10;      // Kita membuat variabel biasa (Loker 101 berisi angka 10)
    int *M;          // Kita mendeklarasikan variabel pointer bernama M

    M = &X;          // M menyimpan alamat memori dari X (tanda '&' berarti "alamat dari")

    printf("Nilai X awal: %d\n", &X);
    printf("Nilai yang ditunjuk oleh M (*M): %d\n", &*M); 

    // Sekarang kita ubah nilai di dalam loker melalui pointernya
    *M = 99;         // "Pergi ke alamat M, lalu ganti isinya menjadi 99"

    printf("\n--- Setelah *M diubah ---\n");
    printf("Nilai X sekarang: %d\n", X);

    return 0;
}
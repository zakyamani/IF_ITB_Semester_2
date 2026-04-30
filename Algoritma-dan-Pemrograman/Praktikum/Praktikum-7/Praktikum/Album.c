#include "Album.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

void CreateAlbum(Album *A, int capacity){
    A->capacity = capacity;
    A->nEff = 0;
    A->buffer = (ElType *) malloc (A->capacity * sizeof(ElType));
}
/* I.S. A sembarang, capacity > 0 */
/* F.S. Album A terbentuk */

void DeallocateAlbum(Album *A){
    A->nEff = 0;
    A->capacity = 0;
    A->buffer = (ElType *) realloc (A->buffer, A->capacity * sizeof(ElType));
}
/* I.S. A terdefinisi */
/* F.S. Memori dibebaskan */

boolean IsEmpty(Album A){
    return (A.nEff == 0);
}
/* Mengembalikan true jika nEff == 0 */

boolean IsFull(Album A){
    return (A.nEff == A.capacity);
}
/* Mengembalikan true jika nEff == capacity */

void ExpandAlbum(Album *A, int num){
    A->capacity += num;
    A->buffer = (ElType *) realloc (A->buffer, A->capacity * sizeof(ElType));
}
/* I.S. A terdefinisi, num > 0 */
/* F.S. Kapasitas bertambah sebanyak num. */

void SplitAndSwap(Album *A, int pivot){
    ElType sementara[pivot + 1];
    for(int i=0; i<=pivot; i++){
        sementara[i] = A->buffer[i];
    }
    A->nEff -= (pivot + 1);
    for(int i=0; i<A->nEff; i++){
        A->buffer[i] = A->buffer[i+pivot+1];
    }
    for(int i=0; i<=pivot; i++){
        A->buffer[A->nEff + i] = sementara[i];
    }
    A->nEff += (pivot + 1);
}
/* Memotong album di indeks pivot, lalu menukar blok kiri dan kanan.
   Contoh: [1,2,3,4,5], pivot 1 (nilai 2) -> Potongan [1,2] dan [3,4,5]
   Hasil: [3,4,5,1,2]
   I.S. A terdefinisi, 0 <= pivot < nEff-1 */

void InjectList(Album *A1, Album A2, int idx){
    for(int i=idx; i<idx+A2.nEff; i++){
        A1->buffer[i] = A2.buffer[i - idx];
    }
    A1->nEff = idx+A2.nEff;
    if(A1->nEff > A1->capacity){
        A1->capacity = A1->nEff;
    }
    A1->buffer = (ElType *) realloc (A1->buffer, A1->capacity * sizeof(ElType));


}
/* Menyisipkan seluruh isi Album A2 ke dalam Album A1 mulai posisi idx
   Kapasitas A1 harus otomatis bertambah jika tidak muat
   I.S. A1, A2 terdefinisi, 0 <= idx <= A1.nEff */

void PrintAlbum(Album A){
    for(int i=0; i<A.nEff; i++){
        printf("%d", A.buffer[i]);
    }
    printf("\n");
}
/* I.S. A terdefinisi */
/* F.S. Cetak isi buffer album ke layar (akhiri \n) */
/* Contoh: [1,2,3]
Maka outputnya adalah -> 123 */

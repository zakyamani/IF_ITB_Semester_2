#include "boolean.h"
#include "ListAnomali.h"
#include <stdio.h>

/* Indeks yang digunakan [IDX_MIN..MAX_CAPACITY - 1] */
/* Jika T adalah ListAnomali, */
/* Maka cara akses:
 * T.nEff untuk mengetahui banyaknya elemen saat ini
 * T.buffer untuk mengakses seluruh nilai elemen list
 * T.buffer[i] untuk mengakses elemen ke-i */
/* Definisi :
 * list kosong: T.nEff = 0
 * list penuh: T.nEff = MAX_CAPACITY
 * Definisi elemen pertama : T.buffer[i] dengan i=IDX_MIN
 * Definisi elemen terakhir yang terdefinisi: T.buffer[i] dengan i=(T.nEff - 1)*/

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong */
void CreateListAnomali(ListAnomali *T){
    T->nEff = 0;
    T->buffer[MAX_CAPACITY];
}
/* I.S. T sembarang */
/* F.S. Terbentuk list T kosong dengan kapasitas MAX_CAPACITY */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int countAnomaly(ListAnomali T){
    return T.nEff;
}
/* Mengirimkan banyaknya anomali efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Daya tampung anomali list *** */
int maxNbAnomaly(ListAnomali T){
    return MAX_CAPACITY;
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh list (MAX_CAPACITY) */

/* ********** Test Indeks yang valid ********** */
boolean isIdxEff(ListAnomali T, IdxType i){
    return ((i >= 0) && (i < T.nEff));
}
/* Prekondisi : List T sembarang (bisa kosong atau bisa terisi), i sembarang */
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list yaitu antara indeks pertama dan indeks nEff */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListAnomali T){
    return (T.nEff == 0);
}
/* Mengirimkan true jika list T kosong, mengirimkan false jika tidak */

/* *** Test list penuh *** */
boolean isFull(ListAnomali T){
    return (T.nEff == MAX_CAPACITY);
}
/* Mengirimkan true jika list T penuh, mengirimkan false jika tidak */

/* ********** Selektor INDEKS ********** */
IdxType getFirstIdx(ListAnomali T){
    if(T.nEff == 0){
        return IDX_UNDEF;
    }
    return IDX_MIN;
}
/* Prekondisi : List T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen pertama yaitu IDX_MIN */
/* Jika list kosong, return IDX_UNDEF */

IdxType getLastIndex(ListAnomali T){
    if(T.nEff == 0){
        return IDX_UNDEF;
    }
    return (T.nEff - 1);
}
/* Prekondisi : List T sembarang (bisa kosong atau bisa terisi) */
/* Mengirimkan indeks elemen efektif terakhir */
/* Jika list kosong, return IDX_UNDEF */

/* *** Menghasilkan sebuah elemen *** */
ElType getAnomalyAtIdx(ListAnomali T, IdxType i){
    if((T.nEff == 0) || (i < 0) || (i >= T.nEff) ){
        return ELEM_UNDEF;
    }
    return T.buffer[i];
}
/* Prekondisi : list T sembarang (bisa kosong atau bisa terisi), i mungkin tidak valid*/
/* Mengirimkan elemen list yang ke-i */
/* Jika list kosong atau indeks tidak valid, return ELEM_UNDEF */

/* ********** INPUT/OUTPUT ********** */
void printAnomalies(ListAnomali T){
    if(T.nEff == 0){
        printf("LIST KOSONG\n");
    }else{
        printf("[");
        for(int i=0; i<T.nEff-1; i++){
            printf("%d,", T.buffer[i]);
        }
        printf("%d]\n", T.buffer[T.nEff-1]);
    }

}
/* Prekondisi: T boleh kosong */
/* Menuliskan isi list dengan traversal */
/* Tampilkan list dalam kurung siku dalam bentuk [<Elemen-1>,<Elemen-2>,<Elemen-3>,..<Elemen-nEff>], seperti [1,2,3], dan diakhiri newline */
/* Perhatikan bahwa tidak ada spasi dalam output */
/* Jika T kosong : Hanya menulis "LIST KOSONG" dan diakhiri newline */

/* ********** Operasi Dasar ********** */
void setAt(ListAnomali *T, ElType v, IdxType i){
    if((i >= 0) && (i < T->nEff)){
        T->buffer[i] = v;
    }
}
/* Prekondisi : list T terisi, indeks i bisa tidak valid */
/* Mengganti elemen T pada indeks i menjadi v */

void insertAt(ListAnomali *T, ElType v, IdxType i){
    if((i >= 0) && (i <= T->nEff)){
        for(int j=T->nEff - 1; j >= i; j--){
            T->buffer[j + 1] = T->buffer[j];
        }
        T->buffer[i] = v;
        T->nEff++;
    }
}
/* Prekondisi : list T sembarang (bisa kosong atau bisa terisi) dan TIDAK PENUH, indeks i bisa tidak valid */
/* Menyelipkan elemen v ke T di indeks i */
/* Semua elemen setelah indeks digeser ke kanan */

void deleteAt(ListAnomali *T, IdxType i, ElType *v){
    if((i >= 0) && (i < T->nEff) && (T->nEff > 0)){
        *v = T->buffer[i];
        for(int j=i+1; j<T->nEff; j++){
            T->buffer[j-1] = T->buffer[j];
        }
        T->nEff--;
    }
}
/* Prekondisi : list T sembarang (bisa kosong atau bisa terisi) dan indeks i bisa tidak valid */
/* Menghapus ElType pada indeks i */
/* Semua elemen setelahnya DIGESER ke kiri */
/* Elemen yang dihapus disimpan pada v */

/* ********** Anomaly Operations ********** */
ElType highestAnomaly(ListAnomali T){
    ElType result = T.buffer[0];
    for(int i=1; i<T.nEff; i++){
        if(result < T.buffer[i]){
            result = T.buffer[i];
        }
    }
    return result;
}
/* Prekondisi : list T tidak kosong */
/* Mengirimkan nilai anomali tertinggi di list */

ElType lowestAnomaly(ListAnomali T){
    ElType result = T.buffer[0];
    for(int i=0; i<T.nEff; i++){
        if(result > T.buffer[i]){
            result = T.buffer[i];
        }
    }
    return result;
}
/* Prekondisi : list T tidak kosong */
/* Mengirimkan nilai anomali terendah di list */

void shiftRightByK(ListAnomali *T, int K){
    for(int i=T->nEff - 1; i>=0; i--){
        T->buffer[i + K] = T->buffer[i];
    }
    for(int i=0; i<K; i++){
        T->buffer[i] = ELEM_UNDEF;
    }
    T->nEff += K;
}
/* Prekondisi : list T tidak kosong dan (last_idx + K) < max_anomaly_count */
/* Menggeser seluruh elemen ke kanan sebanyak K kali */
/* Gunakan ELEM_UNDEF sebagai elemen baru di kiri */
/* Contoh, untuk K = 2, maka [1,2,3] menjadi [ELEM_UNDEF,ELEM_UNDEF,1,2,3]*/

void reverseList(ListAnomali *T){
    for(int i=0; i<T->nEff/2; i++){
        ElType sementara = T->buffer[i];
        T->buffer[i] = T->buffer[T->nEff - i - 1];
        T->buffer[T->nEff - i - 1] = sementara;
    }
}
/* Prekondisi : list T tidak kosong */
/* Membalikkan list T */
/* Contoh, untuk untuk list [1,2,3], maka menjadi [3,2,1] */

void extractExtremeAnomalies(ListAnomali *T_src, ListAnomali *T_dst){
    int newSize = 0;
    for(int i=0; i<T_src->nEff; i++){
        if((T_src->buffer[i] >= 100) || (T_src->buffer[i] <= -100)){
            deleteAt(T_src, i, &(T_dst->buffer[newSize]));
            newSize++;
            i--;
        }
    }
    if(newSize > 0){
        T_dst->nEff = newSize;
    }
}
/* Prekondisi : list T_src dan T_dst sembarang (bisa kosong atau bisa terisi) */
/* MEMINDAHKAN elemen anomali ekstrim dari T_src ke T_dst secara urut dari kiri ke kanan */
/* Anomali ekstrem didefinisikan sebagai anomali dengan nilai <= -100 dan >= 100*/
/* Contoh: */
/* untuk untuk list T_src [0, 100, -200], maka h:*/
/*     T_src akan berisi [0]  */
/*     T_dst akan berisi [100, -200]  */
/* Jika T_dst tidak kosong dan ada elemen yang bisa diekstrak : semua nilai T_dst dihilangkan (List di overwrite) */
/* Jika T_dst tidak kosong dan tidak ada elemen yang bisa diekstrak : jangan ubah T_dst */

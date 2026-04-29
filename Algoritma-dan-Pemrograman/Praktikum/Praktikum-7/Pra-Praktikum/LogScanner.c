#include "boolean.h"
#include "LogScanner.h"
#include <stdlib.h>
#include <stdio.h>

void CreateLogScanner(LogScanner *l, int capacity){
    l->capacity = capacity;
    l->nEff = 0;
    l->buffer = (LogItem *) malloc(capacity * sizeof(LogItem));
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list l kosong dengan kapasitas capacity */

void DealokasiLogScanner(LogScanner *l){    
    free(l->buffer);
    l->capacity = 0;
    l->nEff = 0;
}
/* I.S. l terdefinisi */
/* F.S. List l dikembalikan ke sistem, l.ca.pacity=0, l.nEff=0 */

boolean IsEmpty(LogScanner l){
    return(l.nEff == 0);
}
/* Mengirimkan true jika list l kosong, false jika tidak */

boolean IsFull(LogScanner l){
    return (l.nEff == l.capacity);
}
/* Mengirimkan true jika list l penuh, false jika tidak */

void ExpandList(LogScanner *l){
    l->capacity *= 2;
    l->buffer = (LogItem *) realloc(l->buffer, l->capacity * sizeof(LogItem));
}
/* Melipatgandakan kapasitas list (capacity * 2) */

void ShrinkToFit(LogScanner *l){
    if(l->nEff == 0){
        l->capacity = INITIAL_CAPACITY;
    }else{
        l->capacity = l->nEff;
    }
    
    l->buffer = (LogItem *) realloc(l->buffer, l->capacity * sizeof(LogItem));
}
/* Mengecilkan kapasitas list agar sama dengan nEff */
/* Jika nEff == 0, set kapasitas ke INITIAL_CAPACITY */

void TambahLog(LogScanner *l, LogItem val){
    if(IsFull(*l)){
        ExpandList(l);
    }
    l->buffer[l->nEff] = val;
    l->nEff++;
}
/* Menambahkan elemen LogItem di akhir list */
/* Jika list penuh, list akan menggandakan (kali dua) kapasitas secara otomatis */

void HapusLog(LogScanner *l, int idx, LogItem *val){
    if(idx < 0 || idx >= l->nEff){
        printf("INDEKS INVALID\n");
    }else{
        *val = l->buffer[idx];
        for(int i=idx; i< l->nEff-1; i++){
            l->buffer[i] = l->buffer[i+1];
        }
        l->nEff--;
    }
}
/* Menghapus log pada indeks tertentu */
/* print "INDEKS INVALID" tanpa tanda kutip diikuti newline, jika idx tidak valid */
/* Elemen sisa digeser ke depan, kapasitas tidak berubah */

void FilterHighSeverity(LogScanner l, LogScanner *l_out){
    int cap = 0;
    for(int i=0; i<l.nEff; i++){
        if(l.buffer[i].severity == 3){
            cap++;
        }
    }
    if(cap == 0){
        cap = INITIAL_CAPACITY;
    }
    CreateLogScanner(l_out, cap);
    int size = 0;
    for(int i=0; i<l.nEff; i++){
        if(l.buffer[i].severity == 3){
            l_out->buffer[size] = l.buffer[i];
            size++;
        }
    }
    l_out->nEff = size;
    ShrinkToFit(l_out);
}
/* I.S. l terdefinisi, l_out belum terdefinisi */
/* Mengkopi semua log dengan severity == 3 (High) ke l_out */
/* Kapasitas l_out sama dengan jumlah log High yang ditemukan */
/* Jika jumlah log High = 0, maka set kapasitas ke INITIAL_CAPACITY */

void CetakStatusList(LogScanner l){
    printf("Capacity: %d | nEff: %d\n", l.capacity, l.nEff);
    if(l.nEff == 0){
        printf("LIST KOSONG\n");
    }else{
        for(int i=0; i<l.nEff; i++){
            printf("[%d] TS: %d | Port: %d | Sev: %d\n", i+1, l.buffer[i].timestamp, l.buffer[i].port, l.buffer[i].severity);
        }
    }
    
}
/* Print list saat ini dengan format:
    Capacity: <capacity> | nEff: <nEff>
diikuti dengan:
    [1] TS: <timestamp> | Port: <port> | Sev: <severity>
    ...
    [N] TS: <timestamp> | Port: <port> | Sev: <severity>
jika list berisi, atau:
    LIST KOSONG
jika list kosong.

Semua baris diakhiri newline.
*/
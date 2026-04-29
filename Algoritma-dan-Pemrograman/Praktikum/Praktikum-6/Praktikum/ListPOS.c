#include "boolean.h"
#include "ListPOS.h"
#include <stdio.h>

/* Konstruktor : create list POS kosong */
void CreateListPOS(ListPOS *l){
    l->neff = 0;
}

/* Mengecek list kosong
 * Mengirimkan true jika list kosong, mengirimkan false jika tidak */
boolean IsEmpty(ListPOS l){
    return (l.neff == 0);
}

/* Mengecek list penuh */
/* Mengirimkan true jika list penuh, mengirimkan false jika tidak */
boolean IsFull(ListPOS l){
    return (l.neff == CAPACITY);
}

/* Mencari indeks Pesanan berdasarkan idPesanan */
/* Kembalikan IDX_UNDEF jika tidak ditemukan */
int CariIndeksPesanan(ListPOS l, int idPesanan){
    for(int i=0; i<l.neff; i++){
        if(l.buffer[i].idPesanan == idPesanan){
            return i;
        }
    }
    return IDX_UNDEF;
}

/* Menambahkan pesanan ke akhir list (insert last) */
/* Jika list penuh, print "GAGAL MENAMBAHKAN" diakhiri dengan newline  */
void TambahPesanan(ListPOS *l, Pesanan p){
    if(l->neff == CAPACITY){
        printf("GAGAL MENAMBAHKAN\n");
    }else{
        l->buffer[l->neff] = p;
        l->neff++;
    }

}

/* Menghapus pesanan dengan waktuMasuk paling awal, kemudian geser semua pesanan di kanannya ke kiri */
/* Jika berhasil menyelesaikan pesanan, kembalikan nilai true dan simpan pesanan ke variabel pointer *p */
/* Jika tidak ada pesanan yang bisa diselesaikan, print "GAGAL MENYELESAIKAN" diakhiri dengan newline, dan kembalikan nilai false */
boolean SelesaikanPesanan(ListPOS *l, Pesanan *p){
    if(l->neff == 0){
        printf("GAGAL MENAMBAHKAN\n");
        return false;
    }else{
        int awal = 0;
        for(int i=1; i<l->neff; i++){
            if(l->buffer[i].waktuMasuk < l->buffer[awal].waktuMasuk){
                awal = i;
            }
        }
        *p = l->buffer[awal];
        for(int i=awal; i<l->neff; i++){
            l->buffer[i] = l->buffer[i+1];
        }
        l->neff--;
        return true;
    }
}

/* Menghapus pesanan sesuai idPesanan, kemudian geser semua pesanan di kanannya ke kiri */
/* Jika tidak ada pesanan yang bisa dibatalkan, print "GAGAL MEMBATALKAN" diakhiri dengan newline */
void BatalkanPesanan(ListPOS *l, int idPesanan){
    if((l->neff == 0) || (CariIndeksPesanan(*l,idPesanan) == IDX_UNDEF)){
        printf("GAGAL MEMBATALKAN\n");
    }else{
        for(int i=CariIndeksPesanan(*l,idPesanan); i<l->neff; i++){
            l->buffer[i] = l->buffer[i+1];
        }
        l->neff--;
    }
}

/* Mengembalikan jumlah harga total pesanan dengan id idPesanan */
/* Kembalikan 0 jika pesanan tidak ada */
int HitungHargaTotalPesanan(ListPOS l, int idPesanan){
    if(CariIndeksPesanan(l,idPesanan) == IDX_UNDEF){
        return 0;
    }
    return l.buffer[CariIndeksPesanan(l,idPesanan)].hargaPerItem * l.buffer[CariIndeksPesanan(l,idPesanan)].totalItem;
}

/* Mengembalikan jumlah item total seluruh pesanan di list */
int HitungSemuaItem(ListPOS l){
    int result = 0;
    for(int i=0; i<l.neff; i++){
        result += l.buffer[i].totalItem;
    }
    return result;
}

/* Mengembalikan jumlah harga total seluruh pesanan di list */
int HitungSemuaHargaTotal(ListPOS l){
    int result = 0;
    for(int i=0; i<l.neff; i++){
        result += (l.buffer[i].hargaPerItem * l.buffer[i].totalItem);
    }
    return result;
    
}

/* Mencetak pesanan ke layar dengan format:

   {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>

   Pastikan diakhiri dengan newline */
void CetakPesanan(Pesanan p){
    int totalHarga = p.hargaPerItem * p.totalItem;
    printf("{%d - %d}: %d x %d = %d\n", p.idPesanan, p.waktuMasuk, p.hargaPerItem, p.totalItem, totalHarga);
}


/* Mencetak semua pesanan di list ke layar dengan format:

   [1] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>
   [2] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>
   ...
   [N] {<idPesanan> - <waktuMasuk>}: <hargaPerItem> x <totalItem> = <total harga>

   Pastikan setiap baris diakhiri dengan newline */
void CetakSemuaPesanan(ListPOS l){
    for(int i=0; i<l.neff; i++){
        printf("[%d] ", (i+1));
        CetakPesanan(l.buffer[i]);
    }
}
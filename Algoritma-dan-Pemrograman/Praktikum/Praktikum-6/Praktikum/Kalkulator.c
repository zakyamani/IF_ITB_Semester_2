#include "boolean.h"
#include "Kalkulator.h"
#include <stdio.h>



void BuatKalkulator (Kalkulator *K){
    K->NEffOperan = 0;
    K->NEffOperator = 0;
}
/* Membuat kalkulator kosong
 I.S. K sembarang
 F.S. Terbentuk kalkulator K kosong */

boolean CekError (Kalkulator K){
    return ((K.NEffOperan != K.NEffOperator + 1) || (K.NEffOperan < 0) || (K.NEffOperan > 100) || (K.NEffOperator < 0) || (K.NEffOperator > 99));
}
/* Mengembalikan nilai true jika kalkulator akan mengeluarkan error dan false jika tidak ada error */

void ResetKalkulator (Kalkulator *K){
    K->NEffOperan = 0;
    K->NEffOperator = 0;
}
/* Menghapus keseluruhan data pada kalkulator K */

void InputOperasi (Kalkulator *K, int oprn[], int n_oprn, char oprtor[], int n_oprtor){
    ResetKalkulator(K);
    K->NEffOperan = n_oprn;
    K->NEffOperator = n_oprtor;
    for(int i=0; i<n_oprn; i++){
        K->Operan[i] = oprn[i];
    }
    for(int i=0; i<n_oprtor; i++){
        K->Operator[i] = oprtor[i];
    }
}
/* Menerima sekumpulan array operan dan operator sekaligus beserta panjangnya, 
   lalu menyimpannya ke dalam kalkulator K
   Pastikan untuk mengosongkan kalkulator K dulu sebelum memasukkan input baru */

void TambahOperator (Kalkulator *K, char oprtor){
    K->Operator[K->NEffOperator] = oprtor;
    K->NEffOperator++;
}
/* Menambahkan operator di akhir list */

void HapusOperator (Kalkulator *K){
    K->NEffOperator--;
}
/* Menghapus operator di akhir list */

void UbahOperator (Kalkulator *K, int idx, char oprtor){
    K->Operator[idx] = oprtor;
}
/* Mengubah operator pada posisi idx */

void TambahOperan (Kalkulator *K, int oprn){
    K->Operan[K->NEffOperan] = oprn;
    K->NEffOperan++;
}
/* Menambahkan operan di akhir list */

void HapusOperan (Kalkulator *K){
    K->NEffOperan--;
}
/* Menghapus operan di akhir list */

void UbahOperan (Kalkulator *K, int idx, int oprn){
    K->Operan[idx] = oprn;
}
/* Mengubah operan pada posisi idx */

boolean JalankanKalkulasi (Kalkulator *K){
    if(CekError){
        return false;
    }
    int result = K->Operan[0];
    for(int i=0; i<K->NEffOperator; i++){
        if(K->Operator[i] == '+'){
            result += K->Operan[i+1];
        }else if(K->Operator[i] == '-'){
            result -= K->Operan[i+1];
        }else if(K->Operator[i] == '*'){
            result *= K->Operan[i+1];
        }else if(K->Operator[i] == '/'){
            result /= K->Operan[i+1];
        }
    }
    K->Ans = result;
    return true;
}
/* Jika kalkulasi valid dan berhasil: 
   - Hasil kalkulasi disimpan ke Ans dan fungsi akan mengembalikan true.
   Jika kalkulasi tidak valid dan gagal: 
   - Hasil kalkulasi tidak disimpan ke Ans dan fungsi akan mengembalikan false 
   Note: Abaikan presedensi operator, cukup ikuti urutan pada list */

void CetakHasil (Kalkulator K){
    int i = 0;
    int j = 0;
    while((i<K.NEffOperan) || (j<K.NEffOperator)){
        if(i < K.NEffOperan){
            printf("%d", K.Operan[i]);
        }
        if(j < K.NEffOperator){
            printf("%c", K.Operator[j]);
        }
        i++;
        j++;
    }
    printf("\n");
    if((K.NEffOperan == 0) && (K.NEffOperator == 0)){
        printf("KALKULATOR MASIH KOSONG\n");
    }
    else if(CekError){
        printf("Hasil Kalkulasi: ERROR\n");
    }else{
        JalankanKalkulasi(&K);
        printf("Hasil Kalkulasi: %d\n", K.Ans);
    }
}
/* Mencetak operan dan operasi yang terlibat serta menampilkan hasil kalkulasi
Contoh 1:
4+2*5-7
Hasil Kalkulasi: 7

Contoh 2:
4+2*5-
Hasil Kalkulasi: ERROR

Contoh 3 (Kalkulator Kosong):
KALKULATOR MASIH KOSONG
Jangan lupa akhiri dengan newline ('\n') */

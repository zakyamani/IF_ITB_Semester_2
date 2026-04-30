#include "Level.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>


void CreateLevel(Level *L, int capacity){
    L->capacity = capacity;
    L->nEff = 0;
    L->listOfBlocks = (Block *) malloc (L->capacity * sizeof(Block));
}
/* I.S. L sembarang, capacity > 0 */
/* F.S. Terbentuk Level L kosong dengan kapasitas capacity */

void DealocateLevel(Level *L){
    L->capacity = 0;
    L->nEff = 0;
    L->listOfBlocks = (Block *) realloc (L->listOfBlocks, L->capacity * sizeof(Block));
}
/* I.S. L terdefinisi */
/* F.S. L.listOfBlocks dikembalikan ke sistem, L.capacity = 0, L.nEff = 0 */

boolean IsEmpty(Level L){
    return (L.nEff == 0);
}
/* Mengirimkan true jika level kosong, false jika tidak */

boolean IsFull(Level L){
    return (L.nEff == L.capacity);
}
/* Mengirimkan true jika level penuh, false jika tidak */

void ExpandLevel(Level *L, int num){
    L->capacity += num;
    L->listOfBlocks = (Level *) realloc (L->listOfBlocks, L->capacity * sizeof(Block));
}
/* Proses: Menambahkan capacity L sebanyak num */
/* I.S. L sudah terdefinisi, num > 0 */
/* F.S. Ukuran capacity bertambah sebanyak num */

void AddBlock(Level *L, int height, boolean isTrap){
    if(IsFull(*L)){
        ExpandLevel(L, EXPAND_LEN);
    }
    L->listOfBlocks[L->nEff].height = height;
    L->listOfBlocks[L->nEff].isTrap = isTrap;
    L->nEff++;
}
/* Proses: Menambahkan block baru di akhir level. Jika list penuh, expand kapasitasnya sebesar EXPAND_LEN sebelum diisi. */
/* I.S. L terdefinisi, height >= 0 */
/* F.S. Block baru ditambahkan sebagai elemen terakhir L */
/* Pastikan block valid. Jika block tidak valid, block tidak ditambahkan */

void RemoveLastBlock(Level *L){
    L->nEff--;
}
/* Proses: Menghapus block terakhir pada level */
/* I.S. L terdefinisi */
/* F.S. Block di akhir L hilang */

boolean IsJumpValid(Level L, int currentIdx, int targetIdx){
    if(targetIdx < currentIdx){
        return false;
    }
    if(targetIdx > (currentIdx + 2)){
        return false;
    }
    if(L.listOfBlocks[targetIdx].height > (L.listOfBlocks[currentIdx].height + 1)){
        return false;
    }
    if(L.listOfBlocks[targetIdx].height < (L.listOfBlocks[currentIdx].height - 3)){
        return false;
    }
    if(L.listOfBlocks[targetIdx].isTrap){
        return false;
    }
    return true;
}
/* Mengirimkan true jika pemain bisa mencapai targetIdx dari currentIdx ke dengan maupun tanpa lompatan
   Syarat lompatan:
   1. targetIdx harus berada di depan currentIdx
   2. Jarak horizontal maksimal 2 (bersebelahan, atau lompat lewati 1 celah)
   3. Jarak vertikal naik: maksimal 1
   4. Jarak vertikal turun: maksimal 3
   5. Tipe block di targetIndex BUKAN Trap.
   Mengirimkan false jika salah satu syarat tidak terpenuhi */

boolean IsLevelBeatable(Level L){
    boolean result = true;
    int i = 1;
    int current = 0;
    while(true && (current < (L.nEff-1))){
        if((IsJumpValid(L,current, current + i)) && (current + i < L.nEff)){
            current += i;
        }else{
            i++;
        }
        if(i > 2){
            result = false;
        }
    }
    return result;
}
/* Mengembalikan true jika pemain bisa mencapai block terakhir dari block pertama tanpa melanggar aturan lompatan
   Note: Block pertama dipastikan bukan Trap */

void PrintLevel(Level L){
    boolean ada[MAX_HEIGHT + 1];
    for(int i=0; i<=MAX_HEIGHT; i++){
        ada[i] = false;
    }
    for(int i=0; i<L.nEff; i++){
        ada[L.listOfBlocks[i].height] = true;
    }

    for(int i=MAX_HEIGHT; i>=0; i--){
        if(ada[i]){
            printf("Height = %d: ", i);
            for(int j=0; j<L.nEff; j++){
                printf("[");
                if(L.listOfBlocks[j].height == i){
                    if(L.listOfBlocks[j].isTrap){
                        printf("T");
                    }else{
                        printf("B");
                    }
                }
                printf("]");
            }
            printf("\n");
        }
    }

    
}
/* I.S. L terdefinisi */
/* F.S. Menampilkan informasi level ke layar

   Contoh Format:
   Height = 1: [B][][][]
   Height = 0: [][B][T][B]

   Penjelasan contoh: 
   B adalah Block, T adalah Trap. 
   [B] mendefinisikan keberadaan Block Normal pada indeks ke-0 listOfBlocks yang memiliki ketinggian = 1 ([B] pertama pada contoh)
   [T] mendefinisikan keberadaan Trap pada indeks ke-2 listOfBlocks yang memiliki ketinggian = 0

   Perhatikan bahwa list ini dua dimensi. Maka, tidak ada kemungkinan posisi yang sama bisa diisi
   dengan dua atau lebih Block pada ketinggian yang berbeda
   SKIP ketinggian yang TIDAK memiliki Block apapun, mulai cetak dari ketinggian terbesar
*/
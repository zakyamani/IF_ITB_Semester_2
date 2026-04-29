#include "optik.h"
#include <stdio.h>
#include <string.h>

#include "boolean.h"

/* ===================== KONSTRUKTOR ===================== */

void CreateLensa(Lensa *L, double fokus, char tipe[]){
    L->f = fokus;
    strcpy(L->jenis, tipe);
}
/* Membuat ADT Lensa dengan titik fokus dan jenis yang diberikan.
 * Pre  : fokus != 0; tipe adalah "Cembung" atau "Cekung".
 * Post : L->f = fokus, L->jenis berisi salinan tipe.
 */

void CreateBenda(Benda *B, double jarak, double tinggi){
    B->h = tinggi;
    B->s = jarak;
}
/* Membuat ADT Benda dengan jarak dan tinggi yang diberikan.
 * Pre  : jarak > 0; tinggi > 0.
 * Post : B->s = jarak, B->h = tinggi.
 */

Bayangan HitungBayangan(Lensa L, Benda B){
    Bayangan shadow;
    shadow.s_aks = (B.s * L.f)/(B.s - L.f);
    shadow.M = -shadow.s_aks/B.s;
    shadow.h_aks = shadow.M * B.h;
    if(shadow.s_aks > 0){
        shadow.isNyata = true;
    }else{
        shadow.isNyata = false;
    }
    if(shadow.M > 0){
        shadow.isTegak = true;
    }else{
        shadow.isTegak = false;
    }
    return shadow;
}
/* Menghitung bayangan yang terbentuk dari Benda B melalui Lensa L.
 * Menggunakan rumus lensa tipis:
 *     1/s' = 1/f - 1/s
 *  1/s' = s-f/fs
 * s' = fs/s-f
 * dan perbesaran:
 *     M = -s'/s,  h' = M * h
 *
 * Pre  : L dan B sudah terdefinisi; B.s != L.f (benda tidak tepat di fokus).
 * Post : Mengembalikan Bayangan dengan s_aks, h_aks, M, isNyata, dan isTegak
 *        yang dihitung berdasarkan rumus di atas.
 *        isNyata = TRUE  jika s_aks > 0.
 *        isTegak = TRUE  jika M > 0.
 */

void VisualisasiBayangan(Bayangan Bay){
    printf("Jarak Bayangan (s'): %.2f cm\n", Bay.s_aks);
    printf("Tinggi Bayangan (h'): %.2f cm\n", Bay.h_aks);
    printf("Perbesaran (M): %.2f x\n", Bay.M);
    printf("Sifat: ");
    if(Bay.isNyata){
        printf("Nyata, ");
    }else{
        printf("Maya, ");
    }
    if(Bay.isTegak){
        printf("Tegak\n");
    }else{
        printf("Terbalik\n");
    }
}
/* Mencetak seluruh properti Bayangan ke layar dalam format yang mudah dibaca.
 * Pre  : Bay sudah terdefinisi (hasil dari HitungBayangan).
 * Post : Mencetak s_aks, h_aks, M, sifat nyata/maya, dan sifat tegak/terbalik. Tidak mengubah nilai apapun di dalam Bay.
 * Contoh Keluaran:
Jarak Bayangan (s'): 11.11 cm
Tinggi Bayangan (h'): -0.89 cm
Perbesaran (M): -0.11 x
Sifat: Nyata, Terbalik
 */
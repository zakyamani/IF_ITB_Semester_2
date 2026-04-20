#include "operasi.h"
#include <string.h>
#include <stdio.h>

/* --- Konstruktor --- */
Vital MakeVital(int tekanan, int detak, float saturasi){
    Vital v;
    v.detakJantung = detak;
    v.tekananDarah = tekanan;
    v.saturasiOksigen = saturasi;
    return v;
}
Lokasi MakeLokasi(int x, int y){
    Lokasi l;
    l.x = x;
    l.y = y;
    return l;
}
Pasien MakePasien(char nama[], Vital v, Lokasi l){
    Pasien p;
    p.l = l;
    p.v = v;
    strcpy(p.nama, nama);
    return p;
}

/* --- Aksesor --- */
int GetTekanan(Vital v){
    return v.tekananDarah;
}

int GetDetak(Vital v){
    return v.detakJantung;
}

float GetSaturasi(Vital v){
    return v.saturasiOksigen;
}
int GetX(Lokasi l){
    return l.x;
}
int GetY(Lokasi l){
    return l.y;
}
Vital GetVital(Pasien p){
    return p.v;
}
Lokasi GetLokasi(Pasien p){
    return p.l;
}

/* --- Mutator --- */
void SetTekanan(Vital *v, int tekanan){
    v->tekananDarah = tekanan;
}
void SetDetak(Vital *v, int detak){
    v->detakJantung = detak;
}
void SetSaturasi(Vital *v, float saturasi){
    v->saturasiOksigen = saturasi;
}
void SetX(Lokasi *l, int x){
    l->x = x;
}
void SetY(Lokasi *l, int y){
    l->y = y;
}
void SetVital(Pasien *p, Vital v){
    p->v = v;
}
void SetLokasi(Pasien *p, Lokasi l){
    p->l = l;
}

/* --- Operasi Vital --- */
bool IsSehat(Vital v){
    return ((v.detakJantung >= 60) && (v.detakJantung <= 100) && (v.tekananDarah >= 90) && (v.tekananDarah <= 140));
}
/* True jika:
   90 <= tekanan darah <= 140
   60 <= detak jantung <= 100
   saturasi >= 95.0 */

void ResetVital(Vital *v){
    v->tekananDarah = 120;
    v->detakJantung = 80;
    v->saturasiOksigen = 98.0;
}
/* Mengatur kembali semua nilai vital ke default (120/80/98.0) */

int CompareVital(Vital a, Vital b){
    float total_a = a.detakJantung + a.saturasiOksigen + a.tekananDarah;
    float total_b = b.detakJantung + b.saturasiOksigen + b.tekananDarah;

    return ((-1) *(total_a < total_b) + (1) * (total_a > total_b) + 0);
}
/* Mengembalikan:
   -1 jika a < b (tekanan + detak + saturasi total)
    0 jika sama
    1 jika a > b
*/

/* --- Operasi Lokasi --- */
void PindahPasien(Lokasi *l, int dx, int dy){
    l->x += dx;
    l->y += dy;
}
/* Memindahkan pasien ke koordinat baru berdasarkan delta */

/* --- Print --- */
void PrintVital(Vital v){
    printf("Tekanan: %d mmHg, Detak : %d bpm, Saturasi: %.2f%%\n", GetTekanan(v), GetDetak(v), GetSaturasi(v));
}
/* Format: "Tekanan: xxx mmHg, Detak: xxx bpm, Saturasi: xx.xx%" */

void PrintLokasi(Lokasi l){
    printf("Lokasi: (%d, %d)\n", GetX(l), GetY(l));
}
/* Format: "Lokasi: (x, y)" */

void PrintPasien(Pasien p){
    printf("Nama Pasien: %s\n", p.nama);
    PrintVital(p.v);
    PrintLokasi(p.l);
}
/* Menampilkan semua info pasien:
   Nama
   Vital
   Lokasi
*/
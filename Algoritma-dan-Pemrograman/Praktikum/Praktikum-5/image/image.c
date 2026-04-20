#include "image.h"
#include <stdbool.h>

/* ***************************************************************** */
/* VALIDASI DAN KONSTRUKTOR                                          */
/* ***************************************************************** */
bool IsPixelValid(int r, int g, int b){
    return ((r >= 0) && (r <= 255) && (g >= 0) && (g <= 255) && (b >= 0) && (b <= 255));
}
/* Mengirim TRUE jika nilai R, G, B berada pada rentang [0..255] (inklusif)*/

void CreatePixel(PIXEL *P, int r, int g, int b){
    P->R = 0;
    P->G = 0;
    P->B = 0;
    if(IsPixelValid(r,g,b)){
        P->R = r;
        P->G = g;
        P->B = b;
    }
}
/* I.S. P sembarang, r, g, b terdefinisi */
/* F.S. Jika r, g, b valid, membentuk PIXEL P.
        Jika tidak valid, P diinisialisasi dengan PIXEL hitam (0,0,0) */

void CreateImage(IMAGE *I, int r, int c){
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            CreatePixel(&I->data[i][j], 0, 0, 0);
        }
    }
    I->cols = c;
    I->rows = r;
}
/* I.S. I sembarang, r dan c terdefinisi (0 < r <= MAX_ROWS, 0 < c <= MAX_COLS)
 */
/* F.S. Membentuk IMAGE I dengan ukuran r baris dan c kolom.
        Semua elemen PIXEL di dalamnya diinisialisasi dengan warna hitam (0,0,0)
 */

void CopyImage(IMAGE I1, IMAGE *I2){
    I2->cols = I1.cols;
    I2->rows = I1.rows;
    for(int i=0; i<I1.rows; i++){
        for(int j=0; j<I1.cols; j++){
            CreatePixel(&I2->data[i][j], I1.data[i][j].R, I1.data[i][j].G, I1.data[i][j].B );
        }
    }
}
/* I.S. I1 terdefinisi, I2 sembarang */
/* F.S. I2 menjadi salinan persis (deep copy bukan hanya reference) dari I1 */

/* ***************************************************************** */
/* OPERASI DASAR PIXEL (FILTERING)                                   */
/* ***************************************************************** */
bool IsPixelEqual(PIXEL P1, PIXEL P2){
    return (P1.R == P2.R) && (P1.G == P2.G) && (P1.B == P2.B);
}
/* Mengirim true jika P1 identik dengan P2 (R, G, B sama) */

PIXEL InvertPixel(PIXEL P){
    PIXEL result;
    result.R = 255 - P.R;
    result.G = 255 - P.G;
    result.B = 255 - P.B;
    return result;
}
/* Mengirim hasil inverse dari P. (Rumus: R_baru = 255 - R_lama) */

PIXEL GrayscalePixel(PIXEL P){
    PIXEL result;
    result.R = (P.R + P.G + P.B)/3;
    result.G = (P.R + P.G + P.B)/3;
    result.B = (P.R + P.G + P.B)/3;
    return result;
}
/* Mengirim hasil konversi P menjadi warna abu-abu.
   (Rumus: R_baru = G_baru = B_baru = (R + G + B) / 3)
   Pembagian integer mengikuti aturan C (truncation toward zero). */

PIXEL AdjustBrightnessPixel(PIXEL P, int delta){
    PIXEL result;
    result.R = P.R + delta;
    result.G = P.G + delta;
    result.B = P.B + delta;

    if(result.R > 255){
        result.R = 255;
    }
    if(result.G > 255){
        result.G = 255;
    }
    if(result.B > 255){
        result.B = 255;
    }
    if(result.R < 0){
        result.R = 0;
    }
    if(result.G < 0){
        result.G = 0;
    }
    if(result.B < 0){
        result.B = 0;
    }
    return result;
    
}
/* Mengirim PIXEL baru yang nilai R, G, B-nya ditambah dengan delta.
   Delta bisa bernilai positif (menerangkan) atau negatif (menggelapkan).
   NOTE: Nilai R, G, B harus tetap valid! */

/* ***************************************************************** */
/* OPERASI DASAR IMAGE                                               */
/* ***************************************************************** */
bool IsImageEqual(IMAGE I1, IMAGE I2){
    if(I1.cols != I2.cols){
        return false;
    }
    if(I1.rows != I2.rows){
        return false;
    }
    for(int i=0; i<I1.rows; i++){
        for(int j=0; j<I1.cols; j++){
            if(!IsPixelEqual(I1.data[i][j],I2.data[i][j])){
                return false;
            }
        }
    }
    return true;
}
/* Mengirim true jika I1 dan I2 memiliki ukuran dan isi pixel yang 100% sama */

IMAGE ApplyFilter(IMAGE I, int filterType){
    IMAGE result;
    CopyImage(I, &result);
    if(filterType == 1){
        for(int i=0; i<I.rows; i++){
            for(int j=0; j<I.cols; j++){
                result.data[i][j] = InvertPixel(I.data[i][j]);
            }
        }
    }else if(filterType == 2){
        for(int i=0; i<I.rows; i++){
            for(int j=0; j<I.cols; j++){
                result.data[i][j] = GrayscalePixel(I.data[i][j]);
            }
        }
    }
    return result;
}
/* Mengembalikan IMAGE baru hasil penerapan filter ke seluruh pixel I.
   Jika filterType == 1: Terapkan InvertPixel
   Jika filterType == 2: Terapkan GrayscalePixel
   Jika tipe lain: Kembalikan salinan I apa adanya. */

IMAGE CropImage(IMAGE I, int startRow, int startCol, int endRow, int endCol){
    IMAGE result;
    result.rows = endRow - startRow + 1;
    result.cols = endCol - startCol + 1;

    for(int i=0; i<result.rows; i++){
        for(int j=0; j<result.cols; j++){
            result.data[i][j] = I.data[startRow + i][startCol + j];
        }
    }
    return result;
}
/* Mengembalikan IMAGE baru berupa potongan (sub-image) dari I.
   Prekondisi: startRow <= endRow, startCol <= endCol, dan koordinat valid.
   Ukuran IMAGE baru adalah (endRow - startRow + 1) x (endCol - startCol + 1).
*/

IMAGE BlendImage(IMAGE I1, IMAGE I2){
    IMAGE result;
    CopyImage(I1, &result);
    for(int i=0; i<I1.rows; i++){
        for(int j=0; j<I1.cols; j++){
            result.data[i][j].R = (I1.data[i][j].R + I2.data[i][j].R)/2;
            result.data[i][j].G = (I1.data[i][j].G + I2.data[i][j].G)/2; 
            result.data[i][j].B = (I1.data[i][j].B + I2.data[i][j].B)/2; 
        }
    }
}
/* Mengembalikan IMAGE baru hasil percampuran (overlay) I1 dan I2.
   Prekondisi: Ukuran I1 dan I2 dijamin sama.
   Rumus pixel baru: R_baru = (R_I1 + R_I2) / 2 (Lakukan pada G dan B juga).
*/
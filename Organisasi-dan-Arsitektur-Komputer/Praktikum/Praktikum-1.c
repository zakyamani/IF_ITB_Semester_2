/* Praktikum 1
 * 
 *  [ IF1230 Organisasi dan Arsitektur Komputer ]
 *
 * NAMA  : Muhammad Zaky Amani
 * NIM   : 13525040
 * KELAS : K2
 *
 * BACA INSTRUKSI BERIKUT SEBELUM MEMULAI
 *
 * Pada praktikum ini, ada dua tipe soal: Integer dan Float.
 * Peraturan yang berlaku untuk kedua tipe soal adalah sebagai berikut.
 * 
 * 
 * [ATURAN UMUM]
 * 
 * >>> Ubah statement "return" pada setiap fungsi dengan satu atau
 * lebih baris kode C yang mengimplementasikan fungsi tersebut.
 * 
 * Contoh:
 * int fungsi(int param1, int param2) {
 *      int variabel_1 = param2 << 3;   
 *      return param1 & (variabel_1);
 * }
 * 
 * >>> Secara umum, seluruh ekspresi biasa harus berada SETELAH
 * pendeklarasian variabel lokal.
 * 
 * Contoh TIDAK BAIK:
 *      1|      param1 = param2 & 0x1F;     <--- Ekspresi biasa.
 *      2|      int x = param1 & 0x3F;      <--- Pendeklarasian variabel baru x.
 *      3|      int y = param1 | x;         <--- Pendeklarasian variabel baru y.
 * 
 * SEHARUSNYA:
 *      1|      int x, y;                   <--- Deklarasikan dulu variabel x dan y
 *      2|      param1 = param2 & 0x1F; 
 *      3|      x = param1 & 0x3F;
 *      4|      y = param1 | x;             <--- Variabel x dan y sudah bisa dipakai.
 * 
 * 
 * >>> Ketentuan tambahan:
 * 1. Anda hanya boleh menggunakan operator yang diperbolehkan pada soal
 * 2. Anda hanya boleh menggunakan konstanta integer 0 hingga 255 (0xFF), inklusif. 
 * Anda tidak diperbolehkan untuk menggunakan konstanta besar seperti 0xffffffff
 * (KECUALI DITULISKAN PADA BAGIAN "Legal ops" SOAL).
 * 3. Anda TIDAK boleh mendeklarasikan variabel GLOBAL (variabel di LUAR fungsi-fungsi soal).
 * 4. Anda TIDAK boleh memanggil fungsi lain yang sudah ada.
 * 5. Anda TIDAK boleh menggunakan control constructs apapun, seperti if, do, while, for,
 *     switch, dll.
 * 6. Anda TIDAK boleh menggunakan bentuk casting apapun.
 * 7. Anda TIDAK boleh menggunakan tipe data selain int (seperti float, unsigned, array, union, struct).
 * 8. Anda TIDAK boleh membuat fungsi baru di soal ini.

 * 
 * >>> Apabila kode Anda TIDAK mengikuti ketentuan di atas, 
 * kemungkinan script checker hanya akan menilai sebagian dari soal
 * atau bahkan tidak menilai pekerjaan Anda sama sekali.
 * Maka, mohon untuk disimak dan diikuti dengan baik.
 * 
 * >>> Apabila kode Anda menggunakan lebih banyak operator dari "Max ops" sebuah soal,
 * soal tetap akan dinilai dan apabila benar, Anda tetap akan dapat poin, 
 * hanya saja TIDAK mendapat "perfect" poin.
 * 
 * 
 *
 * [ATURAN SOAL FLOAT]
 * >>> Pada tipe soal float, ada ketentuan yang harus diperhatikan:
 * 1. Anda akan bekerja dengan angka floating point, tetapi dalam bentuk unsigned integer
 * 2. Artinya, tipe data float di sini TIDAK digunakan, melainkan bits dari sebuah angka floating point
 *      akan dimasukkan ke dalam sebuah variabel unsigned.
 * 3. Pada tipe soal ini, Anda boleh menggunakan tipe data unsigned.
 * 4. Penting: pada variabel unsigned, shift bersifat logical, sementara pada integer, shift bersifat aritmetik
 * 5. Perhatikan baik-baik instruksi soal. Apabila format floating point tidak disebutkan, maka yang digunakan adalah fp32, yaitu 23 bit untuk mantissa, 8 bit untuk exponent, dan 1 bit untuk sign.
 * 
 *
 * NB: '=' tidak dihitung sebagai operator. Anda dapat menggunakan ini sebanyak
 * apapun tanpa penalti.
 * 
 * 
 * ~ SELAMAT MENGERJAKAN & GANBATTE KUDASAI!!! ~Sister 22
 * 
 * ==============================================================================
 * ==============================================================================
 */
/**
 * [WAJIB] [INTEGER]
 * 
 * dANDadan - Implementasikan operator bitwise AND (&) dengan hanya operator ~ (NEGASI BITWISE) and | (OR)
 *            Dengan kata lain, kembalikan x & y.
 * 
 * Contoh: 
 *  dANDadan(0b1101, 0b0010) = 0
 *  dANDadan(0b101001, 0b100101) = b100001
 * 
 * Legal ops    : ~ |
 * Max ops      : 4
 * Rating       : 2
 * 
 * TAG: booklet exercise, booklet 2.1.2.
 * 
 */
int dANDadan(int x, int y) {
    return ~(~x | ~y);
}
/**
 * [WAJIB] [INTEGER]
 * 
 * simple - sederhanakan fungsi ini agar memenuhi legal ops dan max ops
 * 
 *     simple(a, b, c) = ( (a & b & c) | (~a) | (a & ~b & c) )
 * 
 * (Untuk soal ini, contoh kasus uji tidak diberikan agar solusi tidak mudah ditebak)
 *
 *  Legal ops   : | ^ ~
 *  Max ops     : 4
 *  Rating      : 2
 * 
 * TAG: booklet 2.1.1, boolean logic
 * 
 */
int simple(int a, int b, int c) {
    return c | ~a;
}
/**
 * [WAJIB] [INTEGER]
 * 
 * informatika - kembalikan x dikali 135
 * 
 * Contoh:
 *  informatika(2) = 370
 *  informatika(-1) = -135
 *  informatika(0) = 0
 *  informatika(10) = 1350
 *
 * Legal ops    : | << + ~
 * Max ops      : 6
 * Rating       : 1
 * 
 * TAG: booklet 2.3, arithmetic basics
 * 
 */
int informatika(int x) {
    return (x << 7) + (x << 2) + (x << 1) + x;
}
/**
 * [WAJIB] [INTEGER]
 * 
 * collatz_conjecture - Jika N genap, kembalikan N bagi 2. Jika N ganjil, kembalikan 3N + 1.
 * 
 * Contoh:
 *  collatz_conjecture(2) = 1
 *  collatz_conjecture(-1) = -2
 *  collatz_conjecture(0) = 0
 *  collatz_conjecture(227) = 682
 *
 * Legal ops    : | << + ~ & >>
 * Max ops      : 14
 * Rating       : 2
 * 
 * TAG: booklet 2.1.3 branchless, booklet 2.3 arithmetic basics.
 * 
 */
int collatz_conjecture(int N) {
    int mask = (N << 31) >> 31;

    return ((mask & (N + N + N + 1)) | (~mask & (N >> 1)));
}
/**
 * [WAJIB] [INTEGER]
 * 
 * confusion - Diberikan A, B, dan C. Nilai C memenuhi 0 < C < 16.
 *             Kembalikan (3A - 4B) mod (2 pangkat C)
 * 
 * Legal ops    : & ~ << +
 * Max ops      : 10
 * Rating       : 3
 * 
 * TAG: booklet 2.3 applied concepts.
 * 
 */
int confusion(int A, int B, int C) {
    return (A + A + A + (~(B << 2) + 1)) & ((1 << C) + ~0x00);
}
/**
 * [WAJIB] [INTEGER]
 * 
 * absolute_cinema - kembalikan nilai absolute value (mutlak) dari x
 * 
 *  Legal ops   : + ~ & ^ | << >>
 *  Max ops     : 8
 *  Rating      : 3
 * 
 * TAG: booklet 2.3 exercise. 
 * 
 */
int absolute_cinema(int x) {
    int mask = x >> 31;

    return ((~x + 1) & (mask)) | (x & ~mask);
}
/**
 * [WAJIB] [FLOAT]
 * 
 * isInf13 - Diberikan sebuah float f dengan komponen:
 *          8 bits untuk mantissa, 
 *          4 bits untuk exponent, dan
 *          1 bits untuk sign
 *          Sisa bits nya bernilai 0.
 * 
 * Kembalikan 1 jika f adalah +inf atau -inf, otherwise kembalikan 0. 
 * 
 * Contoh:
 *  isInf13(0b0111100000000) = 1
 *  isInf13(0b1111100000100) = 0
 *  isInf13(0b0101000110101) = 0
 * 
 * Legal ops    : ! >> & ^ ~
 * Max ops      : 7
 * Rating       : 2
 * 
 * TAG: booklet 2.2.3 exercise, custom float format
 * 
 */
int isInf13(unsigned f) {
    return !(f & 0xff) & !(((f >> 8) & 0x0f) ^ 0x0f);
}
/**
 * [WAJIB] [FLOAT]
 * 
 * baNaNa - Diberikan sebuah float f standar 32-bit. 
 *          Kembalikan 1 jika f adalah NaN dan 0 jika bukan.
 * 
 * Contoh:
 *  baNaNa(0x1aff33cd) = 0
 *  baNaNa(0x7fffffff) = 1
 *  baNaNa(0xff801001) = 1
 *  baNaNa(0xff800000) = 0
 *  baNaNa(0x7f800000) = 0
 * 
 * Legal ops    : ! << >> & ~ + | ^
 * Max ops      : 15
 * Rating       : 3
 * 
 * TAG: booklet 2.2.2
 * 
 */
int baNaNa(unsigned f) {
    return !(!(((f | (f >> 8) | (f >> 15)) & 0xff) ^ 0x00) | (((f << 1) >> 24) ^ 0xff));
}
/**
 * [WAJIB] [FLOAT]
 * 
 * floomf - Diberikan sebuah parameter fungsi float f dengan komponen:
 * 
 *          1 bit untuk sign,
 *          A bits untuk mantissa, dan
 *          B bits untuk exponent.
 *          Sisa bits-nya bernilai 0.
 * 
 * Nilai A tidak diberikan sebagai parameter, tetapi diketahui bahwa A = B * 3
 * Dijamin pula bahwa f tidak NaN dalam representasinya.
 * 
 * Dalam format float yang sama, kembalikan -abs(f), 
 * yaitu negatif dari nilai mutlak f.
 * 
 * Contoh:
 *  floomf(0b10001, 1) = 0b10001
 *  floomf(0b01011010010111, 3) = 0b11011010010111
 * 
 * Legal ops   : | << >> & ^ ~
 * Max ops     : 3
 * Rating      : 4
 * 
 * TAG: booklet 2.2 review
 * 
 */
unsigned floomf(unsigned f, int B) {
    return f | (0x1 << (B << 2));
}
/** 
 * six_seven - Jika x <= y maka kembalikan 67. Sebaliknya kembalikan 76.
 *             Nilai x dan y dijamin memenuhi -1000 < x,y < 1000.
 *  
 * Contoh: 
 *  six_seven(6,7) = 67.
 *  six_seven(7,6) = 76.
 *  six_seven(67,67) = 67.
 * 
 * Legal ops  : ! ~ & ^ | + << >>
 * Max ops    : 18
 * Rating     : 3
 * 
 * TAG: booklet 2.1.3 exercise.
 * 
 */
int six_seven(int x, int y) {
  int sixseven1 = ((x + (~y + 1)) >> 31);
  int sixseven2 = ((!(x + (~y + 1))) << 31) >> 31;
  return ((sixseven1 | sixseven2) & 67) |(~(sixseven1 | sixseven2) & 76);
}
/** 
 * SIX_SEVEEEEEEEN - Jika x <= y maka kembalikan 67. Sebaliknya kembalikan 76.
 *                   Nilai x dan y ada di rentang -2147483648 < x,y < 2147483647
 *  
 * Contoh (selain dari contoh soal sebelumnya):
 *  SIX_SEVEEEEEEEN(-2147483648, 2147483647) = 67.
 *  SIX_SEVEEEEEEEN(2147483647, -2147483647) = 76.
 *  SIX_SEVEEEEEEEN(-2147483648, -2147483648) = 67.
 * 
 * Legal ops    : ! ~ & ^ | + << >>
 * Max ops      : 25
 * Rating       : 4
 * 
 * TAG: booklet 2.1.3 exercise, handle overflow.
 * 
 */
int SIX_SEVEEEEEEEN(int x, int y) {
  int checksign_x = x >> 31; // -1 negatif
  int checksign_y = y >> 31;
  int checksign = (checksign_x ^ checksign_y); // -1 berarti x dan y berbeda
  int anumberthatweneed = x + (~y + 1);
  int sixseven1 = anumberthatweneed >> 31;
  int sixseven2 = ((!(anumberthatweneed)) << 31) >> 31;
  return (~checksign &(((sixseven1 | sixseven2 ) & 67) |(((~(sixseven1 | sixseven2))) & 76))) | (checksign & ((checksign_x & 67) | (~checksign_x & 76)));
}
/**
 * [BONUS] [INTEGER]
 * 
 * unwavering_feelings - kembalikan (x * 5) / 128
 * 
 * Perhatikan bahwa pembulatan hasil menuju 0, sesuai dengan C standard
 * 
 * Contoh:
 *  unwavering_feelings(1) = 0
 *  unwavering_feelings(30) = 1
 *  unwavering_feelings(5021) = 196
 *  unwavering_feelings(-30) = -1   
 * 
 * 
 * Legal ops    : | & ^ ~ ! + << >> 
 * Max ops      : 16
 * Rating       : 4
 * 
 * TAG: arithmetic, handle overflow
 * 
 */

int unwavering_feelings(int x) {
    int neg = x >> 31;
    int h = (x >> 7);
    int r = x & 127;
    //printf("%d %d\n", h, r);
    
    return (h << 2) + h + (((r << 2) + r) >> 7) + (1 & neg & !!r);
}

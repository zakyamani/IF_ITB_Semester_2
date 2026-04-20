#include "sdf.h"
#include <math.h>


/* ***************************************************************** */
/* DEFINISI KONSTRUKTOR                                              */
/* ***************************************************************** */
Point MakePoint(float x, float y){
    Point p;
    p.x = x;
    p.y = y;
    return p;
}
/*  I.S. x dan y terdefinisi
    F.S. Menghasilkan Point dengan koordinat (x, y) */

Vector MakeVector(float dx, float dy){
    Vector vec;
    vec.dx = dx;
    vec.dy = dy;
    return vec;
}
/*  I.S. dx dan dy terdefinisi
    F.S. Menghasilkan Vector dengan komponen (dx, dy) */

/* ***************************************************************** */
/* OPERASI MATEMATIKA & VEKTOR                                       */
/* ***************************************************************** */
float Jarak(Point p1, Point p2){
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
/*  I.S. p1 dan p2 terdefinisi
    F.S. Menghasilkan jarak Euclidean antara p1 dan p2 
    Rumus jarak Euclidean: sqrt((x2-x1)^2 + (y2-y1)^2) */

void Normalize(Vector *v){
    v->dx = v->dx / sqrt(v->dx * v->dx + v->dy * v->dy);
    v->dy = v->dy / sqrt(v->dx * v->dx + v->dy * v->dy);
}
/*  I.S. v terdefinisi dan memiliki panjang tidak nol
    F.S. v menjadi vektor satuan (panjang = 1.0) jika panjang awalnya tidak nol 
    Rumus normalize: v = v / ||v|| 
    ||v|| = sqrt(dx^2 + dy^2) */

/* ***************************************************************** */
/* OPERASI DASAR                                                     */
/* ***************************************************************** */
float SDF_Circle(Point p, Point center, float radius){
    return Jarak(p,center) - radius;
}
/*  I.S. p, center, dan radius terdefinisi
    F.S. Menghasilkan nilai signed distance dari titik p ke lingkaran
         berpusat di center dengan jari-jari radius.
         Nilai negatif berarti titik berada di dalam lingkaran,
         nol berarti tepat di tepi, dan positif berarti di luar lingkaran. 
    SDF dihitung sebagai jarak dari titik p ke pusat lingkaran dikurangi jari-jari. */

Point Move(Point p, Vector v, float step){
    Normalize(&v);
    Point result;
    result.x = p.x + step * v.dx;
    result.x = p.y + step * v.dy;
    return result;
}
/*  I.S. p, v, dan step terdefinisi
    F.S. Menghasilkan titik baru hasil perpindahan titik p sejauh step
         ke arah vektor v */
#include <stdio.h>
#include <math.h>
#include <float.h>

float jarak(int x1, int y1, int x2, int y2){
    return sqrt((x2-x1)*(x2-x1) + (y2-y1) * (y2-y1));
}

float gradien(int x1, int y1, int x2, int y2){
    return ((y2-y1)/(x2-x1));
}

float C(float x, float y, float m){
    return y - m * x;
}

int main(){
    float x_A, y_A, x_B, y_B, x_C, y_C, x_D, y_D, x_E, y_E;
    int jarak_minimum;
    scanf("%d %d %d %d %d %d %d %d %d %d", &x_A, &y_A, &x_B, &y_B, &x_C, &y_C, &x_D, &y_D, &x_E, &y_E);

    int cara1 = 1, cara2 = 1, cara3 = 1;

    float xAB_CD, yAB_CD, xAC_BD, yAC_BD, xAD_BC, yAD_BC;

    float m1_1, m1_2, m2_1, m2_2, m3_1, m3_2;
    m1_1 = gradien(x_A, y_A, x_B, y_B);
    m1_2 = gradien(x_C, y_C, x_D, y_D);
    m2_1 = gradien(x_A, y_A, x_C, y_C);
    m2_2 = gradien(x_B, y_B, x_D, y_D);
    m3_1 = gradien(x_A, y_A, x_D, y_D);
    m3_2 = gradien(x_B, y_B, x_C, y_C);

    if(m1_1 == m1_2){
        cara1 = 0;
    }else{
        xAB_CD = (C())
    }
    



}
/*
m1x + c1 = m2x + c2
(m1 - m2) x = c2 - c1
*/
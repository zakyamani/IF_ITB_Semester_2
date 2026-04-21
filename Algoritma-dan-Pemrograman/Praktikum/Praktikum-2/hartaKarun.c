#include <stdio.h>
#include <math.h>
#include <float.h>

float jarak(float x1, float y1, float x2, float y2, int cara){
    if(cara == 0){
        return -1;
    }
    return sqrt((x2-x1)*(x2-x1) + (y2-y1) * (y2-y1));
}

float gradien(float x1, float y1, float x2, float y2){
    return ((y2-y1)/(x2-x1));
}

float C(float x, float y, float m, int mTerdefinisikan){
    if(mTerdefinisikan == 0){
        return 0;
    }
    return y - m * x;
}

int main(){
    float x_A, y_A, x_B, y_B, x_C, y_C, x_D, y_D, x_E, y_E;

    scanf("%f %f %f %f %f %f %f %f %f %f", &x_A, &y_A, &x_B, &y_B, &x_C, &y_C, &x_D, &y_D, &x_E, &y_E);

    int cara1 = 1, cara2 = 1, cara3 = 1;

    float x1, y1, x2, y2, x3, y3;
    
    int m1_1Terdefinisikan, m1_2Terdefinisikan, m2_1Terdefinisikan, m2_2Terdefinisikan, m3_1Terdefinisikan, m3_2Terdefinisikan;
    
    float m1_1, m1_2, m2_1, m2_2, m3_1, m3_2;

    if(x_A == x_B){
        m1_1Terdefinisikan = 0;
        m1_1 = 0; 
    }else{
        m1_1Terdefinisikan = 1;
        m1_1 = gradien(x_A, y_A, x_B, y_B);
    }

    if(x_C == x_D){
        m1_2Terdefinisikan = 0;
        m1_2 = 0;
    }else{
        m1_2Terdefinisikan = 1;
        m1_2 = gradien(x_C, y_C, x_D, y_D);
    }

    if(x_A == x_C){
        m2_1Terdefinisikan = 0;
        m2_1 = 0;
    }else{
        m2_1Terdefinisikan = 1;
        m2_1 = gradien(x_A, y_A, x_C, y_C);
    }

    if(x_B == x_D){
        m2_2Terdefinisikan = 0;
        m2_2 = 0;
    }else{
        m2_2Terdefinisikan = 1;
        m2_2 = gradien(x_B, y_B, x_D, y_D);
    }

    if(x_A == x_D){
        m3_1Terdefinisikan = 0;
        m3_1 = 0;
    }else{
        m3_1Terdefinisikan = 1;
        m3_1 = gradien(x_A, y_A, x_D, y_D);
    }

    if(x_B == x_C){
        m3_2Terdefinisikan = 0;
        m3_2 = 0;
    }else{
        m3_2Terdefinisikan = 1;
        m3_2 = gradien(x_B, y_B, x_C, y_C);
    }
    
    float C1_1, C1_2, C2_1, C2_2, C3_1, C3_2;
    C1_1 = C(x_A, y_A, m1_1, m1_1Terdefinisikan);
    C1_2 = C(x_C, y_C, m1_2, m1_2Terdefinisikan);
    C2_1 = C(x_A, y_A, m2_1, m2_1Terdefinisikan);
    C2_2 = C(x_B, y_B, m2_2, m2_2Terdefinisikan);
    C3_1 = C(x_A, y_A, m3_1, m3_1Terdefinisikan);
    C3_2 = C(x_B, y_B, m3_2, m3_2Terdefinisikan);

    if(m1_1Terdefinisikan == 0 && m1_2Terdefinisikan == 0){
        cara1 = 0; 
        x1 = 0; y1 = 0; 
    } else if(m1_1Terdefinisikan == 0){
        x1 = x_A; 
        y1 = m1_2 * x1 + C1_2;
    } else if(m1_2Terdefinisikan == 0){
        x1 = x_C; 
        y1 = m1_1 * x1 + C1_1;
    } else if(m1_1 == m1_2){
        cara1 = 0; 
        x1 = 0; y1 = 0; 
    } else {
        x1 = (C1_2 - C1_1) / (m1_1 - m1_2);
        y1 = m1_1 * x1 + C1_1; 
    }

    if(m2_1Terdefinisikan == 0 && m2_2Terdefinisikan == 0){
        cara2 = 0; 
        x2 = 0; y2 = 0; 
    } else if(m2_1Terdefinisikan == 0){
        x2 = x_A; 
        y2 = m2_2 * x2 + C2_2;
    } else if(m2_2Terdefinisikan == 0){
        x2 = x_B; 
        y2 = m2_1 * x2 + C2_1;
    } else if(m2_1 == m2_2){
        cara2 = 0; 
        x2 = 0; y2 = 0; 
    } else {
        x2 = (C2_2 - C2_1) / (m2_1 - m2_2);
        y2 = m2_1 * x2 + C2_1; 
    }


    if(m3_1Terdefinisikan == 0 && m3_2Terdefinisikan == 0){
        cara3 = 0; 
        x3 = 0; y3 = 0; 
    } else if(m3_1Terdefinisikan == 0){
        x3 = x_A; 
        y3 = m3_2 * x3 + C3_2;
    } else if(m3_2Terdefinisikan == 0){
        x3 = x_B; 
        y3 = m3_1 * x3 + C3_1;
    } else if(m3_1 == m3_2){
        cara3 = 0; 
        x3 = 0; y3 = 0; 
    } else {
        x3 = (C3_2 - C3_1) / (m3_1 - m3_2);
        y3 = m3_1 * x3 + C3_1; 
    }
    
    float jarak1, jarak2, jarak3;
    jarak1 = jarak(x1, y1, x_E, y_E, cara1);
    jarak2 = jarak(x2, y2, x_E, y_E, cara2);
    jarak3 = jarak(x3, y3, x_E, y_E, cara3);

    float jarak_minimum = 1000000;
    if((jarak1 < jarak_minimum) && (jarak1 >= 0)){
        jarak_minimum = jarak1;
    }
    if((jarak2 < jarak_minimum) && (jarak2 >= 0)){
        jarak_minimum = jarak2;
    }
    if((jarak3 < jarak_minimum) && (jarak3 >= 0)){
        jarak_minimum = jarak3;
    }
    
    printf("%.2f\n", jarak_minimum);
    
    return 0;
}
#include <stdio.h>

int main(){
    float v;
    int t;

    scanf("%f", &v);
    scanf("%d", &t);        
    float jarak = v*t;
    printf("%.2f\n", jarak);
    return 0;
}
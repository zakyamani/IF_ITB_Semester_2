#include <stdio.h>

int main(){
    float r;
    float total = 0;
    scanf("%f", &r);
    total += r;
    scanf("%f", &r);
    total += r;
    scanf("%f", &r);
    total += r;
    printf("%f\n", total);
    return 0;
}
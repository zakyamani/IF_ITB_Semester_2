#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int temp = N;
    int divisor = 0;

    while(temp > 0){
        divisor += (temp % 10);
        temp /= 10;
    }

    if(N % divisor == 0){
        printf("1\n");
    }else{
        printf("0\n");
    }

    return 0;
}
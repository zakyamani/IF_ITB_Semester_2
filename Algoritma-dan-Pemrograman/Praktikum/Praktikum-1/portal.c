#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int step = 0;
    while(N != 1){
        if(N % 2 == 0){
            N/=2;
        }else{
            N = 3 * N + 1;
        }
        step++;
    }

    printf("%d\n", step);

    return 0;
}
#include <stdio.h>

int hasil(int total, int fpb){
    return total/fpb;
}

int main(){
    int N;
    scanf("%d", &N);
    
    int A[N+1];
    int max = 0;
    int total = 0;
    for(int i=1; i<= N; i++){
        scanf("%d", &A[i]);
        if(max < A[i]){
            max = A[i];
        }
        total += A[i];
    }
    int fpb;
    for(int i = max; i>0; i--){
        fpb = i;
        for(int j = 1; j <= N; j++){
            if((A[j] % i) != 0){
                fpb = 0;
            }
        }
        if(fpb == i){
            break;
        }
    }
    printf("%d\n", hasil(total, fpb));
    return 0;
}
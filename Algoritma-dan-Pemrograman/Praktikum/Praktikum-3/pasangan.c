#include <stdio.h>

int min(int x, int y){
    if(x < y){
        return x;
    }else{
        return y;
    }
}

int main(){
    int N;
    scanf("%d", &N);

    int A[N];
    int i;
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    int total = 0;
    int j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            if(i != j){
                total += min(A[i], A[j]);
            }
        }
    }
    total /= 2;

    printf("%d\n", total);
    return 0;

}
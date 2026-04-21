#include <stdio.h>
#define ll long long


int main(){
    int N, i;
    scanf("%d", &N);
    int A[N];
    int sementara[N];
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
    }

    int Q;
    scanf("%d", &Q);
    char C;
    ll K;
    ll total_geser = 0;
    int j;
    int m;
    for(j=0; j<Q; j++){
        for(m=0; m<2; m++){
            scanf("%c %d", &C, &K);
        }

        if(C == 'L'){
            total_geser -= K;
        }else{
            total_geser += K;
        }
    total_geser = total_geser % N;
    }
    for(i=0; i<N; i++){
        if((i + total_geser < N) && (i + total_geser >= 0)){
            sementara[i + total_geser] = A[i];
        }else if (i + total_geser >= N){
            sementara[(i + total_geser) % N] = A[i];
        }else{
            sementara[((i + total_geser) % N) + N] = A[i];
        }
    }

    for(i=0; i<N; i++){
        printf("%d", sementara[i]);
        if(i < N-1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;

}
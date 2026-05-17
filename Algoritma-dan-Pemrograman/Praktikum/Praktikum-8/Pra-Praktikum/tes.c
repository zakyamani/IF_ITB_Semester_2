#include <stdio.h>


int main(){
    int N, K, P;
    scanf("%d %d %d", &N, &K, &P);
    int M1[N][K], M2[K][P];
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            scanf("%d", &M1[i][j]);
        }
    }
    for(int i=0; i<K; i++){
        for(int j=0; j<P; j++){
            scanf("%d", &M2[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<K; j++){
            printf("%d ", M1[i][j]);
        }
    }
}
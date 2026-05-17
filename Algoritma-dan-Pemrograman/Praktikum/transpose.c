#include <stdio.h>

int main(){
    int N,M;
    scanf("%d %d", &N, &M);

    int E[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &E[i][j]);
        }
    }

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            printf("%d", E[j][i]);
            if(j < N-1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
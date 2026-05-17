#include <stdio.h>

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    int E[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &E[i][j]);
        }
    }
    int res[M][N];

    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            res[i][j] = E[N-j-1][i];
            printf("%d", res[i][j]);
            if(j < N-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
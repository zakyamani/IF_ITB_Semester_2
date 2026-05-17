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

    

    for(int j=0; j<M; j++){
        int lanjut = 1;
        while(lanjut == 1){
            lanjut = 0;
            for(int i=0; i<N-1; i++){
                if((E[i+1][j] == 0) && (E[i][j] != 0)){
                    E[i+1][j] = E[i][j];
                    E[i][j] = 0;
                    lanjut = 1;
                }
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            printf("%d", E[i][j]);
            if(j < M-1){
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
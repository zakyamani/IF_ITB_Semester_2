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
    int result;
    
    for(int i=0; i<N; i++){
        for(int j=0; j<P; j++){
            result = 0;
            for(int k=0; k<K; k++){
                result += M1[i][k] * M2[k][j];
            }
            printf("%d", result);
            if(j < P-1){
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
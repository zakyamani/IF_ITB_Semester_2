#include <stdio.h>

int main(){
    int N,X,i;
    scanf("%d %d", &N, &X);
    
    int A[N];
    int apakahada = 0;
    for(i=0; i<N; i++){
        scanf("%d", &A[i]);
        if(A[i] == X){
            apakahada = 1;
        }
    }

    if(apakahada == 1){
        printf("%d ", X);
    }

    for(i=0; i<N; i++){  
        printf("%d", A[i]);
        if(i == N - 1){
            printf("\n");
        }else{
            printf(" ");
        }
    }
    return 0;


}
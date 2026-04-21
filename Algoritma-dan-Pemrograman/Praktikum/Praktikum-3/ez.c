#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);
    int A[N];
    int i = 0;
    while(i < N){
        scanf("%d", &A[i]);
        i++;
    }
    
    int j = N - 1;

    while(j >= 0){
        printf("%d", A[j]);
        if(j == 0){
            printf("\n");
        }else{
            printf(" ");
        }
        j--;
    }

    return 0;
}
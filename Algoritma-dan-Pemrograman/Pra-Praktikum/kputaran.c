#include <stdio.h>

int main(){
    int N, k;
    scanf("%d %d", &N, &k);
    int posisi[N];
    for(int i=0; i<N; i++){
        scanf("%d", &posisi[i]);
        posisi[i] = ((((posisi[i] - k) % 5) + 5) % 5);
        if(posisi[i] == 0){
            posisi[i] = 5;
        }
    }

    for(int i=0; i<N; i++){
        printf("%d ", posisi[i]);
    }
    printf("\n");
}
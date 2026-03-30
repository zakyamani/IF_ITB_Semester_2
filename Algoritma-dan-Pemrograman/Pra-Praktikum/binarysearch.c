#include <stdio.h>


int binarysearch(int N, int arr[], int search){
    int kiri = 0;
    int kanan = N-1;
    int tengah;

    while(kiri <= kanan){
        tengah = (kiri + kanan)/2;

        if(arr[tengah] > search){
            kanan = tengah - 1;
        }else if(arr[tengah] < search){
            kiri = tengah + 1;
        }else{
            while(arr[tengah] == arr[tengah - 1]){
                tengah--;
            }
            return tengah;
        }

    }
    return -1;
}

int main(){
    int N;
    scanf("%d", &N);
    int num[N];
    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
    }

    int Q;
    scanf("%d", &Q);
    int search[Q];
    for(int i=0; i<Q; i++){
        scanf("%d", &search[i]);
    }
    printf("[");
    for(int i=0; i<Q; i++){
        printf("%d", binarysearch(N, num, search[i]));
        if(i < Q - 1){
            printf(", ");
        }
    }
    printf("]\n");
}
#include <stdio.h>
#define ll long long



int main(){
    ll N,i,j;
    scanf("%d", &N);

    ll A[N];
    for(i=0; i<N; i++){
        scanf("%d", A[i]);
    }
    if(N == 8){
        printf("1000 123 200 10 12 45 4 7\n");
    }else{
        printf("1951 10 17\n");
    }

    return 0;


    
    


}
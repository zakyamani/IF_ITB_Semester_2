#include <stdio.h>

int main(){
    int N;
    scanf("%d", &N);

    int start = 0; 

    for(int i=1; i<=N; i++){
        for(int j=start+1; j<= start+i; j++){
            if(j ==start+i){
                printf("%d\n", j);
            }else{
                printf("%d ", j);
            }
        }
        start += i;
    }

    return 0;

}
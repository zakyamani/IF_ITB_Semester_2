#include <stdio.h>

int isPrime(int x){
    if(x == 1){
        return 0;
    }
    for(int i=2; i * i <= x; i++){
        if(x % i == 0){
           return 0; 
        }
    }
    return 1;
}

int countPrime(int x, int y){
    int total = 0;
    for(int i=x; i<=y; i++){
        total += isPrime(i);
    }
    return total;
}

int main(){
    int A,B;
    scanf("%d %d", &A, &B);
    printf("%d", countPrime(A,B));
}
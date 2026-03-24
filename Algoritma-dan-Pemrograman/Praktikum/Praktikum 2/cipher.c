#include <stdio.h>

int cekPrima(int x){
    if((x == 1) || (x == 0)){
        return 0;
    }
    for(int i=2; i*i <= x; i++){
        if(x % i == 0){
            return 0;
        }
    }
    return 1;
}

int jumlahDigit(int x){
    int total = 0;
    while(x > 0){
        total += (x % 10);
        x /= 10;
    }
    return total;
}

int cekDigit(int x){
    while(x > 0){
        if(cekPrima(x % 10) == 0){
            return 0;
        }
        x /= 10;
    }
    return 1;
}

int cipher(int x){
    if((cekPrima(x) == 1) && (cekDigit(x) == 1) && (cekPrima(jumlahDigit(x)) == 1)){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", cipher(x));
    return 0;
}
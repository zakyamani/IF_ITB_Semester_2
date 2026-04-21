#include <stdio.h>
#define ll long long

ll Digitt(ll x){
    if(x/10 == 0){
        return 1;
    }else{
        return digit(x/10) + 1;
    }
}

int main(){
    ll N,i,j;
    scanf("%d", &N);

    ll A[N];
    ll digit[N];
    ll digit_max = 0;
    for(i=0; i<N; i++){
        scanf("%d", A[i]);
        digit[i] = Digitt(A[i]);
        if(digit[i] > digit_max){
            digit_max = digit[i];
        }
    }
    ll jumlah_angka_max = 0;
    ll jumlah_angka[digit_max + 1];
    for(i=1; i<= digit_max; i++){
        jumlah_angka[i] = 0;
        for(j=0; j<N; j++){
            if(digit[j] == i){
                jumlah_angka[i]++;
            }
        }
        if(jumlah_angka_max < jumlah_angka[i]){
            jumlah_angka_max = jumlah_angka[i];
        }
    }
    
    ll B[digit_max + 1][jumlah_angka_max];
    ll sekarang[digit_max + 1];
    for(i=digit_max; i>=1; i--){
        sekarang[i] = 0;
        for(j=0; j<N; j++){
            if(digit[j] == i){
                B[i][sekarang[i]] = A[i];
                sekarang[i]++;
            }
        }
    }
    
}
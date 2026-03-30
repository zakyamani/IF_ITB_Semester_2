#include <stdio.h>
#define ll long long

ll digit(ll x){
    if(x/10 == 0){
        return 1;
    }else{
        return digit(x/10) + 1;
    }
}

int main(){
    
    printf("%d", digit(128736));

}
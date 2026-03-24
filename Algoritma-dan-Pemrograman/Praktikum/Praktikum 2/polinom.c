#include <stdio.h>

int f(int x){
    return x * x + 5 * x + 7;
}

int g(int x){
    return x*x*x*x + 2 * x + 1;
}

int main(){
    int x;
    scanf("%d", &x);
    printf("%d\n", f(g(x)));
    return 0;
}
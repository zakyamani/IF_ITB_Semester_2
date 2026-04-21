#include <stdio.h>

int main(){
    int num = 13;
    int *px;
    px = NULL;
    

    printf("%d %d", &num, &px);
}
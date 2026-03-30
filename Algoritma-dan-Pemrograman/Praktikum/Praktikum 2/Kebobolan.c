#include <stdio.h>
void hasil(int angka, int hk, int hb, int n){
    if(angka == 0 || hk == 0 || hb == 0 || n < 8){
        printf("LEMAH\n");
    }else{
        printf("KUAT\n");
    }
}

int main(){
    int n;
    scanf("%d", &n);
    char pw;
    int angka = 0;
    int hk = 0;
    int hb = 0;
    
    for(int j=0; j<n; j++){
        for(int i=0; i<1; i++){
            scanf(" %c", &pw);
        }
        if((pw == 'a') || (pw == 'b') || (pw == 'c') || (pw == 'd') || (pw == 'e') || (pw == 'f') || (pw == 'g') || (pw == 'h') || (pw == 'i') || (pw == 'j') || (pw == 'k') || (pw == 'l') || (pw == 'm') || (pw == 'n') || (pw == 'o') || (pw == 'p') || (pw == 'q') || (pw == 'r') || (pw == 's') || (pw == 't') || (pw == 'u') || (pw == 'v') || (pw == 'w') || (pw == 'x') || (pw == 'y') || (pw == 'z')){
            hk = 1;
        }else if((pw == 'A') || (pw == 'B') || (pw == 'C') || (pw == 'D') || (pw == 'E') || (pw == 'F') || (pw == 'G') || (pw == 'H') || (pw == 'I') || (pw == 'J') || (pw == 'K') || (pw == 'L') || (pw == 'M') || (pw == 'N') || (pw == 'O') || (pw == 'P') || (pw == 'Q') || (pw == 'R') || (pw == 'S') || (pw == 'T') || (pw == 'U') || (pw == 'V') || (pw == 'W') || (pw == 'X') || (pw == 'Y') || (pw == 'Z')){
            hb = 1;
        }else{
            angka = 1;
        }
    }

    hasil(angka, hk, hb, n);

    return 0;
}
#include <stdio.h>

int main(){
    int D, M;
    scanf("%d %d", &D, &M);

    while(D >= 0 && M >= 0 && D != M){
        int subsM = 0, subsD = 0;
        int tempD = D, tempM = M;

        subsM += tempD % 10;
        subsD += tempM % 10;

        while(tempD >= 10){
            tempD /= 10;
        }
        subsM += tempD;

        while(tempM >= 10){
            tempM /= 10;
        }
        subsD += tempM;

        D -= subsD;
        M -= subsM;
        
    }

    if(D == M){
        printf("Wattles\n");
    }else if(D < 0){
        printf("Mebel\n");
    }else{
        printf("Deeper\n");
    }

    return 0;

}
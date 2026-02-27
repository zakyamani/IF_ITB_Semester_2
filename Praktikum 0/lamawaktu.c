#include <stdio.h>

int main(){
    int HH, MM, SS;
    scanf("%d %d %d", &HH, &MM, &SS);
    int lamaH = 0;
    int lamaM = 0;
    int lamaS = 0;
    lamaH -= HH;
    lamaM -= MM;
    lamaS -= SS;

    scanf("%d %d %d", &HH, &MM, &SS);
    lamaH += HH;
    lamaM += MM;
    lamaS += SS;

    printf("%d %d %d\n", lamaH, lamaM, lamaS);
    return 0;


}
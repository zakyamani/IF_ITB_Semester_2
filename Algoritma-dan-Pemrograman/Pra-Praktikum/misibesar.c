#include <stdio.h>

int main(){
    int d1,m1,y1,d2,m2,y2;
    scanf("%d %d %d", &d1, &m1, &y1);

    while(d1 < 1 || d1 > 31 || m1 < 1 || m1 > 12 || y1 < 1){
        printf("Tanggal tidak valid\n");
        scanf("%d %d %d", &d1, &m1, &y1);
    }

    scanf("%d %d %d", &d2, &m2, &y2);
    while(d2 < 1 || d2 > 31 || m2 < 1 || m2 > 12 || y2 < 1 || y2 < y1 || (y2 == y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1)){
        if(d2 < 1 || d2 > 31 || m2 < 1 || m2 > 12 || y2 < 1 ){
            printf("Tanggal tidak valid\n");
        }else{
            printf("%d %d %d Lebih dulu dari pada %d %d %d\n", d2, m2, y2, d1, m1, y1);
        }
        scanf("%d %d %d", &d2, &m2, &y2);
    }
    int selisih = 0;
    selisih += (y2 - y1) * 365;
    selisih += (m2 - m1) * 30;
    selisih += (d2 - d1);

    printf("%d", selisih);
}
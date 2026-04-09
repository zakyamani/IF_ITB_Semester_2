#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *data1 = fopen("data1.txt", "r");
    int size1;
    fscanf(data1, "%d ", &size1);
    int angka1[size1];
    for(int i=0; i<size1; i++){
        fscanf(data1, "%d ", &angka1[i]);
    }
    fclose(data1);
    

    FILE *data2 = fopen("data2.txt", "r");
    int size2;
    fscanf(data2, "%d ", &size2);
    int angka2[size2];
    for(int i=0; i<size2; i++){
        fscanf(data2, "%d ", &angka2[i]);
    }
    fclose(data2);
    

    int size = size1 + size2;
    int sorted[size];
    int current1 = 0, current2 = 0;
    for(int i=0; i<size; i++){
        if(angka1[current1] <= angka2[current2]){
            sorted[i] = angka1[current1];
            current1++;
        }else{
            sorted[i] = angka2[current2];
            current2++;
        }
    }
    

    for(int i=0; i<size; i++){
        printf("%d", sorted[i]);
        if(i < size - 1){
            printf(" ");
        }else{
            printf("\n");
        }
    }
    return 0;
    
}
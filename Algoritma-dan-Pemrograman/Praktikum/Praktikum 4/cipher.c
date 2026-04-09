#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *kunci = fopen("kunci.txt", "r");
    char origin[26], encrypt[26];
    for(int i=0; i<26; i++){
        fscanf(kunci, "%c ", &origin[i]);
        fscanf(kunci, "%c ", &encrypt[i]);
    }

    fclose(kunci);

    FILE *cipher = fopen("ciphertext.txt", "r");
    char encrypted[1000];
    char kar;
    char totalKar = 0;
    for(int i=0; i<1000; i++){
        fscanf(cipher, "%c", &kar);
        if(kar == '.'){
            break;
        }
        encrypted[i] = kar;
        totalKar++;
    }
    
    totalKar--;

    char translated[totalKar];

    for(int i=0; i<totalKar; i++){
        translated[i] = ' ';
        for(int j=0; j<26; j++){
            if(encrypted[i] == encrypt[j]){
                translated[i] = origin[j];
                break;
            }
        }
    }

    for(int i=0; i<totalKar; i++){
        printf("%c", translated[i]);
    }
    printf("\n");
    return 0;

}
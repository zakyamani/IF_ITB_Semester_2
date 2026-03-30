#include <stdio.h>
#include <string.h>

int main(){
    char s[1001];
    scanf("%s", &s);

    int jumlah[26];
    for(int i = 0; i<26; i++){
        jumlah[i] = 0;
    }

    for(int i=0; i<1001; i++){
        if(s[i] == '\0'){
            break;
        }
        for(int j=0; j<26; j++){
            if(s[i] == ('a' + j)){
                jumlah[j]++;
                break;
            }
        }
    }
    int ganjil = 0;
    for(int i = 0; i<26; i++){
        //printf("%d\n", jumlah[i]);
        ganjil += (jumlah[i] % 2);
    }
    //printf("%d\n", ganjil);
    if(ganjil > 1){
        printf("NO");
    }else{
        printf("YES");
    }

}
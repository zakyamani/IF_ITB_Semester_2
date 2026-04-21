#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    for(int i=n-1; i>=1; i--){
        for(int j=i+1; j>=1; j--){
            for(int k=1; k<j; k++){
                printf(" ");
            }
            for(int k=1; k<=((n-j)*2)+1; k++){
                printf("*");
            }
            printf("\n");
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=(n-2); j++){
            printf(" ");
        }
        for(int j=1; j<=3; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;

}
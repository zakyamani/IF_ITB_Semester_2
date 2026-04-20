#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tester.h"
#define ll long long


int main() {
    init();
    FILE *katalog = fopen("katalog.txt", "r");
    FILE *transaksi = fopen("transaksi.txt", "r");

    char item_id[100][100];
    char nama_item[100][100];
    ll harga[100];

    char str[100];
    ll num;

    ll total_barang = 0;
    for(ll i=0; i<100; i++){
        fscanf(katalog, "%s ", str);
        if(str[0] == '.'){
            break;
        }
        total_barang++;
        strcpy(item_id[i], str);
        fscanf(katalog, "%s ", str);
        strcpy(nama_item[i], str);
        fscanf(katalog, "%lld", &num);
        harga[i] = num;
    }

    
    fclose(katalog);

    char id_terjual[1000][100];
    ll jumlah_terjual[1000];
    ll total_transaksi = 0;
    for(ll i=0; i<1000; i++){
        fscanf(transaksi, "%s ", str);
        if(str[0] == '.'){
            break;
        }
        total_transaksi++;
        strcpy(id_terjual[i], str);
        fscanf(transaksi, "%lld", &num);
        jumlah_terjual[i] = num;
    }



    fclose(transaksi);

    ll total_terjual[total_barang];
    for(ll i=0; i<total_barang; i++){
        total_terjual[i] = 0;
    }
    for(ll i=0; i<total_transaksi; i++){
        for(ll j=0; j<total_barang; j++){
            if(!strcmp(id_terjual[i], item_id[j])){
                total_terjual[j] += jumlah_terjual[i];
                break;
            }
        }
    }



    ll total_harga[total_barang];
    ll total_semuanya = 0;
    for(ll i=0; i<total_barang; i++){
        total_harga[i] = (ll)harga[i] * total_terjual[i];
        total_semuanya += total_harga[i];
    }

    char urutan[total_barang][100];
    for(ll i=0; i<total_barang; i++){
        strcpy(urutan[i], item_id[i]);
    }

    for(ll i=0; i<total_barang; i++){
        for(ll j=total_barang - 1; j>0; j--){
            if(strcmp(urutan[j], urutan[j-1]) < 0){
                char sementara[100];
                strcpy(sementara, urutan[j]);
                strcpy(urutan[j], urutan[j-1]);
                strcpy(urutan[j-1], sementara);
            }
        }
    }

    for(ll i=0; i<total_barang; i++){
        for(ll j=0; j<total_barang; j++){
            if(!strcmp(urutan[i], item_id[j])){
                printf("%s %lld\n", nama_item[j], total_harga[j]);
                break;
            }
        }
    }

    printf("TOTAL %lld\n", total_semuanya);
    return 0;
}
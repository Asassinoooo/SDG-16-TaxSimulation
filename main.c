#include <stdio.h>

//batas  include

//batas struct
void printMainMenu(){
    puts("Pilih Menu: \n");
    puts("1. Hitung pajak penghasilan\n");
    puts("2. Hitung pajak penghasilan UMKM\n");
    puts("3. Rekapitulasi Pajak\n");
    printf("Pilihan anda: ");
}
//batas function lainnya
int main(){
    int pilihan;
    puts("Welcome to Simulasi Pajak Indonesia");
    printMainMenu();
    scanf("%d",&pilihan);
    
    return 0;
}

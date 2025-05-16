#include <stdio.h>
#include <stdlib.h>
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
    mainMenu: 
    printMainMenu();
    scanf("%d",&pilihan);
    switch(pilihan){
        case 1:
            //function pajak penghasilan
            break;

        case 2:
            //function pajak penghasilan UMKM
            break;

        case 3:
            //function untuk print data yang sudah dikumpulkan
            break;

        default:
        puts("Invalid choice\n");
        goto mainMenu;
        break;

    }
    return 0;
}

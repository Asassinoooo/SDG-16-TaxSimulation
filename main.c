#include <stdio.h>
#include <stdlib.h>
//batas  include
typedef enum{
    FALSE = 0,
    TRUE = 1
}bool;

typedef enum{
    TK,
    K,
    KI,
}PTKP;
typedef struct{
    char namaLengkap[50];
    unsigned long long int nik;
}user;

typedef struct{
    user pekerja;
    bool statusPernikahan;
    int jumlahTanggunganAnak;
    unsigned long long int penghasilanBruto;
    unsigned long long int penghasilanNeto;
    unsigned long long int bonusTunjangan;
    unsigned long long int penghasilanLainnya;
    PTKP statusPTKP;
    unsigned long long int tarifPPH;
}pegawai;

typedef struct{
    user pengusaha;
    char namaUsaha[50];
    char jenisUsaha[50];
    bool badanUsaha; //jika omzet diatas 4.8M, badan usaha kena pph 22%, individu progresif
    unsigned long long int omzetUsaha;
    unsigned long long int labaBersih;
    unsigned long long int PPN; //hanya untuk usaha omzet diatas 4.8M
    unsigned long long int PPH;
}UMKM;
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

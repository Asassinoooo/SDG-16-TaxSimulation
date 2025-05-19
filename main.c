#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void hitungPajakUMKM() {
    UMKM umkm;

    printf("Masukkan nama lengkap: ");
    getchar();
    fgets(umkm.pengusaha.namaLengkap, sizeof(umkm.pengusaha.namaLengkap), stdin);
    strtok(umkm.pengusaha.namaLengkap, "\n");

    printf("Masukkan NIK: ");
    scanf("%llu", &umkm.pengusaha.nik);

    printf("Masukkan nama usaha: ");
    getchar();
    fgets(umkm.namaUsaha, sizeof(umkm.namaUsaha), stdin);
    strtok(umkm.namaUsaha, "\n");

    printf("Masukkan jenis usaha: ");
    getchar();
    fgets(umkm.jenisUsaha, sizeof(umkm.jenisUsaha), stdin);
    strtok(umkm.jenisUsaha, "\n");

    printf("Masukkan omzet: ");
    scanf("%llu", &umkm.omzetUsaha);

    printf("Masukkan laba bersih: ");
    scanf("%llu", &umkm.labaBersih);

    if(umkm.omzetUsaha > 400000000000){
        umkm.badanUsaha = TRUE;
        umkm.PPN = umkm.omzetUsaha * 11 / 100;
        umkm.PPH = umkm.labaBersih * 22 / 100;
    } else {
        umkm.badanUsaha = FALSE;
        umkm.PPN = 0;
        umkm.PPH = umkm.omzetUsaha * 0.5 / 100;
    }
    printf("\n---REKAP PAJAK PENGHASILAN UMKM---\n");
    printf("Nama Pengusaha  : %s\n", umkm.pengusaha.namaLengkap);
    printf("NIK Pengusaha   : %llu\n", umkm.pengusaha.nik);
    printf("Nama Usaha      : %s\n", umkm.namaUsaha);
    printf("Jenis Usaha     : %s\n", umkm.jenisUsaha);
    printf("Omzet Usaha     : Rp.%llu\n", umkm.omzetUsaha);
    printf("Laba Bersih     : Rp.%llu\n", umkm.labaBersih);
    printf("Potongan PPN    : Rp.%llu\n", umkm.PPN);
    printf("Potongan PPh    : Rp.%llu\n", umkm.PPH);
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
            hitungPajakUMKM();
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

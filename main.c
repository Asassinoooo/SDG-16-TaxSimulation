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
}PEGAWAI;

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
    puts("4. Exit Program\n");
    printf("Pilihan anda: ");
}

void hitungPajakUMKM(UMKM* umkm, int umkmCount) {
    umkm = realloc(umkm,umkmCount*sizeof(UMKM));
    umkmCount--;
    printf("Masukkan nama lengkap: ");
    getchar();
    fgets((umkm+umkmCount)->pengusaha.namaLengkap, sizeof((umkm+umkmCount)->pengusaha.namaLengkap), stdin);
    strtok((umkm+umkmCount)->pengusaha.namaLengkap, "\n");

    printf("Masukkan NIK: ");
    scanf("%llu", &(umkm+umkmCount)->pengusaha.nik);

    printf("Masukkan nama usaha: ");
    getchar();
    fgets((umkm+umkmCount)->namaUsaha, sizeof((umkm+umkmCount)->namaUsaha), stdin);
    strtok((umkm+umkmCount)->namaUsaha, "\n");

    printf("Masukkan jenis usaha: ");
    fgets((umkm+umkmCount)->jenisUsaha, sizeof((umkm+umkmCount)->jenisUsaha), stdin);
    strtok((umkm+umkmCount)->jenisUsaha, "\n");

    printf("Masukkan omzet: ");
    scanf("%llu", &(umkm+umkmCount)->omzetUsaha);

    printf("Masukkan laba bersih: ");
    scanf("%llu", &(umkm+umkmCount)->labaBersih);

    if((umkm+umkmCount)->omzetUsaha > 4800000000){
        (umkm+umkmCount)->badanUsaha = TRUE;
        (umkm+umkmCount)->PPN = (umkm+umkmCount)->omzetUsaha * 11 / 100;
        (umkm+umkmCount)->PPH = (umkm+umkmCount)->labaBersih * 22 / 100;
    } else {
        (umkm+umkmCount)->badanUsaha = FALSE;
        (umkm+umkmCount)->PPN = 0;
        (umkm+umkmCount)->PPH = (umkm+umkmCount)->omzetUsaha * 0.5 / 100;
    }
    printf("\n---REKAP PAJAK PENGHASILAN UMKM---\n");
    printf("Nama Pengusaha  : %s\n", (umkm+umkmCount)->pengusaha.namaLengkap);
    printf("NIK Pengusaha   : %llu\n", (umkm+umkmCount)->pengusaha.nik);
    printf("Nama Usaha      : %s\n", (umkm+umkmCount)->namaUsaha);
    printf("Jenis Usaha     : %s\n", (umkm+umkmCount)->jenisUsaha);
    printf("Omzet Usaha     : Rp.%llu\n", (umkm+umkmCount)->omzetUsaha);
    printf("Laba Bersih     : Rp.%llu\n", (umkm+umkmCount)->labaBersih);
    printf("Potongan PPN    : Rp.%llu\n", (umkm+umkmCount)->PPN);
    printf("Potongan PPh    : Rp.%llu\n", (umkm+umkmCount)->PPH);
    puts("");
}
//batas function lainnya
int main(){
    int pilihan;
    UMKM * umkm = malloc(sizeof(UMKM));
    PEGAWAI * pegawai = malloc(sizeof(PEGAWAI));
    int umkmCount = 0, pegawaiCount = 0;
    while(pilihan != 4){
        puts("Welcome to Simulasi Pajak Indonesia");
        printMainMenu();
        scanf("%d",&pilihan);
        switch(pilihan){
            case 1:
                //function pajak penghasilan
                pegawaiCount++;
                break;

            case 2:
                //function pajak penghasilan UMKM
                umkmCount++;
                hitungPajakUMKM(umkm,umkmCount);
                break;

            case 3:
                //function untuk print data yang sudah dikumpulkan
                break;

            case 4:
                puts("program closed\n");
                return 0;
                break;

            default:
            puts("Invalid choice\n");
            break;

    }}
    return 0;
}

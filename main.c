#include <stdio.h>
#include <stdlib.h>
#include <string.h>
unsigned long long juta = 1000000;
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
    int umurUsaha;
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

void hitungPajakProgresifPegawai (PEGAWAI* pegawai, int pegawaiCount){
    if((pegawai + pegawaiCount)->penghasilanBruto <= 60*juta){
        (pegawai + pegawaiCount)->tarifPPH += (pegawai + pegawaiCount)->penghasilanBruto * 5 / 100; 
        }
        else if((pegawai + pegawaiCount)->penghasilanBruto <= 250*juta){
            (pegawai + pegawaiCount)->tarifPPH += 60*juta * 5 / 100;
            (pegawai + pegawaiCount)->tarifPPH += ((pegawai + pegawaiCount)->penghasilanBruto - 60*juta) * 15 / 100;
        }
        else if((pegawai + pegawaiCount)->penghasilanBruto <= 500*juta){
            (pegawai + pegawaiCount)->tarifPPH += 60*juta * 5 / 100;
            (pegawai + pegawaiCount)->tarifPPH += (250-60)*juta * 15 / 100;
            (pegawai + pegawaiCount)->tarifPPH += ((pegawai + pegawaiCount)->penghasilanBruto - 250*juta) * 25 / 100;
        }
        else if((pegawai + pegawaiCount)->penghasilanBruto <= 5000*juta){
            (pegawai + pegawaiCount)->tarifPPH += 60*juta * 5 / 100;
            (pegawai + pegawaiCount)->tarifPPH += (250-60)*juta * 15 / 100;
            (pegawai + pegawaiCount)->tarifPPH += (500-250)*juta * 25 / 100;
            (pegawai + pegawaiCount)->tarifPPH += ((pegawai + pegawaiCount)->penghasilanBruto - 500*juta) * 30 / 100;
        }
        else {
            (pegawai + pegawaiCount)->tarifPPH += 60*juta * 5 / 100;
            (pegawai + pegawaiCount)->tarifPPH += (250-60)*juta * 15 / 100;
            (pegawai + pegawaiCount)->tarifPPH += (500-250)*juta * 25 / 100;
            (pegawai + pegawaiCount)->tarifPPH += (5000-500)*juta * 30 / 100;
            (pegawai + pegawaiCount)->tarifPPH += ((pegawai + pegawaiCount)->penghasilanBruto - 5000*juta) * 35 / 100;
        }
}
void hitungPajakPegawai(PEGAWAI * pegawai, int pegawaiCount){
	pegawai = realloc(pegawai, pegawaiCount * sizeof(PEGAWAI));
    pegawaiCount--;
    printf("Masukkan nama lengkap: ");
    getchar();
    fgets((pegawai + pegawaiCount)->pekerja.namaLengkap, sizeof((pegawai + pegawaiCount)->pekerja.namaLengkap), stdin);
    strtok((pegawai + pegawaiCount)->pekerja.namaLengkap, "\n");

    printf("Masukkan NIK: ");
    scanf("%llu", &(pegawai + pegawaiCount)->pekerja.nik);

    printf("Masukkan status pernikahan \n(Tidak Kawin : 0, Kawin : 1, Kawin Istri Bekerja : 2): ");
    scanf("%llu", &(pegawai + pegawaiCount)->statusPTKP);
    if ((pegawai + pegawaiCount)->statusPTKP == K || (pegawai + pegawaiCount)->statusPTKP == KI) {
        (pegawai + pegawaiCount)->statusPernikahan = TRUE;
    } else {
        (pegawai + pegawaiCount)->statusPernikahan = FALSE;
    }

    printf("Masukkan jumlah tanggungan anak (maksimal 3): ");
    scanf("%llu", &(pegawai + pegawaiCount)->jumlahTanggunganAnak);

    printf("Masukkan penghasilan bruto: ");
    scanf("%llu", &(pegawai + pegawaiCount)->penghasilanBruto);

    printf("Masukkan penghasilan lainnya: ");
    scanf("%llu", &(pegawai + pegawaiCount)->penghasilanLainnya);

    printf("Masukkan bonus/tunjangan: ");
    scanf("%llu", &(pegawai + pegawaiCount)->bonusTunjangan);

    (pegawai + pegawaiCount)->penghasilanNeto = (pegawai + pegawaiCount)->penghasilanBruto +
                                                (pegawai + pegawaiCount)->penghasilanLainnya +
                                                (pegawai + pegawaiCount)->bonusTunjangan;

    if ((pegawai + pegawaiCount)->statusPTKP = TK) {
        if ((pegawai + pegawaiCount)->penghasilanNeto < 54*juta + (pegawai + pegawaiCount)->jumlahTanggunganAnak*4500000) {
        (pegawai + pegawaiCount)->tarifPPH = 0; }
        else {
            hitungPajakProgresifPegawai(pegawai, pegawaiCount);
        }
    } else if ((pegawai + pegawaiCount)->statusPTKP = K) {
        if ((pegawai + pegawaiCount)->penghasilanNeto < 54*juta + (pegawai + pegawaiCount)->jumlahTanggunganAnak*4500000 + 4500000) {
        (pegawai + pegawaiCount)->tarifPPH = 0; }
        else {
            hitungPajakProgresifPegawai(pegawai, pegawaiCount);
        }
    } else if ((pegawai + pegawaiCount)->statusPTKP = K) {
        if ((pegawai + pegawaiCount)->penghasilanNeto < 108*juta + (pegawai + pegawaiCount)->jumlahTanggunganAnak*4500000 + 4500000) {
        (pegawai + pegawaiCount)->tarifPPH = 0; }
        else {
            hitungPajakProgresifPegawai(pegawai, pegawaiCount);
        }
    }

    printf("\n---REKAP PAJAK PENGHASILAN PEGAWAI---\n");
    printf("Nama Pegawai    : %s\n", (pegawai + pegawaiCount)->pekerja.namaLengkap);
    printf("NIK Pegawai     : %llu\n", (pegawai + pegawaiCount)->pekerja.nik);
    printf("Penghasilan Neto: Rp.%llu\n", (pegawai + pegawaiCount)->penghasilanNeto);
    printf("Potongan PPh    : Rp.%llu\n", (pegawai + pegawaiCount)->tarifPPH);
    puts("");
}

void hitungPajakProgresif (UMKM* umkm, int umkmCount){
    if((umkm+umkmCount)->labaBersih <= 60*juta){
        (umkm+umkmCount)->PPH += (umkm+umkmCount)->labaBersih * 5 / 100; 
    }
    else if((umkm+umkmCount)->labaBersih <= 250*juta){
        (umkm+umkmCount)->PPH += 60*juta * 5 / 100;
        (umkm+umkmCount)->PPH += ((umkm+umkmCount)->labaBersih - 60*juta) * 15 / 100;
    }
    else if((umkm+umkmCount)->labaBersih <= 500*juta){
        (umkm+umkmCount)->PPH += 60*juta * 5 / 100;
        (umkm+umkmCount)->PPH += (250-60)*juta * 15 / 100;
        (umkm+umkmCount)->PPH += ((umkm+umkmCount)->labaBersih - 250*juta) * 25 / 100;
    }
    else if((umkm+umkmCount)->labaBersih <= 5000*juta){
        (umkm+umkmCount)->PPH += 60*juta * 5 / 100;
        (umkm+umkmCount)->PPH += (250-60)*juta * 15 / 100;
        (umkm+umkmCount)->PPH += (500-250)*juta * 25 / 100;
        (umkm+umkmCount)->PPH += ((umkm+umkmCount)->labaBersih - 500*juta) * 30 / 100;
    }
    else {
        (umkm+umkmCount)->PPH += 60*juta * 5 / 100;
        (umkm+umkmCount)->PPH += (250-60)*juta * 15 / 100;
        (umkm+umkmCount)->PPH += (500-250)*juta * 25 / 100;
        (umkm+umkmCount)->PPH += (5000-500)*juta * 30 / 100;
        (umkm+umkmCount)->PPH += ((umkm+umkmCount)->labaBersih - 5000*juta) * 35 / 100;
    }
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

    printf("Apakah usaha anda milik Badan Usaha (Jika ya ketik '1', Jika perseorangan ketik '0'): ");
    scanf("%d",&(umkm+umkmCount)->badanUsaha);

    printf("Berapa tahun sudah anda merintis usaha anda: ");
    scanf("%d",&(umkm+umkmCount)->umurUsaha);

    if((umkm+umkmCount)->badanUsaha = TRUE){
        if((umkm+umkmCount)->omzetUsaha >= 4800*juta){
            (umkm+umkmCount)->PPH = (umkm+umkmCount)->labaBersih * 22 / 100;
            (umkm+umkmCount)->PPN = (umkm+umkmCount)->omzetUsaha * 12 / 100; //ppn 12 persen
        }
        else if((umkm+umkmCount)->umurUsaha > 3){ //WP Usaha wajib pajak untuk diatas 3 tahun
            if((umkm+umkmCount)->omzetUsaha < 500*juta ){ //omzet dibawah 500 juta bebas pajak
                (umkm+umkmCount)->PPH = 0;
                (umkm+umkmCount)->PPN = 0;
            }
            else{
            (umkm+umkmCount)->PPH = (umkm+umkmCount)->labaBersih * 22 / 100;
            (umkm+umkmCount)->PPN = 0;
            }
        }
        else{
            if((umkm+umkmCount)->omzetUsaha < 500*juta ){ //omset dibawah 500 juta bebas pajak
                (umkm+umkmCount)->PPH = 0;
                (umkm+umkmCount)->PPN = 0;
            }
            else{
                (umkm+umkmCount)->PPH = (umkm+umkmCount)->omzetUsaha * 0.5/100;
                (umkm+umkmCount)->PPN = 0;
            }
            
        }
    }
    else {
        if((umkm+umkmCount)->omzetUsaha >= 4800*juta){
            hitungPajakProgresif(umkm,umkmCount);
            (umkm+umkmCount)->PPN = (umkm+umkmCount)->omzetUsaha * 12 / 100; //ppn 12 persen
        }
        else if((umkm+umkmCount)->umurUsaha > 3){ //WP Usaha wajib pajak untuk diatas 3 tahun
            if((umkm+umkmCount)->omzetUsaha < 500*juta ){ //omzet dibawah 500 juta bebas pajak
                (umkm+umkmCount)->PPH = 0;
                (umkm+umkmCount)->PPN = 0;
            }
            else{
            hitungPajakProgresif(umkm,umkmCount);
            (umkm+umkmCount)->PPN = 0;
            }
        }
        else{
            if((umkm+umkmCount)->omzetUsaha < 500*juta ){ //omset dibawah 500 juta bebas pajak
                (umkm+umkmCount)->PPH = 0;
                (umkm+umkmCount)->PPN = 0;
            }
            else{
                (umkm+umkmCount)->PPH = (umkm+umkmCount)->omzetUsaha * 0.5/100;
                (umkm+umkmCount)->PPN = 0;
            }
            
        }  
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
void rekapitulasiPajakPegawai(PEGAWAI * pegawai,int index){
    printf("\n---REKAP PAJAK PENGHASILAN PEGAWAI KE %d---\n", index+1);
    printf("Nama Pegawai        : %s\n", (pegawai+index)->pekerja.namaLengkap);
    printf("NIK Pegawai         : %llu\n", (pegawai+index)->pekerja.nik);
    printf("Status Pernikahan   : %s\n", (pegawai+index)->statusPernikahan ? "True" : "False");
    printf("Jumlah Tanggungan   : %d\n", (pegawai+index)->jumlahTanggunganAnak);
    printf("Penghasilan Kotor   : Rp.%llu\n", (pegawai+index)->penghasilanBruto);
    printf("Penghasilan Bersih  : Rp.%llu\n", (pegawai+index)->penghasilanNeto);
    printf("Tunjangan           : Rp.%llu\n", (pegawai+index)->bonusTunjangan);
    printf("Penghasilan Lainnya : Rp.%llu\n", (pegawai+index)->penghasilanLainnya);
    if ((pegawai+index)->statusPTKP == TK) {
        printf("Status PTKP         : TK\n");
    } else if ((pegawai+index)->statusPTKP == K) {
        printf("Status PTKP         : K\n");
    } else {
        printf("Status PTKP         : KI\n");
    } 
    printf("Potongan PPh        : Rp.%llu\n", (pegawai+index)->tarifPPH);    
    puts("");	
}
void rekapitulasiPajakUMKM(UMKM * umkm,int index){
    printf("\n---REKAP PAJAK PENGHASILAN UMKM KE %d---\n", index+1);
    printf("Nama Pengusaha  : %s\n", (umkm+index)->pengusaha.namaLengkap);
    printf("NIK Pengusaha   : %llu\n", (umkm+index)->pengusaha.nik);
    printf("Nama Usaha      : %s\n", (umkm+index)->namaUsaha);
    printf("Jenis Usaha     : %s\n", (umkm+index)->jenisUsaha);
    printf("Omzet Usaha     : Rp.%llu\n", (umkm+index)->omzetUsaha);
    printf("Laba Bersih     : Rp.%llu\n", (umkm+index)->labaBersih);
    printf("Potongan PPN    : Rp.%llu\n", (umkm+index)->PPN);
    printf("Potongan PPh    : Rp.%llu\n", (umkm+index)->PPH);
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
                hitungPajakPegawai(pegawai,pegawaiCount);
                break;

            case 2:
                //function pajak penghasilan UMKM
                umkmCount++;
                hitungPajakUMKM(umkm,umkmCount);
                break;

            case 3:
				//function rekapitulasi pajak
					{
                	int i;
                	for(i=0;i<pegawaiCount;i++){
                    	rekapitulasiPajakPegawai(pegawai,i);
                	}
               		for(i=0;i<umkmCount;i++){
                    	rekapitulasiPajakUMKM(umkm,i);
               		}
                	        		
					}
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

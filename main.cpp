#include <iostream>
#include <stdio.h>
#include "GAANTRE.h"

int main() {
	
	int opsi = 1;
	char opsichar;
	int display = 1;
	
	while (opsi != 0) {
		switch (display) {
			case 1:
				printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                Selamat Datang di GaAntre                             |+|\n");
                printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n");
                printf("|+|Lanjut? (y/n) ");
                scanf(" %c", &opsichar);
                if (opsichar == 'y') {
                	display = 2;
				} else
				if (opsichar == 'n') {
					opsi = 0;
				}
			case 2:
				system("cls");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         GaAntre                                      |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         Sign Up                                      |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Sudah punya akun?                                                                     |+|\n");
				printf("|+|1. Sudah                                                                              |+|\n");
				printf("|+|2. Belum                                                                              |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Pilih opsi: ");
				scanf("%d", &opsi);
				if (opsi == 1) {
					display = 4;
				} else 
				if (opsi == 2) {
					display = 3;
				}
				break;

			case 3:
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                       GaAntre                                        |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                      Buat Akun                                       |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Silahkan buat akun baru                                                               |+|\n");
				membuatAkun(&display);
				break;
				

			case 4:
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                        GaAntre                                       |+|\n");
				printf("|+|                                Ga Perlu CAPE-CAPE Ngantre                            |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");                                                                                                                                                                   
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         LOGIN                                        |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|Silahkan Login                                                                        |+|\n");
				login(&display);
				break;
	
			case 5:
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                       GaAntre                                        |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                         ADMIN                                        |+|\n");
				printf("|+|                                                                                      |+|\n");	
				printf("|+|======================================================================================|+|\n");
				printf("|+|1. Mendaftarkan                                                                       |+|\n");
				printf("|+|2. Hapus Antrian                                                                      |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|Pilih opsi: ");
				scanf("%d", &opsi);
				if (opsi == 1){
					daftarAdmin();
				}else if (opsi == 2){
					popAntrian();
				}
				opsi = 0;
				break;
			case 6:
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                       GaAntre                                        |+|\n");
				printf("|+|                             Kamu Ga Perlu CAPE-CAPE Ngantre                          |+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|======================================================================================|+|\n");
				printf("|+|                                                                                      |+|\n");
				printf("|+|                                      PENGGUNA                                        |+|\n");
				printf("|+|                                                                                      |+|\n");	
				printf("|+|======================================================================================|+|\n");
				printf("|+|1. Daftar Antrian                                                                     |+|\n");
				printf("|+|2. Tampilkan Nomor Antrian terkini                                                    |+|\n");
				printf("|+|0. Keluar                                                                             |+|\n");
				printf("|+|Pilih opsi: ");
				scanf("%d", &opsi);
				if (opsi == 1){
					daftarPengguna();
				}else if (opsi == 2){
					antrianSekarang();
				}
				opsi = 0;
				break;
			case 7 :
				
			default:
				printf("Pilih opsi yang sesuai!");
		}
	}
	


	return 0;
}

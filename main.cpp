#include "GAANTRE.h"

int main() {
	int opsi = 1, display = 1, jamBuka, menitBuka, jamTutup, menitTutup, maksPasien, noAntrian = 0, urutUser;
	bool running = true;
	bool valid, setTree = false;
	char edit;
	char waktuBuka[6], waktuTutup[6];
	address root = NULL;
	account sedangLogin;
	char filename[30];
	Pasien pasienSelesai;
	buatFilePembukaan();
	buatFilePasien();
	dataPendaftaranToday(waktuBuka, waktuTutup, &maksPasien);
	aturJamMenit (waktuBuka, waktuTutup, &jamBuka, &menitBuka, &jamTutup, &menitTutup);

	
	while (running) {
		switch (display) {
			case 1:
				displayAwal (&display);
				
			case 2:
				displaySignUp (&valid, &display, &running);
				break;
				
			case 3:
				displayBuatAkun (&display);
				break;
				
			case 4:
				displayLogin (&display, &sedangLogin);
				break;
	
			case 5:
                printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                        GaAntre                                       |+|\n");
                printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
                printf("|+|No Antrian Sekarang: %04d                                                             |+|\n", noAntrian);
                printf("|+|======================================================================================|+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|                                         MENU                                         |+|\n");
                printf("|+|                                                                                      |+|\n");
                printf("|+|======================================================================================|+|\n");
                printf("|+|1. Daftar Antrian                                                                     |+|\n");
                printf("|+|2. Mengeluarkan pasien yang selesai dari antrian                                      |+|\n");
                printf("|+|3. Pemberian nomor antrian                                                            |+|\n");
                printf("|+|4. Menentukan pembukaan dan penutupan pendaftaran                                     |+|\n");
                printf("|+|0. Keluar                                                                             |+|\n");
                printf("|+|--------------------------------------------------------------------------------------|+|\n");
                printf("|+|Pilih opsi: ");
                valid = false;
				do {
			        if (scanf("%d", &opsi) == 1) {
			            valid = true;
			        } else {
			            printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
			            printf("|+|Pilih opsi: ");
			            clearBuffer();
			        }
			    } while (!valid);
			    
			    
				if (opsi == 1) {
					//system("cls");
                    display = 6;
                } else
				if (opsi == 2) {
					if (!sudahDibuka()) {
						printf("|+|Mohon tentukan waktu buka dan waktu tutup pendaftaran terlebih dahulu!\n");
					} else
					if (!setTree) {
						printf("|+|Antrian belum dibangun! Bangun antrian terlebih dahulu!\n");
					} else
					if (root != NULL) {
						root = pop(root, &pasienSelesai);
						printf("|+|Pasien yang sedang konsultasi\n");
                   		printf("|+|Nama: %s (%d)\n|+|\n|+|\n", pasienSelesai.nama, pasienSelesai.prioritas);
                   		noAntrian = pasienSelesai.urutan;
					} else {
						printf("|+|Antrian sudah kosong!");
					}
                    
                    
                    
//                    displayTree(root);
                    printf("|+|");
                    system("pause");
                    //system("cls");
                    display = 5;
                    
                } else 
				if (opsi == 3) {
					updateTime();
					if (!sudahDibuka()) {
						printf("|+|Mohon tentukan waktu buka dan waktu tutup pendaftaran terlebih dahulu!\n");
					} else
					if (waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)) {
						printf("|+|Tunggu setelah pendaftaran ditutup pada pukul %s!\n", waktuTutup);
						display = 5;
					} else {
						if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (jamBuka * 60 + menitBuka)) {
							printf("|+|Pendaftaran belum dibuka! Tidak dapat membangun antrian!\n");
						} else
						if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (jamTutup * 60 + menitTutup)) {
							sortAntrian(&root);
	                		displayTree(root); 
	                		printf("|+|");
	                		system("pause");
	                		//system("cls");
	                		display = 5;
	                		setTree = true;
						}
					}
			
					
				} else
				if (opsi == 4) {
					if (sudahDibuka()) {
					printf("|+|Waktu pendaftaran hari ini telah ditentukan! %s - %s\n", waktuBuka, waktuTutup);
					system("pause");
					} else {
						while (!sudahDibuka()) {
							printf("|+|Masukan maksimal jumlah pasien: ");
							scanf("%d", &maksPasien);
							clearBuffer();
							valid = false;
							while (!valid) {
							    printf("|+|Masukan waktu buka pendaftaran (HH:MM): ");
							    scanf("%s", waktuBuka);
							    clearBuffer();
							    if (validasiWaktu(waktuBuka, &jamBuka, &menitBuka)) {
							    	if (validasiWaktuBuka(jamBuka, menitBuka)) {
							    		valid = true;
							    		break;
									} else {
										printf("|+|Waktu pembukaan harus lebih dari waktu sekarang!\n");
									}
								} else {
									printf("Format waktu tidak valid\n");
								}
							}
							
							valid = false;
							while (!valid) {
							    printf("|+|Masukan waktu tutup pendaftaran (HH:MM): ");
							    scanf("%s", waktuTutup);
							    clearBuffer();
							    if (validasiWaktu(waktuTutup, &jamTutup, &menitTutup)) {
							    	if (validasiWaktuTutup(jamTutup, menitTutup, jamBuka, menitBuka)) {
								    	valid = true;
								    	break;
								    } else {
								    	printf("|+|Waktu penutupan harus lebih dari waktu sekarang dan waktu buka!\n");
									}
								} else {
									printf("|+|Format waktu tidak valid\n");
								}								
							} 

													
						
							printf("|+|[INFO] Anda tidak bisa mengubah waktu pendaftaran lagi setelah di submit\n");
							printf("|+|Edit? (y/n) ");
							scanf(" %c", &edit);
								
							if (edit == 'n' || edit == 'N') {
								waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup);
								simpanWaktuPendaftaran (waktuBuka, waktuTutup, maksPasien);
 								
							} 
						} 
					display = 5;
					}
					
					
				} else
				if (opsi == 0) {
					//system("cls");
					display = 2;
				} 
				break;
					
			case 6:
				displayDaftarAdmin (root, &sedangLogin, &display);
                break;
				
			case 7:
				displayMenuPengguna (&display, &valid, &noAntrian);
				break;
				
			case 8:
				if (waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)) {
					daftarPengguna(&root, &sedangLogin, &display, maksPasien);
	                //system("cls");
					display = 7;
				} else {
					if (!sudahDibuka ()) {
						printf("|+|Admin belum mengatur pembukaan pendaftaran, tidak dapat melakukan pendaftaran!\n");		
					} else
					if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (jamBuka * 60 + menitBuka)) {
						printf("|+|Pendaftaran belum dibuka! Silahkan coba lagi saat pukul %s\n", waktuBuka );
					} else
					if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (jamTutup * 60 + menitTutup)) {
						printf("|+|Mohon maaf pendaftaran hari ini telah ditutup pada pukul %s\n", waktuTutup);
					}
	                display = 7;
				}
				break;
		
			case 9:
				updateTime();
				if (setTree && (timeSekarang.tm_hour * 60 + timeSekarang.tm_min) >= (jamTutup * 60 + menitTutup)) {
					printf("|+|======================================================================================|+|\n");
			        printf("|+|                                                                                      |+|\n");
			        printf("|+|                                        GaAntre                                       |+|\n");
			        printf("|+|                               Ga Perlu CAPE-CAPE Ngantre                             |+|\n");
			        printf("|+|                                                                                      |+|\n");
			        printf("|+|======================================================================================|+|\n");
			    	printf("|+|                                                                                      |+|\n");
			        printf("|+|                                   Nomor Antrian Anda                                 |+|\n");
			        printf("|+|                                         %04d                                         |+|\n", noAntrianUser(&sedangLogin));
			        printf("|+|                                                                                      |+|\n");
			        printf("|+|======================================================================================|+|\n");
					printf("|+|Nomor antrian anda adalah %d", noAntrianUser(&sedangLogin));
                	display = 7;
				} else {
					if (!sudahDibuka()) {
						printf("|+|Admin belum mengatur pembukaan pendaftaran, tidak dapat menampilkan antrian!\n");
					} else
					if (waktuPendaftaran(jamBuka, menitBuka, jamTutup, menitTutup)) {
						printf("|+|Mohon maaf antrian belum bisa ditampilkan. Coba lagi setelah pendaftaran ditutup pukul %2d:%2d\n", jamTutup, menitTutup);
					} else 
					if ((timeSekarang.tm_hour * 60 + timeSekarang.tm_min) <= (jamBuka * 60 + menitBuka)) {
						printf("|+|Pendaftaran belum dibuka! Tidak dapat menampilkan antrian!\n");
					} else {
						printf("|+|Mohon maaf antrian belum bisa ditampilkan karena antrian belum buat\n"); // admin belum membangun antrian
					}
					display = 7;
				}
                break;
                
			default:
				printf("|+|Input tidak valid. Mohon masukkan input yang sesuai!\n");
				break;
		}
	}
	displayAkhir();
	return 0;
}


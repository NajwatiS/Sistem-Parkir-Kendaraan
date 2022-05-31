#include "Kelompok15.h"

int main() {
  int jumlah_pengendara = 0, a = 0, totalbiaya, opsi, opsi2, opsi3, kembali, ganti_biaya, jenis_mobil, jenis_motor, spi;
  char opsic[50], opsi_mobil[] = "mobil";
  int biaya[2][2] = {{4000, 2000}, {2000, 1000}};
  int diskon[2] = {15000, 7500};
  int total_pendapatan = 0;
  struct DataPengendara sort;
  int j, m, i, k, min1, hour1, day1, mon1, year1, min_diff, hour_diff, day_diff, mon_diff, year_diff;
  time_t rawtime;
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);
  int start = 0;
  List DatPengendara;
  CreateList(&DatPengendara);
  dpengendara data;
  BinTree p = NULL;

  while (1) {
    // Tampilan Halaman Utama
    if (start == 0){
      displayMenu(0);
      start = 1;
    } else displayMenu(1);

    scanf("%d", & opsi);

    // Input Data
    if (opsi == 1) {
      system("cls");
      printf("Silahkan isi data di bawah ini\n");
      printf("Nama: ");
      i = jumlah_pengendara;

      // Insert Array
      scanf(" %[^\n]s", data_pengendara[i].nama);

      do {
        printf("Jenis Kendaraan: ");
        scanf("%s", data_pengendara[i].jenis_kendaraan);
        jenis_mobil = strcmpi(data_pengendara[i].jenis_kendaraan, "Mobil"); //strcmpi: string compare insensitive untuk membangdingkan kedua variabel, memberikan
        jenis_motor = strcmpi(data_pengendara[i].jenis_kendaraan, "Motor"); //         output 0 jika kedua variabel sama tanpa memandang kapital/kecil
        if (jenis_mobil != 0 && jenis_motor != 0) {
          printf("Masukkan jenis kendaraan dengan benar! (Mobil/Motor)\n");
        }
      } while (jenis_mobil != 0 && jenis_motor != 0);

      do {
        spi = 1;
        printf("No. Plat Kendaraan: ");
        scanf(" %[^\n]s", data_pengendara[i].plat);
        if (jumlah_pengendara >= 1) {
          for (j = 0; j < jumlah_pengendara; j++) {
            spi = strcmpi(data_pengendara[i].plat, data_pengendara[j].plat);
            if (spi == 0) {
              printf("Kendaraan bernopol ini sudah dimasukkan, silahkan masukkan plat lain!\n");
              break;
            }
          }
        }
      } while (spi == 0);

      // Insert Linked List
      strcpy(data.nama, data_pengendara[i].nama);
      strcpy(data.jenis_kendaraan, data_pengendara[i].jenis_kendaraan);
      strcpy(data.plat, data_pengendara[i].plat);
      insertLast(&DatPengendara, data);

      // Print Linked List
      printf("\n====================================================\n");
      printf("\nData Kendaraan yang terparkir pada List :\n\n");
      Address P = FIRST(DatPengendara);
      while (P != NULL) {
        printf("Nama Pengendara: %s\n", INFO(P).nama);
        printf("Jenis Kendaraan: %s\n", INFO(P).jenis_kendaraan);
        printf("No. Plat Kendaraan: %s\n\n", INFO(P).plat);
        P = NEXT(P);
      }

      printf("\nData berhasil dimasukkan\n");
      jumlah_pengendara += 1;
      back();
    }

    // Mencari dan Menampilkan Rincian Bayaran Pengendara
    else if (opsi == 2) {
      system("cls");
      if (jumlah_pengendara == 0) {
        printf("Belum ada data yang tersimpan!\n");
      } else {

        // Pencarian pada array
        spi = 1;
        while (spi != 0) {
          printf("Masukkan Plat Kendaraan Anda: "); // Pemakaian searching untuk mencari data pengendara dari platnya
          scanf(" %[^\n]s", opsic);

          for (i = 0; i < jumlah_pengendara; i++) { //Linear Search

            spi = strcmpi(opsic, data_pengendara[i].plat);

            if (spi == 0) {
              k = i;
              printf("Nama Pengendara: %s\n", data_pengendara[k].nama);
              printf("Jenis Kendaraan: %s\n", data_pengendara[k].jenis_kendaraan);
              printf("No. Plat Kendaraan: %s\n\n", data_pengendara[k].plat);

              printf("Masukkan waktu Anda masuk (DD/MM/YYYY HH:MM): ");
              scanf("%d/%d/%d %d:%d", & day1, & mon1, & year1, & hour1, & min1);
              min_diff = hitung_waktu_min(min1, hour1, day1, mon1, year1);
              hour_diff = hitung_waktu_jam(min1, hour1, day1, mon1, year1);
              day_diff = hitung_waktu_hari(min1, hour1, day1, mon1, year1);
              mon_diff = hitung_waktu_bulan(min1, hour1, day1, mon1, year1);
              year_diff = hitung_waktu_tahun(min1, hour1, day1, mon1, year1);
              if (min_diff > 0) {
                hour_diff = hour_diff + 1;
              }

              if (strcmpi(opsi_mobil, data_pengendara[k].jenis_kendaraan) == 0) { // Membedakan jenis kendaraan mobil/motor
                totalbiaya = biaya[0][0] + ((hour_diff-1) * biaya[0][1]);
                if (hour_diff > 24) {
                  totalbiaya -= diskon[0];
                }
              } else {
                totalbiaya = biaya[1][0] + ((hour_diff-1) * biaya[1][1]);
                if (hour_diff > 24) {
                  totalbiaya -= diskon[1];
                }
              }
              strcpy(data_pengendara[k].nama, data_pengendara[jumlah_pengendara - 1].nama); //strcpy: string copy untuk menyalin string dari variabel pertama ke 
              strcpy(data_pengendara[k].jenis_kendaraan, data_pengendara[jumlah_pengendara - 1].jenis_kendaraan); // variabel kedua
              strcpy(data_pengendara[k].plat, data_pengendara[jumlah_pengendara - 1].plat);
              break;
            }

          }

          if (spi != 0){
            printf("Plat Kendaraan tidak ditemukan!\n");
          }
        }

        printf("\nBiaya parkir Anda sebesar: Rp.");
        printf("%d\n", totalbiaya);
        printf("\nTerima Kasih atas kepercayaan Anda untuk parkir bersama kami.\n\n");
        jumlah_pengendara -= 1;
        a += 1;
        total_pendapatan += totalbiaya;

        // Pencarian & Penghapusan pada Linked List
        printf("\n====================================================\n");
        printf("\nData pengendara yang ditemukan pada List :\n\n");
        Address P = FIRST(DatPengendara);
        int idx = 0;
        while (P != NULL) {
          if (strcmpi(INFO(P).plat, opsic) == 0) {
            printf("Nama Pengendara: %s\n", INFO(P).nama);
            printf("Jenis Kendaraan: %s\n", INFO(P).jenis_kendaraan);
            printf("No. Plat Kendaraan: %s\n\n", INFO(P).plat);
            break;
          } else {
            idx++;
            P = NEXT(P);
          }
        }
        deleteAt(&DatPengendara, idx, &data);

        // Print Linked List
        printf("====================================================\n");
        printf("\nData Kendaraan yang terparkir pada List (setelah dihapus):\n\n");
        P = FIRST(DatPengendara);
        while (P != NULL) {
          printf("Nama Pengendara: %s\n", INFO(P).nama);
          printf("Jenis Kendaraan: %s\n", INFO(P).jenis_kendaraan);
          printf("No. Plat Kendaraan: %s\n\n", INFO(P).plat);
          P = NEXT(P);
        }
      }
      back();
    }
    // Menampilkan Data Kendaraan yang Terparkir
    else if (opsi == 3) {
      system("cls");
      if (jumlah_pengendara == 0) {
        printf("Belum ada data yang tersimpan!\n");
      } else {

        printf("Jumlah pengendara adalah: %d\n\n", jumlah_pengendara);
          printf("Opsi Data Kendaraan\n\n");
          printf("1. Berdasarkan Nama Pemilik\n");
          printf("2. Berdasarkan Plat Kendaraan\n");
          printf("\nPilihan: ");
          scanf("%d", & opsi2);
          if (opsi2 == 1) {
            printf("Opsi Tampilan Data\n\n");
            printf("1. Tampilan Ascending (A-Z)\n");
            printf("2. Tampilan Descending (Z-A)\n");
            printf("\nPilihan: ");
            scanf("%d", & opsi3);

            // Sorting Array

            if (opsi3 == 1 || opsi3 == 2) {
              //tampilan berdasarkan nama pemilik secara ascending
              system("cls");

              // Sorting pada Array
              for (i = 0; i < jumlah_pengendara; i++) {
                for (j = i + 1; j < jumlah_pengendara; j++) {
                  if (opsi3 == 1){
                    //tampilan berdasarkan nama pemilik secara ascending
                    if (strcmpi(data_pengendara[i].nama, data_pengendara[j].nama) > 0) {
                      sort = data_pengendara[i];
                      data_pengendara[i] = data_pengendara[j];
                      data_pengendara[j] = sort;
                    }
                  } else {
                    //tampilan berdasarkan nama pemilik secara descending
                    if (strcmpi(data_pengendara[i].nama, data_pengendara[j].nama) < 0) {
                      sort = data_pengendara[i];
                      data_pengendara[i] = data_pengendara[j];
                      data_pengendara[j] = sort;
                    }
                  }
                }
              }

              // Sorting pada Linked List type 1
              if (opsi3 == 1){
                bubbleSort(&DatPengendara, 1);
              } else {
                bubbleSort(&DatPengendara, 2);
              }

            } else {
              printf("Angka yang Anda masukkan salah!\n");
            }
          } else if (opsi2 == 2) {
              printf("Opsi Tampilan Data\n\n");
              printf("1. Tampilan Ascending (A-Z)\n");
              printf("2. Tampilan Descending (Z-A)\n");
              printf("\nPilihan: ");
              scanf("%d", & opsi3);
              if (opsi3 == 1 || opsi3 == 2) {
                system("cls");
                for (i = 0; i < jumlah_pengendara; i++) {
                  for (j = i + 1; j < jumlah_pengendara; j++) {
                    //tampilan berdasarkan plat kendaraan secara ascending
                    if (opsi3 == 1){
                      if (strcmpi(data_pengendara[i].plat, data_pengendara[j].plat) > 0) {
                        sort = data_pengendara[i];
                        data_pengendara[i] = data_pengendara[j];
                        data_pengendara[j] = sort;
                      }
                    }

                    //tampilan berdasarkan plat kendaraan secara descending
                    else {
                      if (strcmpi(data_pengendara[i].plat, data_pengendara[j].plat) < 0) {
                        sort = data_pengendara[i];
                        data_pengendara[i] = data_pengendara[j];
                        data_pengendara[j] = sort;
                      }
                    }
                  }
                }

                // Sorting pada Linked List
                if (opsi3 == 1){
                  bubbleSort(&DatPengendara, 3);
                } else {
                  bubbleSort(&DatPengendara, 4);
                }

              } else {
                printf("Angka yang Anda masukkan salah!\n");
              }
          }

        if ((opsi2 == 1 || opsi2 == 2) && (opsi3 == 1 || opsi3 == 2)) {
          printf("Data Kendaraan yang Terparkir:\n");
          for (i = 0; i < jumlah_pengendara; i++) {
            printf("Nama Pengendara: %s\n", data_pengendara[i].nama);
            printf("Jenis Kendaraan: %s\n", data_pengendara[i].jenis_kendaraan);
            printf("No. Plat Kendaraan: %s\n\n", data_pengendara[i].plat);
          }

          // Print Linked List
          printf("====================================================\n");
          printf("Data Kendaraan yang Terparkir pada List:\n\n");
          Address P = FIRST(DatPengendara);
          while (P != NULL) {
            printf("Nama Pengendara: %s\n", INFO(P).nama);
            printf("Jenis Kendaraan: %s\n", INFO(P).jenis_kendaraan);
            printf("No. Plat Kendaraan: %s\n\n", INFO(P).plat);
            P = NEXT(P);
          }
        }
      }
      back();
    }

    // Mencari Data Kendaraan yang Terparkir Berdasarkan Nama/Plat
    else if (opsi == 4) {
      system("cls");
      if (jumlah_pengendara == 0) {
        printf("Belum ada data yang tersimpan!\n");
      } else {
          printf("Opsi Pencarian Kendaraan\n\n");
          printf("1. Berdasarkan Nama Pemilik\n");
          printf("2. Berdasarkan Plat Kendaraan\n");
          printf("\nPilihan: ");
          scanf("%d", & opsi2);
          if (opsi2 == 1 || opsi2 == 2) {
            if (opsi2 == 1) printf("Masukkan Nama Pemilik Kendaraan: "); // Pemakaian searching untuk mencari data pengendara dari namanya
            else printf("Masukkan Plat Pemilik Kendaraan: "); // Mencari data pengendara dari platnya

            scanf(" %[^\n]s", opsic);

            // Pencarian pada Array
            j = 0;

            for (i = 0; i < jumlah_pengendara; i++) { //Linear Search

              if (opsi2 == 1) spi = strcmpi(opsic, data_pengendara[i].nama);
              else spi = strcmpi(opsic, data_pengendara[i].plat);

              if (spi == 0) {
                k = i;
                printf("\nNama Pengendara: %s\n", data_pengendara[k].nama);
                printf("Jenis Kendaraan: %s\n", data_pengendara[k].jenis_kendaraan);
                printf("No. Plat Kendaraan: %s\n\n", data_pengendara[k].plat);
                j--;
              }
              j++;
            }

            if (j == jumlah_pengendara) {
              printf("Data pengendara tidak ditemukan!\n");
            }

            // Pencarian pada Linked List
            printf("====================================================\n");
            printf("\nData pengendara yang ditemukan pada List :\n\n");
            Address P = FIRST(DatPengendara);
            boolean found = false;
            while (P != NULL) {
              if (strcmpi(INFO(P).plat, opsic) == 0 && opsi2 == 2 || strcmpi(INFO(P).nama, opsic) == 0 && opsi2 == 1) {
                printf("Nama Pengendara: %s\n", INFO(P).nama);
                printf("Jenis Kendaraan: %s\n", INFO(P).jenis_kendaraan);
                printf("No. Plat Kendaraan: %s\n\n", INFO(P).plat);
                found = true;
              } 
              P = NEXT(P);
            }

            if (!found) {
              printf("Data pengendara tidak ditemukan!\n");
            }

          } else {
            printf("Angka yang Anda masukkan salah!\n");
          }
      }
      back();
    }

    // MENGUBAH BIAYA PARKIR
    else if (opsi == 5) {
      system("cls");
      printf("Opsi Admin\n\n");
      printf("1. Ubah Biaya Parkir\n");
      printf("2. Total Pendapatan\n");
      printf("\nPilihan: ");
      scanf("%d", & opsi2);
      if (opsi2 == 1) {
        printf("Pilih kendaraan yang ingin biayanya diubah:\n");
        printf("Pilih 3 untuk melihat rincian biaya yang diterapkan sekarang\n");
        printf("1. Mobil\n");
        printf("2. Motor\n");
        printf("\nPilihan: ");
        scanf("%d", & opsi3);
        if (opsi3 == 1) {
          system("cls");
          printf("Masukkan nominal biaya parkir mobil yang baru:\n");

          printf("Biaya masuk awal: Rp.");
          scanf("%d", & ganti_biaya);
          biaya[0][0] = ganti_biaya;

          printf("Biaya per jam: Rp.");
          scanf("%d", & ganti_biaya);
          biaya[0][1] = ganti_biaya;

          printf("Diskon bonus h+1: Rp.");
          scanf("%d", & ganti_biaya);
          diskon[0] = ganti_biaya;

          printf("\nBiaya parkir telah berhasil diubah.\n");
        } else if (opsi3 == 2) {
          system("cls");
          printf("Masukkan nominal biaya parkir motor yang baru:\n");

          printf("Biaya masuk awal: Rp.");
          scanf("%d", & ganti_biaya);
          biaya[1][0] = ganti_biaya;

          printf("Biaya per jam: Rp.");
          scanf("%d", & ganti_biaya);
          biaya[1][1] = ganti_biaya;

          printf("Diskon bonus h+1: Rp.");
          scanf("%d", & ganti_biaya);
          diskon[1] = ganti_biaya;

          printf("\nBiaya parkir telah berhasil diubah.\n");
        } else if (opsi3 == 3) {
          system("cls");
          printf("Biaya awal parkir mobil saat ini adalah: Rp.%d\n", biaya[0][0]);
          printf("Biaya per-jam parkir mobil saat ini adalah: Rp.%d\n", biaya[0][1]);
          printf("Diskon untuk pemarkir mobil lebih dari satu hari adalah: Rp.%d\n", diskon[0]);

          printf("\nBiaya awal parkir motor saat ini adalah: Rp.%d\n", biaya[1][0]);
          printf("Biaya per-jam parkir motor saat ini adalah: Rp.%d\n", biaya[1][1]);
          printf("Diskon untuk pemarkir motor lebih dari satu hari adalah: Rp.%d\n", diskon[1]);
        } else {
          printf("Angka yang Anda masukkan salah\n");
        }
      } else if (opsi2 == 2) {
        printf("Total pendapatan dari parkir sebesar %d\n\n", total_pendapatan);
      } else {
        printf("Angka yang Anda masukkan salah\n");
      }
      back();
    }
    // Menampilkan Panduan
    else if (opsi == 6) {
      system("cls");
      displayPanduan();
      back();
    }

    // Binary Tree
    else if (opsi == 7){
      system("cls");
      // operasi : add, edit, delete, search, print
      printf("Binary Tree\n");
      printf("1. Add\n");
      printf("2. Edit\n");
      printf("3. Delete\n");
      printf("4. Search\n");
      printf("5. Print\n");
      printf("\nPilihan: ");
      scanf("%d", & opsi2);
      int treetemp, treetemp2;
      Address2 tempp;
      system("cls");

      if (opsi2 == 1){
        printf("Masukkan nilai yang ingin dimasukkan: ");
        scanf("%d", & treetemp);
        if (isTreeEmpty(p)){
          CreateTree(treetemp, NULL, NULL, &p);
        } else {
          p = insertNode(p, treetemp);
        }
      }

      else if (opsi2 == 2){
        printf("Masukkan nilai yang ingin diedit: ");
        scanf("%d", & treetemp);
        if (searchNode(p, treetemp)){
          printf("Masukkan nilai yang ingin diganti: ");
          scanf("%d", & treetemp2);
          p = editNode(p, treetemp, treetemp2);
        } else {
          printf("Nilai tidak ditemukan\n");
        }
      }

      else if (opsi2 == 3){
        printf("Masukkan nilai yang ingin dihapus: ");
        scanf("%d", & treetemp);
        if (searchNode(p, treetemp)){
          p = deleteNode(p, treetemp);
        } else {
          printf("Nilai tidak ditemukan\n");
        }
      }

      else if (opsi2 == 4){
        printf("Masukkan nilai yang ingin dicari: ");
        scanf("%d", & treetemp);
        if (searchNode(p, treetemp)){
          printf("Nilai ditemukan\n");
        } else {
          printf("Nilai tidak ditemukan\n");
        }
      }

      else if (opsi2 == 5){
        printf("Preorder :\n");
        printPreorder(p);
        printf("\n");
        printf("Inorder :\n");
        printInorder(p);
        printf("\n");
        printf("Postorder :\n");
        printPostorder(p);
        printf("\n");
      }

      else {
        printf("Angka yang Anda masukkan salah\n");
      }
      back();
    }

    // Exit program
    else if (opsi == 8) {
      system("cls");
      printf("Terima kasih sudah menggunakan program ini.");
      break;
    } else {
      printf("Opsi yang dimasukkan tidak ada!\n");
    }

  }
  return 0;
}

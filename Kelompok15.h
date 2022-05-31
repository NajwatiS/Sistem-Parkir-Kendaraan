#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

/** AKSES & SELEKTOR */
#define boolean unsigned char
#define true 1
#define false 0
// Linked List
#define INFO(p) (p)->info
#define NEXT(p) (p)->next
#define IDX_UNDEF (-1)
#define FIRST(l) (l)
// Binary Tree
#define ROOT(b) (b)->data
#define LEFT(b) (b)->left
#define RIGHT(b) (b)->right
// Queue (for binary tree)
#define CAPACITY 100
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

/** STRUCT */
typedef struct {
  char nama[50];
  char jenis_kendaraan[50];
  char plat[50];
} dpengendara;

typedef int ElType;
typedef struct node* Address;
typedef struct node {
    dpengendara info;
    Address next;
} Node;

struct DataPengendara {
  char nama[50];
  char jenis_kendaraan[50];
  char plat[50];
} data_pengendara[50];

typedef struct treeNode* Address2;
typedef struct treeNode { 
     ElType data;
     Address2 left;
     Address2 right;
} TreeNode;

typedef Address List;
typedef Address2 BinTree;

typedef struct {
	Address2 buffer[CAPACITY]; 
	int idxHead;
	int idxTail;
} Queue;

/** LIST FUNGSI & PROSEDUR (PROTOTYPE) */
// void displayPanduan();
// void displayMenu(int pil);
// int back();
// int hitung_waktu_min(int min1, int hour1, int day1, int mon1, int year1);
// int hitung_waktu_jam(int min1, int hour1, int day1, int mon1, int year1);
// int hitung_waktu_hari(int min1, int hour1, int day1, int mon1, int year1);
// int hitung_waktu_bulan(int min1, int hour1, int day1, int mon1, int year1);
// int hitung_waktu_tahun(int min1, int hour1, int day1, int mon1, int year1);
// Address newNode(dpengendara val);
// void CreateList(List *l);
// boolean isEmpty(List l);
// dpengendara getElmt(List l, int idx);
// void setElmt(List *l, int idx, dpengendara val);
// void insertFirst(List *l, dpengendara val);
// void insertLast(List *l, dpengendara val);
// void deleteFirst(List *l, dpengendara *val);
// void deleteLast(List *l, dpengendara *val);
// void deleteAt(List *l, int idx, dpengendara *val);
// void bubbleSort(List *l, int type);
// void CreateQueue(Queue *q);
// boolean isEmptyQueue(Queue q);
// int length(Queue q);
// void enqueue(Queue *q, Address2 val);
// void dequeue(Queue *q, Address2 *val);
// BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree);
// void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p);
// Address2 newTreeNode(ElType val);
// BinTree insertNode(BinTree p, ElType val);
// boolean searchNode(BinTree p, ElType val);
// BinTree editNode(BinTree p, ElType val, ElType newVal)
// BinTree deleteNode(BinTree p, ElType val);
// boolean isTreeEmpty (BinTree p);
// void printPreorder(BinTree p);
// void printInorder(BinTree p);
// void printPostorder(BinTree p);

/** IMPLEMENTASI FUNGSI & PROSEDUR */
void displayPanduan() {
  printf("\tSistem Parkir Kendaraan\n");
  printf("\tProgram ini akan menyimpan data pemarkir kendaraan serta menghitung biaya parkir.\n\n");

  printf("\tPanduan Program\n");
  printf("\tUntuk menggunakan program ini, harap mengikuti instruksi di bawah ini:\n");
  printf("\tOpsi 1\n");
  printf("\t     Pada opsi ini, Anda akan diminta untuk memasukkan data mobil Anda.\n");
  printf("\t     Data tersebut di antara lain:\n");
  printf("\t     - Nama, yaitu nama anda.\n");
  printf("\t     - Jenis Kendaraan, yaitu jenis kendaraan yang Anda gunakan (mobil/motor).\n");
  printf("\t     - Plat Kendaraan, yaitu nomor plat kendaraan Anda\n");
  printf("\t     Untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 2\n");
  printf("\t     Pada opsi ini, Anda akan diminta untuk memasukkan nama, plat kendaraan,\n");
  printf("\t	   dan berapa lama Anda memarkirkan kendaraan Anda.\n");
  printf("\t     Setelah itu, Anda akan diberikan rincian biaya parkir untuk Anda bayar.\n");
  printf("\t     Untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 3\n");
  printf("\t     Pada opsi ini, Anda dapat melihat kendaraan yang diparkir dengan urutan \n");
  printf("\t     naik atau turun berdasarkan nama/plat kendaraan.\n");
  printf("\t     Untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 4\n");
  printf("\t     Pada opsi ini, Anda dapat mencari kendaraan yang terdata dalam sistem\n");
  printf("\t     berdasarkan nama pemilik kendaraan/plat kendaraan\n");
  printf("\t     Untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 5\n");
  printf("\t     Pada opsi ini, Admin dapat mengubah biaya parkir untuk kedua jenis kendaraan\n");
  printf("\t     serta melihat pendapatan harian.\n");
  printf("\t     Untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 7\n");
  printf("\t     Pada opsi ini, Anda dapat menggunakan fungsionalitas Binary Tree.\n");
  printf("\t     Operasi yang dapat dilakukan : Insert, Edit, Delete, Search, Print\n");
  printf("\t     Untuk kembali ke tampilan utama, Anda dapat memasukkan angka 0.\n");
  printf("\tOpsi 8\n");
  printf("\t     Pada opsi ini, Anda dapat keluar dari program dengan mengetik angka 7.\n");
}

void displayMenu(int pil) {
    if (pil == 0){
        printf(" SELAMAT DATANG DI PROGRAM PARKIR KENDARAAN\n");
        printf("                  ______ \n");
        printf("                 /|_||_\\`.__\n");
        printf("                (   _    _ _\\\n");
        printf("                =`-(_)--(_)-'  \n");
    }
  printf("==========Sistem Parkir Kendaraan==========\n");
  printf("1. Kendaraan Masuk\n");
  printf("2. Kendaraan Keluar\n");
  printf("3. Data Kendaraan\n"); // Daftar kendaraan ascending dan descending berdasarkan nama-kendaraan/plat-kendaraan
  printf("4. Pencarian Kendaraan\n"); // Pencarian Kendaraan bisa dari nama/platnya
  printf("5. Menu Admin\n"); // Menunjukkan menu Admin
  printf("6. Panduan program\n");
  printf("7. Binary Tree\n");
  printf("8. Keluar\n");

  printf("\nSilahkan pilih opsi sesuai nomor: ");
}

int back() {
  int kembali = 1;
  while (kembali != 0) {
    printf("Masukkan angka 0 untuk kembali: ");
    scanf("%d", & kembali);
    if (kembali == 0) {
      system("cls");
      continue;
    } else {
      printf("Angka yang Anda masukkan salah!\n");
      continue;
    }
  }
}
//--------------------------------------------------------------------------------------------------- Awal Fungsi Hitung Waktu
int hitung_waktu_min(int min1, int hour1, int day1, int mon1, int year1) {
  time_t rawtime;
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);

  int min2 = info -> tm_min;
  int hour2 = info -> tm_hour;
  int day2 = info -> tm_mday;
  int mon2 = info -> tm_mon + 1;
  int year2 = info -> tm_year + 1900;

  if (day2 < day1) {
    // Februari
    if (mon2 == 3) {

      if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
        day2 += 29;
      } else {
        day2 += 28;
      }
    }

    // Bulan 30
    else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
      day2 += 30;
    }

    // Bulan 31
    else {
      day2 += 31;
    }

    mon2 = mon2 - 1;
  }

  if (mon2 < mon1) {
    mon2 += 12;
    year2 -= 1;
  }

  if (hour2 > hour1) {
    min2 += 60;
    hour2 -= 1;
  }

  int min_diff = min2 - min1;
  int hour_diff = hour2 - hour1;
  int day_diff = day2 - day1;
  int mon_diff = mon2 - mon1;
  int year_diff = year2 - year1;

  if (day_diff > 0) {
    hour_diff += 24 * day_diff;
    day_diff = 0;
  }
  if (min_diff >= 60) {
    do {
      hour_diff += 1;
      min_diff -= 60;
    } while (min_diff >= 60);
  }
  return min_diff;
}

int hitung_waktu_jam(int min1, int hour1, int day1, int mon1, int year1) {
  time_t rawtime;
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);

  int min2 = info -> tm_min;
  int hour2 = info -> tm_hour;
  int day2 = info -> tm_mday;
  int mon2 = info -> tm_mon + 1;
  int year2 = info -> tm_year + 1900;

  if (day2 < day1) {
    // Februari
    if (mon2 == 3) {

      if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
        day2 += 29;
      } else {
        day2 += 28;
      }
    }

    // Bulan 30
    else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
      day2 += 30;
    }

    // Bulan 31
    else {
      day2 += 31;
    }

    mon2 = mon2 - 1;
  }

  if (mon2 < mon1) {
    mon2 += 12;
    year2 -= 1;
  }

  if (hour2 > hour1) {
    min2 += 60;
    hour2 -= 1;
  }

  int min_diff = min2 - min1;
  int hour_diff = hour2 - hour1;
  int day_diff = day2 - day1;
  int mon_diff = mon2 - mon1;
  int year_diff = year2 - year1;

  if (day_diff > 0) {
    hour_diff += 24 * day_diff;
    day_diff = 0;
  }
  if (min_diff >= 60) {
    do {
      hour_diff += 1;
      min_diff -= 60;
    } while (min_diff >= 60);
  }
  return hour_diff;
}

int hitung_waktu_hari(int min1, int hour1, int day1, int mon1, int year1) {
  time_t rawtime;
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);

  int min2 = info -> tm_min;
  int hour2 = info -> tm_hour;
  int day2 = info -> tm_mday;
  int mon2 = info -> tm_mon + 1;
  int year2 = info -> tm_year + 1900;

  if (day2 < day1) {
    // Februari
    if (mon2 == 3) {

      if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
        day2 += 29;
      } else {
        day2 += 28;
      }
    }

    // Bulan 30
    else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
      day2 += 30;
    }

    // Bulan 31
    else {
      day2 += 31;
    }

    mon2 = mon2 - 1;
  }

  if (mon2 < mon1) {
    mon2 += 12;
    year2 -= 1;
  }

  if (hour2 > hour1) {
    min2 += 60;
    hour2 -= 1;
  }

  int min_diff = min2 - min1;
  int hour_diff = hour2 - hour1;
  int day_diff = day2 - day1;
  int mon_diff = mon2 - mon1;
  int year_diff = year2 - year1;

  if (day_diff > 0) {
    hour_diff += 24 * day_diff;
    day_diff = 0;
  }
  if (min_diff >= 60) {
    do {
      hour_diff += 1;
      min_diff -= 60;
    } while (min_diff >= 60);
  }
  return day_diff;
}

int hitung_waktu_bulan(int min1, int hour1, int day1, int mon1, int year1) {
  time_t rawtime;
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);

  int min2 = info -> tm_min;
  int hour2 = info -> tm_hour;
  int day2 = info -> tm_mday;
  int mon2 = info -> tm_mon + 1;
  int year2 = info -> tm_year + 1900;

  if (day2 < day1) {
    // Februari
    if (mon2 == 3) {
      if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
        day2 += 29;
      } else {
        day2 += 28;
      }
    }

    // Bulan 30
    else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
      day2 += 30;
    }

    // Bulan 31
    else {
      day2 += 31;
    }

    mon2 = mon2 - 1;
  }

  if (mon2 < mon1) {
    mon2 += 12;
    year2 -= 1;
  }

  if (hour2 > hour1) {
    min2 += 60;
    hour2 -= 1;
  }

  int min_diff = min2 - min1;
  int hour_diff = hour2 - hour1;
  int day_diff = day2 - day1;
  int mon_diff = mon2 - mon1;
  int year_diff = year2 - year1;

  if (day_diff > 0) {
    hour_diff += 24 * day_diff;
    day_diff = 0;
  }
  if (min_diff >= 60) {
    do {
      hour_diff += 1;
      min_diff -= 60;
    } while (min_diff >= 60);
  }
  return mon_diff;
}

int hitung_waktu_tahun(int min1, int hour1, int day1, int mon1, int year1) {
  time_t rawtime;
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);

  int min2 = info -> tm_min;
  int hour2 = info -> tm_hour;
  int day2 = info -> tm_mday;
  int mon2 = info -> tm_mon + 1;
  int year2 = info -> tm_year + 1900;

  if (day2 < day1) {
    // Februari
    if (mon2 == 3) {
      if ((year2 % 4 == 0 && year2 % 100 != 0) || (year2 % 400 == 0)) {
        day2 += 29;
      } else {
        day2 += 28;
      }
    }

    // Bulan 30
    else if (mon2 == 5 || mon2 == 7 || mon2 == 10 || mon2 == 12) {
      day2 += 30;
    }

    // Bulan 31
    else {
      day2 += 31;
    }

    mon2 = mon2 - 1;
  }

  if (mon2 < mon1) {
    mon2 += 12;
    year2 -= 1;
  }

  if (hour2 > hour1) {
    min2 += 60;
    hour2 -= 1;
  }

  int min_diff = min2 - min1;
  int hour_diff = hour2 - hour1;
  int day_diff = day2 - day1;
  int mon_diff = mon2 - mon1;
  int year_diff = year2 - year1;

  if (day_diff > 0) {
    hour_diff += 24 * day_diff;
    day_diff = 0;
  }
  if (min_diff >= 60) {
    do {
      hour_diff += 1;
      min_diff -= 60;
    } while (min_diff >= 60);
  }
  return year_diff;
}
//--------------------------------------------------------------------------------------------------- Akhir Fungsi Hitung Waktu

Address newNode(dpengendara val) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}

void CreateList(List *l){
	FIRST(*l) = NULL;
}

boolean isEmpty(List l){
	return FIRST(l) == NULL;
}

dpengendara getElmt(List l, int idx){
	Address P = FIRST(l);
	int i = 0;
	while (i<idx){
		P = NEXT(P);
		i++;
	}
	return INFO(P);
}

void setElmt(List *l, int idx, dpengendara val){
	Address P = FIRST(*l);
	int i = 0;
	while (i<idx){
		P = NEXT(P);
		i++;
	}
	INFO(P) = val;
}

void insertFirst(List *l, dpengendara val){
	Address P = newNode(val);
	if (P != NULL){
		NEXT(P) = FIRST(*l);
		FIRST(*l) = P;
	}
}

void insertLast(List *l, dpengendara val){
	if (!isEmpty(*l)){
		Address P = newNode(val);
		if (P != NULL){
			Address last = FIRST(*l);
			while (NEXT(last) != NULL){
				last = NEXT(last);
			}
			NEXT(last) = P;
		}
	} else insertFirst(l, val);
}

void deleteFirst(List *l, dpengendara *val){
	Address P = FIRST(*l);
	*val = INFO(P);
	FIRST(*l) = NEXT(P);
	free(P);
}

void deleteLast(List *l, dpengendara *val){
	Address P = FIRST(*l);
	Address loc = NULL;
	while (NEXT(P) != NULL){
		loc = P;
		P = NEXT(P);
	}
	if (loc == NULL) FIRST(*l) = NULL;
	else NEXT(loc) = NULL;
	*val = INFO(P);
	free(P);
}

void deleteAt(List *l, int idx, dpengendara *val){
	int count;
	if (idx == 0) deleteFirst(l, val);
	else {
		count = 0;
		Address loc = FIRST(*l);
		while (count < idx-1){
			count++;
			loc = NEXT(loc);
		}
		Address P = NEXT(loc);
		*val = INFO(P);
		NEXT(loc) = NEXT(P);
		free(P);
	}
}

void bubbleSort(List *l, int type)
{
    // Type 1 = Name Ascending
    // Type 2 = Name Descending
    // Type 3 = Plat Ascending
    // Type 4 = Plat Descending

    int swapped, i;
    Address P;
    Address Q = NULL;
    dpengendara temp;

    if(isEmpty(*l))
    {
        printf("List kosong\n");
        return;
    } else {
      do {
        swapped = 0;
        P = FIRST(*l);
        while (NEXT(P) != Q){
          if (strcmpi(INFO(P).nama, INFO(NEXT(P)).nama) > 0 && type == 1){
            temp = INFO(P);
            INFO(P) = INFO(NEXT(P));
            INFO(NEXT(P)) = temp;
            swapped = 1;
          } else if (strcmpi(INFO(P).nama, INFO(NEXT(P)).nama) < 0 && type == 2){
            temp = INFO(P);
            INFO(P) = INFO(NEXT(P));
            INFO(NEXT(P)) = temp;
            swapped = 1;
          } else if (strcmpi(INFO(P).plat, INFO(NEXT(P)).plat) > 0 && type == 3){
            temp = INFO(P);
            INFO(P) = INFO(NEXT(P));
            INFO(NEXT(P)) = temp;
            swapped = 1;
          } else if (strcmpi(INFO(P).plat, INFO(NEXT(P)).plat) < 0 && type == 4){
            temp = INFO(P);
            INFO(P) = INFO(NEXT(P));
            INFO(NEXT(P)) = temp;
            swapped = 1;
          }

          P = NEXT(P);
        }
        Q = P;
      } while (swapped);
    }
}

void CreateQueue(Queue *q){
	IDX_HEAD(*q) = IDX_UNDEF;
	IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmptyQueue(Queue q){
	return (IDX_HEAD(q)==IDX_UNDEF && IDX_TAIL(q)==IDX_UNDEF);
	
}

int length(Queue q){
	if (isEmptyQueue(q)) return 0;
	else {
		return (IDX_TAIL(q) - IDX_HEAD(q) + 1);	
	}
}

void enqueue(Queue *q, Address2 val){
	if (!isEmptyQueue(*q)){
		if (IDX_TAIL(*q)==(CAPACITY-1)){
			int i = IDX_HEAD(*q);
			while (i<=IDX_TAIL(*q)){
				(*q).buffer[i-IDX_HEAD(*q)] = (*q).buffer[i];
				i++;
			}
			IDX_TAIL(*q) -= IDX_HEAD(*q);
			IDX_HEAD(*q) = 0;
		}
		IDX_TAIL(*q)++;
	} else {
		IDX_HEAD(*q) = 0;
		IDX_TAIL(*q) = 0;
	}
	TAIL(*q) = val;
}

void dequeue(Queue *q, Address2 *val){
	*val = HEAD(*q);
	if (IDX_HEAD(*q) != IDX_TAIL(*q)) IDX_HEAD(*q)++;
	else {
		IDX_HEAD(*q)=IDX_UNDEF;
		IDX_TAIL(*q)=IDX_UNDEF;
	}
}

BinTree NewTree (ElType root, BinTree left_tree, BinTree right_tree){
    BinTree tree = (BinTree) malloc(sizeof(BinTree));
    if (tree == NULL) return NULL;
    else {
        ROOT(tree) = root;
        LEFT(tree) = left_tree;
        RIGHT(tree) = right_tree;

        return tree;
    }
} 

void CreateTree (ElType root, BinTree left_tree, BinTree right_tree, BinTree *p){
    *p = NewTree(root, left_tree, right_tree);
}

Address2 newTreeNode(ElType val){
    Address2 P = (Address2) malloc(sizeof(TreeNode));
    if (P != NULL){
        ROOT(P) = val;
        LEFT(P) = NULL;
        RIGHT(P) = NULL;
    }
    return P;
}

BinTree insertNode(BinTree p, ElType val){
  Address2 temp = newTreeNode(val);
  Address2 bin;

  Queue q;
  CreateQueue(&q);
  enqueue(&q, p);

  while (!isEmptyQueue(q)){
    dequeue(&q, &bin);
    if (LEFT(bin) == NULL){
      LEFT(bin) = temp;
      return p;
    } else if (RIGHT(bin) == NULL){
      RIGHT(bin) = temp;
      return p;
    } else {
      enqueue(&q, LEFT(bin));
      enqueue(&q, RIGHT(bin));
    }
  }
}

boolean searchNode(BinTree p, ElType val){
  if (p == NULL) return false;
  else if (ROOT(p) == val) return true;
  else {
    return (searchNode(LEFT(p), val) || searchNode(RIGHT(p), val));
  }
}

BinTree editNode(BinTree p, ElType val, ElType newVal){
  Address2 temp = newTreeNode(newVal);
  Address2 bin;

  Queue q;
  CreateQueue(&q);
  enqueue(&q, p);

  while (!isEmptyQueue(q)){
    dequeue(&q, &bin);
    if (ROOT(bin) == val){
      ROOT(bin) = newVal;
      return p;
    } else {
      enqueue(&q, LEFT(bin));
      enqueue(&q, RIGHT(bin));
    }
  }
}

BinTree deleteNode(BinTree p, ElType val){
  Address2 bin;
  Queue q;
  CreateQueue(&q);
  enqueue(&q, p);

  while (!isEmptyQueue(q)){
    dequeue(&q, &bin);
    if (LEFT(bin) != NULL && ROOT(LEFT(bin)) == val){
      LEFT(bin) = NULL;
      return p;
    } else if (RIGHT(bin) != NULL && ROOT(RIGHT(bin)) == val){
      RIGHT(bin) = NULL;
      return p;
    } else {
      enqueue(&q, LEFT(bin));
      enqueue(&q, RIGHT(bin));
    }
  }

  return p;
}

boolean isTreeEmpty (BinTree p){
    return (p == NULL);
}

void printPreorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printf("%d", ROOT(p));
        printPreorder(LEFT(p));
        printPreorder(RIGHT(p));
    }
    printf(")");
}

void printInorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printInorder(LEFT(p));
        printf("%d", ROOT(p));
        printInorder(RIGHT(p));
    }
    printf(")");
}

void printPostorder(BinTree p){
    printf("(");
    if (!isTreeEmpty(p)){
        printPostorder(LEFT(p));
        printPostorder(RIGHT(p));
        printf("%d", ROOT(p));
    }
    printf(")");
}
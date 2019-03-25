/*ADT untuk memeriksa syntax error pada input string*/

#ifndef SYNTAX_h
#define SYNTAX_h

#include "parse.h"

/* Ukuran minimum dan maksimum baris dan kolom matriks CYK*/
#define BrsMin 0
#define BrsMax 99
#define KolMin 0
#define KolMax 99

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef struct { 
	ElType Mem[BrsMax+1][KolMax+1][100];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKSCYK;
/* NBrsEff <= 1 dan NKolEff <= 1 */
/* Indeks matriks yang digunakan: [BrsMin..BrsMax][KolMin..KolMax] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

boolean Search (string s, char C);
/*untuk search apakah ada karakter C pada elemen matriks*/
/*I.S. M,i,j,C terdefinisi*/
/*F.S. mengembalikan true jika terdapat character C pada elemen matriks berindeks i j, false sebaliknya*/

arrString MakeBracketsArr (arrString arr);
/* membuat array yang isinya hanya tanda kurung untuk dicek apakah tanda kurung berpasangan*/
/* I.S. arr sudah di parse*/
/* F.S. mengembalikan array yang hanya berisi tanda kurung*/

char VariableBrackets (string s);
/* Mencari variable asal dari sebuah string yang berbentuk 2 variable atau 1 terminal dari aturan produksi kurung berpasangan*/
/* I.S. string s sudah dalam bentuk dua variable atau 1 terminal*/
/* F.S. mengembalikan variabel asal jika ada atau 'Z' bila tidak ada*/
/* Contoh : A -> AB | a
	VariableBrackets ("AB") = 'A'*/

boolean BracketsCheck (arrString arr);
/* mengecek apakah tanda kurung berpasangan memakai algoritma CYK*/
/* I.S. arr sudah di-parse dan di-MakeBracketsArr*/
/* F.S. mengembalikan nilai true jika tanda kurung berpasangan, false jika tanda kurung tidak berpasangan*/
	
void Variable (string s, string *temp, int *neff);
/* Mencari variable asal dari sebuah string yang berbentuk 2 variable atau 1 terminal dari aturan produksi input kalkulator*/
/* I.S. string s sudah dalam bentuk dua variable atau 1 terminal*/
/* F.S. mengembalikan variabel asal jika ada atau 'Z' bila tidak ada sebanyak neff*/
/* Contoh : A -> AB | a
	VariableBrackets ("AB") = "A"*/

boolean InputCheck (arrString arr);
/* mengecek input diterima memakai algoritma CYK*/
/* I.S. arr sudah di-parse */
/* F.S. mengembalikan nilai true jika input diterima, false jika input tidak diterima*/

boolean IsNumValid (arrString arr);
/*memeriksa banyak '.' pada angka. Valid bila banyak '.' 0 atau 1. Tidak valid bila banyak '.' lebih dari 1.
 * I.S. string input sudah diparse
 * F.S. mengembalikan nilai false bisa ada angka tidak valid, true jika semua angka valid*/
 
 
#endif

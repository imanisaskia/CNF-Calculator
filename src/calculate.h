/*ADT untuk menghitung input user sesuai urutan prioritas perhitungan*/

#ifndef CALCULATE_h
#define CALCULATE_h

#include "parse.h"

typedef struct {
    double T[100];
    int Neff;
} arrDouble;

int PrioBracket (arrString arr);
/*untuk mengetahui indeks pertama yang akan dikalkulasi menurut prioritas berdasarkan tanda kurung*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error*/
/*F.S. mengembalikan nilai indeks pertama yang akan dikalkulasi dilihat dari prioritas tanda kurung*/

int PrioOperator (arrString arr, int i);
/*untuk mengetahui indeks operator yang harus dihitung duluan*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error, i adalah hasil PrioBracket*/
/*F.S. mengembalikan nilai indeks operator yang pertama harus dikalkulasi*/

void toArrDouble (arrString arr, arrDouble *arrd);
/*untuk membuat array yang berisi seluruh angka dalam tipe double dengan indeks yang sama dengan arrString*/
/*I.S. arr sudah di parse*/
/*F.S. mengembalikan array dengan elemen bertipe double yang isinya semua angka dengan indeks sama dengan arrString*/

void DelTwo (arrString *arr, int i, char X);
/*untuk menghapus elemen di antara indeks i, mengubah nilai elemen berindeks i menjadi X, menggeser elemen-elemen lainnya*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error*/
/*F.S. elemen di antara i sudah dihapus,nilai X sudah dimasukkan*/

void DelTwoDouble (arrDouble *arrd, int i, double X);
/*untuk menghapus letak elemen di antara i agar indeks angka tetap terjaga sama dengan arrString, nilai elemen i menjadi X,
 * menggeser elemen lainnya*/
/*I.S. arrd terdefinisi*/
/*F.S. elemen dengan indeks yang sama dengan elemen di antara i pada arrString sudah dihapus, elemen berindeks i menjadi X*/

void DelOne (arrString *arr, int i, char X);
/*untuk menghapus elemen setelah indeks i, mengubah nilai elemen berindeks i menjadi X, menggeser elemen-elemen lainnya*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error*/
/*F.S. elemen setelah i sudah dihapus,nilai X sudah dimasukkan*/

void DelOneDouble (arrDouble *arrd, int i, double X);
/*untuk menghapus letak elemen setelah i agar indeks angka tetap terjaga sama dengan arrString, nilai elemen i menjadi X,
 * menggeser elemen lainnya*/
/*I.S. arrd terdefinisi*/
/*F.S. elemen dengan indeks yang sama dengan elemen setelah i pada arrString sudah dihapus, elemen berindeks i menjadi X*/

double lilCalc (double angka1, double angka2, char Op);
/*untuk menghitung angka1 dioperasikan dengan angka2*/
/*I.S. angka1 dan angka2 terdefinisi*/
/*F.S. mengembalikan hasil operasi*/

void calculate (arrString *arr, arrDouble *arrd, boolean *error);
/*untuk mengkalkulasi inputan user berdasarkan prioritas penghitungan sambil mengecek math error*/
/*I.S. arr sudah di parse, sudah lulus uji syntax error, arrd sudah diisi melalui toArrDouble*/
/*F.S. mengeprint hasil kalkulasi atau math error jika ada*/


#endif

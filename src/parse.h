#ifndef _PARSE_h
#define _PARSE_h

#define boolean unsigned char
#define true 1
#define false 0

typedef char string[1000];
typedef struct {
    string T[100];
    int Neff;
} arrString;

typedef boolean flag;

boolean IsOp (char c);
/*untuk mengecek apakah karakter termasuk operator*/
/*I.S. c terdefinisi*/
/*F.S. mengembalikan true jika c adalah '-','+','*','/', atau '^'
 * 					 false jika c bukan karakter-karakter di atas*/

boolean IsNum (char c);
/*untuk mengecek apakah karakter termasuk angka*/
/*I.S. c terdefinisi*/
/*F.S. mengembalikan true jika c adalah '0','1','2','3','4','5','6','7','8','9', atau '.'*/

void parse (string s, arrString * arr);
/*untuk mengisi arrString dengan inputan pengguna sesuai tipe inputan*/
/*I.S. s terdefinisi, arr sembarang*/
/*F.S. arr terisi, setiap elemen arr adalah tiap elemen input (angka, operator, atau kurung) yang berbeda*/

void printArr (arrString arr);
/*untuk mengeprint arrString*/
/*I.S. arr terdefinisi*/
/*F.S. arr diprint*/

double toDouble (string s);
/*untuk mengubah string angka menjadi tipe double*/
/*I.S. s terdefinisi dan berupa angka*/
/*F.S. mengembalikan nilai double yang sesuai string*/

#endif

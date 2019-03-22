#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

boolean IsOp (char c) {
/*untuk mengecek apakah karakter termasuk operator*/
/*I.S. c terdefinisi*/
/*F.S. mengembalikan true jika c adalah '-','+','*','/', atau '^'
 * 					 false jika c bukan karakter-karakter di atas*/
    return ((c == '(') || (c == ')') || (c == '+') || (c == '-') || (c == '*') || (c == '/') || (c == '^'));
}

boolean IsNum (char c) {
/*untuk mengecek apakah karakter termasuk angka*/
/*I.S. c terdefinisi*/
/*F.S. mengembalikan true jika c adalah '0','1','2','3','4','5','6','7','8','9', atau '.'*/
    return ((c == '0') || (c == '1') || (c == '2') || (c == '3') || (c == '4') || (c == '5') || (c == '6') || (c == '7') || (c == '8') || (c == '9') || (c == '.'));
}

void parse (string s, arrString * arr) {
/*untuk mengisi arrString dengan inputan pengguna sesuai tipe inputan*/
/*I.S. s terdefinisi, arr sembarang*/
/*F.S. arr terisi, setiap elemen arr adalah tiap elemen input (angka, operator, atau kurung) yang berbeda*/
    int i, j;
    i = 0;
    j = 0;
	(*arr).Neff = 0;
	
    while (i < strlen(s)) {
        string temp = "";
       
        if (IsOp(s[i])) {
            temp[0] = s[i];
            (*arr).T[j][0] = temp[0];
            (*arr).Neff++;
            i++;
            j++;

        } else if (IsNum(s[i])) {
            temp[0] = s[i];

            int k = 1;
            i++;
            
            while ((IsNum(s[i])) && (i < strlen(s))) {
                temp[k] = s[i];
                i++;
                k++;
            }

            for (int a = 0; a <= strlen(temp); a++) {
                (*arr).T[j][a] = temp[a];
            }

            (*arr).Neff++;
            j++;
        } else {
            temp[0] = s[i];
            (*arr).T[j][0] = temp[0];
            (*arr).Neff++;
            i++;
            j++;
        }
    }
}

void printArr (arrString arr) {
/*untuk mengeprint arrString*/
/*I.S. arr terdefinisi*/
/*F.S. arr diprint*/

    for (int i = 0; i < arr.Neff; i++) {
        printf("[%d] %s\n", i, arr.T[i]);
    }
}

double toDouble (string s) {
/*untuk mengubah string angka menjadi tipe double*/
/*I.S. s terdefinisi dan berupa angka*/
/*F.S. mengembalikan nilai double yang sesuai string*/
    int i;
    double x;
    double dec;
	
	x = 0;
    i = 0;
    while (s[i] != '.' && i<strlen(s)) {
        x = (x * 10) + (s[i] - '0');
        i++;
    }

    dec = 1;
    i++;

    while (i < strlen(s)) {
        dec = dec * 10;
        x = (x * 10) + (s[i] - '0');
        i++;
    }
    x = x / dec;

    return x;
}

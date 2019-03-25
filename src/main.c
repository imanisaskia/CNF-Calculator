/* No.Kelompok	:7
 * Anggota		:Lydia Astrella Wiguna - 13517019
 * 				 Karina Iswara - 13517031
 * 				 Saskia Imani - 13517142
 * Mata Kuliah	:IF 2220 Teori Bahasa Formal dan Automata
 * Topik		:Tugas Besar II Aplikasi CFG dan/atau PDA pada kalkulator*/

#include "parse.h"
#include "syntax.h"
#include "calculate.h"
#include <stdio.h>
//#include <windows.h>

void UI (){
	printf(" ___________________________\n");
	printf("|  _______________________  |\n");
	printf("| | Credits :             | |\n");
	printf("| |                       | |\n");
	printf("| | Lydia A.W. - 13517019 | |\n");
	printf("| | Karina I.  - 13517031 | |\n");
	printf("| | Saskia I.  - 13517142 | |\n");
	printf("| |_______________________| |  _____     _         _     _\n");
	printf("|  ___ ___ ___   ___   ___  | |     |___| |___ _ _| |___| |_ ___ ___\n");
	printf("| | 7 | 8 | 9 | | + | | ^ | | |   --| .'| |  _| | | | .'|  _| . |  _|\n");
	printf("| |___|___|___| |___| |___| | |_____|__,|_|___|___|_|__,|_| |___|_|\n");
	printf("| | 4 | 5 | 6 | | - |  ___  |\n");
	printf("| |___|___|___| |___| |   | |\n");
	printf("| | 1 | 2 | 3 | | x | |On | |\n");
	printf("| |___|___|___| |___| | / | |\n");
	printf("| | . | 0 | = | | / | |OFF| |\n");
	printf("| |___|___|___| |___| |___| |\n");
	printf("|___________________________|\n");
	printf("\n");
}

int main(){
	/*KAMUS*/
	string input;			//untuk menampung input pengguna
	arrString arr;			//untuk menampung input pengguna yang sudah di parse
	arrString arrbracket;	//untuk menampung semua karakter '(' dan ')'
	arrDouble arrd;			//untuk menampung semua elemen angka dalam tipe double
	boolean valid_num;		//untuk mengecek jumlah karakter '.' pada setiap angka
	boolean valid_bracket;	//untuk mengecek tanda kurung berpasangan 
	boolean valid_input;	//untuk mengecek syntax error lainnya
	boolean math_error;		//untuk mengecek ada math error
	
	/*ALGORITMA*/
	UI();
	/*menerima input dari pengguna dan mem-parse input*/
	printf("Silakan masukkan perhitungan yang akan dikalkulasi:\n");
	scanf("%s",input);
	parse(input, &arr);
	
	/*mengecek banyak '.' pada setiap angka*/
	valid_num = IsNumValid(arr);
	if(!valid_num){
		printf("\n");
		printf("SYNTAX ERROR\n");
	}else{					//semua angka memiliki banyak '.' <=1
		
		/*mengecek tanda kurung berpasangan*/
		arrbracket = MakeBracketsArr(arr);
		valid_bracket = BracketsCheck(arrbracket);
		if(!valid_bracket){
			printf("\n");
			printf("SYNTAX ERROR\n");
		}else{				//semua tanda kurung berpasangan
			
			/*mengecek syntax error lainnya*/
			valid_input = InputCheck(arr);
			if(!valid_input){
				printf("\n");
				printf("SYNTAX ERROR\n");
			}else{			//lolos syntax error, melakukan kalkulasi
				toArrDouble(arr,&arrd);
				calculate(&arr,&arrd,&math_error);
				if(!math_error){
					printf("\n");
					if(arrd.T[0] == -0){
						printf("%f\n",arrd.T[0]*-1);
					}else{
						printf("%f\n",arrd.T[0]);
					}
				}
			}
		}
	}
	return 0;
}

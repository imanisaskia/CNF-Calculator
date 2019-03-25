 	/*Implementasi dari calculate.h*/
/*digunakan untuk menghitung input user sesuai urutan prioritas perhitungan*/

#include "calculate.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "parse.h"

int PrioBracket (arrString arr){
/*untuk mengetahui indeks pertama yang akan dikalkulasi menurut prioritas berdasarkan tanda kurung*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error*/
/*F.S. mengembalikan nilai indeks pertama yang akan dikalkulasi dilihat dari prioritas tanda kurung*/
	/*Kamus Lokal*/
	int i,prio;
	/*Algoritma*/
	i = 0;
	prio = 0;
	while (i<arr.Neff && arr.T[i][0] != ')'){
		if (arr.T[i][0] == '('){
			prio=i+1; //setelah '(' pasti ada karakter lain
		}
		i++;
	}
	return prio;
}

int PrioOperator (arrString arr, int i){
/*untuk mengetahui indeks operator yang harus dihitung duluan*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error, i adalah hasil PrioBracket*/
/*F.S. mengembalikan nilai indeks operator yang pertama harus dikalkulasi*/
	/*Kamus lokal*/
	int j,prio;
	boolean found1,found2,found3;
	
	/*Algoritma*/
	found1 = false;
	found2 = false;
	found3 = false;
	prio=i;
	j=i;
	while(j<arr.Neff && arr.T[j][0] != ')'){
		if (arr.T[j][0] == '^'){
			prio = j;
			found1=true;
		}
		j++;
	}
	if (!found1){
		j=i;
		while(j<arr.Neff && arr.T[j][0] != ')' && !found2){
			if (arr.T[j][0] == '*' || arr.T[j][0] == '/'){
				prio = j;
				found2=true;
			}
			j++;
		}
		if(!found2){
			j=i;
			while(j<arr.Neff && arr.T[j][0] != ')' && !found3){
				if (arr.T[j][0] == '+' || arr.T[j][0] == '-'){
					prio = j;
					found3=true;
				}
				j++;
			}
		}
	}
	return prio;
}

void toArrDouble (arrString arr, arrDouble *arrd){
/*untuk membuat array yang berisi seluruh angka dalam tipe double dengan indeks yang sama dengan arrString*/
/*I.S. arr sudah di parse*/
/*F.S. mengembalikan array dengan elemen bertipe double yang isinya semua angka dengan indeks sama dengan arrString*/
	/*Kamus lokal*/
	int i;
	/*Algoritma*/
	(*arrd).Neff = arr.Neff;
	for (i=0;i<arr.Neff;i++){
		if(IsNum(arr.T[i][0])){
			(*arrd).T[i] = toDouble(arr.T[i]);
		}
	}
}

void DelTwo (arrString *arr, int i, char X){
/*untuk menghapus character di antara indeks i, mengubah nilai elemen berindeks i menjadi X, menggeser elemen-elemen lainnya*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error*/
/*F.S. elemen di antara i sudah dihapus,nilai X sudah dimasukkan*/
	/*Kamus lokal*/
	int j;
	
	/*Algoritma*/
	(*arr).T[i][0] = X;
	strcpy((*arr).T[i-1],(*arr).T[i]);
	for (j=i;j<((*arr).Neff-2);j++){
		strcpy((*arr).T[j],(*arr).T[j+2]);
	}
	(*arr).Neff -= 2;
}

void DelTwoDouble (arrDouble *arrd, int i, double X){
/*untuk menghapus letak elemen di antara i agar indeks angka tetap terjaga sama dengan arrString, nilai elemen i menjadi X,
 * menggeser elemen lainnya*/
/*I.S. arrd terdefinisi*/
/*F.S. elemen dengan indeks yang sama dengan elemen di antara i pada arrString sudah dihapus, elemen berindeks i menjadi X*/
/*Kamus lokal*/
	int j;
	
	/*Algoritma*/
	(*arrd).T[i] = X;
	(*arrd).T[i-1]=(*arrd).T[i];
	for (j=i;j<((*arrd).Neff-2);j++){
		(*arrd).T[j]=(*arrd).T[j+2];
	}
	(*arrd).Neff -= 2;
}

void DelOne (arrString *arr, int i, char X){
/*untuk menghapus elemen setelah indeks i, mengubah nilai elemen berindeks i menjadi X, menggeser elemen-elemen lainnya*/
/*I.S. arr sudah di parse, sudah divalidasi syntax error*/
/*F.S. elemen setelah i sudah dihapus,nilai X sudah dimasukkan*/
	/*Kamus lokal*/
	int j;
	/*Algoritma*/
	(*arr).T[i][0] = X;
	for (j=i+1;j<((*arr).Neff-1);j++){
		strcpy((*arr).T[j],(*arr).T[j+1]);
	}
	(*arr).Neff -= 1;
}

void DelOneDouble (arrDouble *arrd, int i, double X){
/*untuk menghapus letak elemen setelah i agar indeks angka tetap terjaga sama dengan arrString, nilai elemen i menjadi X,
 * menggeser elemen lainnya*/
/*I.S. arrd terdefinisi*/
/*F.S. elemen dengan indeks yang sama dengan elemen setelah i pada arrString sudah dihapus, elemen berindeks i menjadi X*/
	/*Kamus lokal*/
	int j;
	/*Algoritma*/
	(*arrd).T[i] = X;
	for (j=i+1;j<((*arrd).Neff-1);j++){
		(*arrd).T[j] =(*arrd).T[j+1];
	}
	(*arrd).Neff -= 1;
}

double lilCalc (double angka1, double angka2, char Op){
/*untuk menghitung angka1 dioperasikan dengan angka2*/
/*I.S. angka1 dan angka2 terdefinisi*/
/*F.S. mengembalikan hasil operasi*/
	/*Kamus lokal*/
	double result;
	/*Algoritma*/
	if (Op == '^') {
		result = (float) pow((double) angka1,angka2);
	} else
	if (Op == '/') {
		result = (angka1 / angka2);
	}else 
	if (Op == '*') {
		result = (angka1 * angka2);
	} else 
	if (Op == '+') {
		result = (angka1 + angka2);
	} else 
	if (Op == '-') {
		result = (angka1 - angka2);
	}
	return result;
}

void calculate (arrString *arr,arrDouble *arrd, boolean *error){
/*untuk mengkalkulasi inputan user berdasarkan prioritas penghitungan sambil mengecek math error*/
/*I.S. arr sudah di parse, sudah lulus uji syntax error, arrd sudah diisi melalui toArrDouble*/
/*F.S. mengeprint hasil kalkulasi atau math error jika ada*/
	/*Kamus lokal*/
	int i,j;
	float temp;
	char tempc;
	/*Algoritma*/
	*error=false;
	while ((*arr).Neff > 1) {
		i = PrioBracket(*arr);
		j = PrioOperator(*arr, i);
		if (((*arr).T[j][0] == '^') || ((*arr).T[j][0] == '/')) {
			if ((*arr).T[j][0] == '^') {	
				if (fmod((1/(*arrd).T[j+1]), 2.0) == 0 && (*arrd).T[j-1] <0) {
					printf("\n");
					printf("DANGER !!! MATH ERROR !!! Akar imajiner nih...\n");
					(*arr).Neff = 1;
					*error=true;
				}
			}else 
			if ((*arr).T[j][0] == '/') {
				if ((*arrd).T[j+1] == 0) {
					printf("\n");
					printf("DANGER !!! MATH ERROR !!! Pembagi kok 0 sih...\n");
					(*arr).Neff = 1;
					*error=true;
				} 
			} 
		}
		if((*arr).Neff != 1) {
			if ((*arr).T[j-1][0] == '(') {
				if (IsNum((*arr).T[j+1][0])) {
					if((*arr).T[j][0] == '-'){ 
						temp = ((*arrd).T[j+1]) * -1;
					}else{
						temp = ((*arrd).T[j+1]);
					}
					tempc =  '0';
					DelOne(arr,j,tempc);
					DelOneDouble(arrd,j,temp);
				} else
				if ((*arr).T[j+1][0] == ')') {
					temp = ((*arrd).T[j]);
					tempc = '0';
					DelTwo(arr,j, tempc);
					DelTwoDouble(arrd,j,temp);
				} 
				//else if (IsOp((*arr).T[j+1][0])){}
			} else 
			if (IsNum((*arr).T[j-1][0])) {
				temp = lilCalc(((*arrd).T[j-1]),((*arrd).T[j+1]),(*arr).T[j][0]);
				tempc = '0';
				DelTwo(arr,j,tempc);
				DelTwoDouble(arrd,j,temp);
			} else 
			if (j==0){
				if(j+1<(*arr).Neff){
					if((*arr).T[j][0] == '-'){ 
						temp = ((*arrd).T[j+1]) * -1;
					}else{
						temp = ((*arrd).T[j+1]);
					}
					tempc =  '0';
					DelOne(arr,j,tempc);
					DelOneDouble(arrd,j,temp);
				}
			}
		}

	}
}

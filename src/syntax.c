/*Implementasi dari syntax.h*/
/*Digunakan untuk memeriksa syntax error pada input user yang sudah di parse*/

#include "syntax.h"
#include <string.h>
#include <stdio.h>

boolean Search (string s, char C){
/*untuk search apakah ada karakter C pada elemen matriks*/
/*I.S. M,i,j,C terdefinisi*/
/*F.S. mengembalikan true jika terdapat character C pada elemen matriks berindeks i j, false sebaliknya*/
	/*Kamus lokal*/
	int k;
	boolean found;
	/*Algoritma*/
	found=false;
	k=0;
	while ((k < strlen(s) && !found)){
		if (s[k] == C){
			found=true;
		}else{
			k++;
		}
	}
	return found;
}

arrString MakeBracketsArr (arrString arr){
/* membuat array yang isinya hanya tanda kurung untuk dicek apakah tanda kurung berpasangan*/
/* I.S. arr sudah di parse*/
/* F.S. mengembalikan array yang hanya berisi tanda kurung*/
	/*Kamus lokal*/
	arrString arrbracket;
	int i,j;
	
	/*Algoritma*/
	j=0;
	arrbracket.Neff = 0;
	for (i=0;i<arr.Neff;i++){
		if (arr.T[i][0] == '(' || arr.T[i][0] == ')'){
			arrbracket.T[j][0] = arr.T[i][0];
			arrbracket.Neff +=1;
			j++;
		}
	}
	return arrbracket;
}

char VariableBrackets (string s){
/* Mencari variable asal dari sebuah string yang berbentuk 2 variable atau 1 terminal dari aturan produksi kurung berpasangan*/
/* I.S. string s sudah dalam bentuk dua variable atau 1 terminal*/
/* F.S. mengembalikan variabel asal jika ada atau 'Z' bila tidak ada*/
/* Contoh : A -> AB | a
	VariableBrackets ("AB") = 'A'*/
	/*Algoritma*/
	if (strcmp(s,"EF") == 0 || strcmp(s,"EG") == 0){
		return 'D';
	}else if(strcmp(s,"EH")==0 || strcmp(s,")")==0){
		return 'G';
	}else if (strcmp(s,"GD")==0){
		return 'F';
	}else if (strcmp(s,"(")==0){
		return 'E';
	}else if (strcmp(s,"GG")==0){
		return 'H';
	}else{
		return 'Z';
	}
}
	
boolean BracketsCheck (arrString arr){
/* mengecek apakah tanda kurung berpasangan memakai algoritma CYK*/
/* I.S. arr sudah di-parse dan di-MakeBracketsArr*/
/* F.S. mengembalikan nilai true jika tanda kurung berpasangan, false jika tanda kurung tidak berpasangan*/
	/*Kamus lokal*/
	MATRIKSCYK M;
	int i,j,k,l,m,n,o,p,kurang;
	string temp;
	char c;
	boolean found;
	
	/* Algoritma*/
	if (arr.Neff == 0){
		return true;
	}else{
		M.NBrsEff = arr.Neff;
		M.NKolEff = arr.Neff;
		for (i=0;i<arr.Neff;i++){
			M.Mem[i][i][0] = VariableBrackets(arr.T[i]);
		}
		kurang=1;
		for (m=1;m<arr.Neff;m++){
			for (j=m;j<arr.Neff;j++){
				i=j-kurang;
				n=0;
				k=i;
				l=k+1;
				while(l<=j){
					if (strlen(M.Mem[i][k]) != 0 && strlen(M.Mem[l][j]) !=0){
						for (o=0;o<strlen(M.Mem[i][k]);o++){
							for(p=0;p<strlen(M.Mem[l][j]);p++){
								temp[0]=M.Mem[i][k][o];
								temp[1]=M.Mem[l][j][p];
								c = VariableBrackets(temp);
								if (c!='Z'){
									M.Mem[i][j][n]=c;
									n++;
								}
							}
						}
					}
					k++;
					l++;
				}
			}
			kurang++;
		}
		found=false;
		i=0;
		while(i<strlen(M.Mem[0][arr.Neff-1]) && !found){
			if (M.Mem[0][arr.Neff-1][i] == 'D'){
				found=true;
			}else{
				i++;
			}
		}
		if (found){
			return true;
		}else{
			return false;
		}
	}

}

void Variable (string s, string *temp, int *neff){
/* Mencari variable asal dari sebuah string yang berbentuk 2 variable atau 1 terminal dari aturan produksi input kalkulator*/
/* I.S. string s sudah dalam bentuk dua variable atau 1 terminal*/
/* F.S. mengembalikan variabel asal jika ada atau 'Z' bila tidak ada sebanyak neff*/
/* Contoh : A -> AB | a
	VariableBrackets ("AB") = "A"*/
	/*kamus lokal*/
	int i;
	
	/*Algoritma*/
	i=0;
	*neff =0;
	if (strcmp(s,"II") == 0 || strcmp(s,"IJ") == 0 || strcmp(s,"IK") == 0 ||strcmp(s,"NI") == 0||strcmp(s,"NJ") == 0 ||
	strcmp(s,"NK") == 0||strcmp(s,"JI") == 0||strcmp(s,"JK") == 0||strcmp(s,"OI") == 0||strcmp(s,"OK") == 0 ||
	strcmp(s,"PI") == 0||strcmp(s,"PK") == 0||strcmp(s,"KJ") == 0||strcmp(s,"KL") == 0||strcmp(s,"KM") == 0||
	IsNum(s[0])){
		*temp[i]='S';
		*neff += 1;
		i++;
	}
	if(strcmp(s,"II")==0 || strcmp(s,"IJ")==0||strcmp(s,"IK") == 0||strcmp(s,"NI") == 0||strcmp(s,"NJ") == 0||
	strcmp(s,"NK") == 0){
		*temp[i]='I';
		*neff +=1;
		i++;
	}
	if (strcmp(s,"JI")==0||strcmp(s,"JK") == 0||strcmp(s,"OI") == 0||strcmp(s,"OK") == 0||strcmp(s,"PI") == 0||
	strcmp(s,"PK") == 0){
		(*temp)[i]='J';
		*neff +=1;
		i++;
	}
	if (strcmp(s,"KJ")==0||strcmp(s,"KL") == 0||strcmp(s,"KM") == 0|| IsNum(s[0])){
		(*temp)[i]='K';
		*neff +=1;
		i++;
	}
	if (strcmp(s,"LI")==0||strcmp(s,"LJ") == 0||strcmp(s,"LK") == 0||strcmp(s,"QI") == 0||strcmp(s,"QJ") == 0||
	strcmp(s,"QK") == 0||strcmp(s,"RI") == 0||strcmp(s,"RJ") == 0||strcmp(s,"RK") == 0||strcmp(s,"TI") == 0||
	strcmp(s,"TJ") == 0||strcmp(s,"TK") == 0){
		(*temp)[i]='L';
		*neff +=1;
		i++;
	}
	if(strcmp(s,"MJ")==0||strcmp(s,"ML") == 0||strcmp(s,"MM") == 0||strcmp(s,")") == 0){
		(*temp)[i]='M';
		*neff +=1;
		i++;
	}
	if (strcmp(s,"(") == 0){
		(*temp)[i]='N';
		*neff +=1;
		i++;
	}
	if(strcmp(s,"-") == 0){
		(*temp)[i]='O';
		*neff +=1;
		i++;
	}
	if(strcmp(s,"+") == 0){
		(*temp)[i]='P';
		*neff +=1;
		i++;
	}
	if(strcmp(s,"*") == 0){
		(*temp)[i]='Q';
		*neff +=1;
		i++;
	}
	if(strcmp(s,"/") == 0){
		(*temp)[i]='R';
		*neff +=1;
		i++;
	}
	if(strcmp(s,"^") == 0){
		(*temp)[i]='T';
		*neff +=1;
		i++;
	}
	if(*neff ==0){
		(*temp)[0]='Z';
		*neff +=1;
	}
}

boolean InputCheck (arrString arr){
/* mengecek input diterima memakai algoritma CYK*/
/* I.S. arr sudah di-parse */
/* F.S. mengembalikan nilai true jika input diterima, false jika input tidak diterima*/
/*Kamus lokal*/
	MATRIKSCYK M;
	int i,j,k,l,m,n,o,p,q,kurang,neff;
	string temp,s;
	boolean found;
	
	/* Algoritma*/
	if (arr.Neff == 0){
		return true;
	}else{
		M.NBrsEff = arr.Neff;
		M.NKolEff = arr.Neff;
		for (i=0;i<arr.Neff;i++){
			n=0;
			Variable(arr.T[i],&s,&neff);
			for (q=0; q<neff;q++){
				if (s[q] != 'Z'){
					M.Mem[i][i][n] = s[q];
					n++;
				}
			}
		}
		kurang=1;
		for (m=1;m<arr.Neff;m++){
			for (j=m;j<arr.Neff;j++){
				i=j-kurang;
				n=0;
				k=i;
				l=k+1;
				while(l<=j){
					if (strlen(M.Mem[i][k]) != 0 && strlen(M.Mem[l][j]) !=0){
						for (o=0;o<strlen(M.Mem[i][k]);o++){
							for(p=0;p<strlen(M.Mem[l][j]);p++){
								temp[0]=M.Mem[i][k][o];
								temp[1]=M.Mem[l][j][p];
								Variable(temp,&s,&neff);
								for(q=0;q<neff;q++){
									if ((s[q]!='Z') && !Search(M.Mem[i][j], s[q])) {
										M.Mem[i][j][n]=s[q];
										n++;
									}
								}
							}
						}
					}
					k++;
					l++;
				}
			}
			kurang++;
		}
		found=false;
		i=0;
		while(i<strlen(M.Mem[0][arr.Neff-1]) && !found){
			if (M.Mem[0][arr.Neff-1][i] == 'S'){
				found=true;
			}else{
				i++;
			}
		}
		if (found){
			return true;
		}else{
			return false;
		}
	}
}


boolean IsNumValid (arrString arr){
/*memeriksa banyak '.' pada angka. Valid bila banyak '.' 0 atau 1. Tidak valid bila banyak '.' lebih dari 1.
 * I.S. string input sudah diparse
 * F.S. mengembalikan nilai false bisa ada angka tidak valid, true jika semua angka valid*/
	/*Kamus lokal*/
	boolean valid;
	int count;
	int i,j;
	
	/*Algoritma*/
	valid = true;
	i=0;
	while(i<arr.Neff && valid){
		if (IsNum(arr.T[i][0])){
			j=0;
			count=0;
			while (j<strlen(arr.T[i])){
				if (arr.T[i][j] == '.'){
					count+=1;
				}
				j++;
			}
			if(count>1){
				valid = false;
			}
		}
		i++;
	}
	return valid;
}

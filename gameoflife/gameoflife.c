#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

void set_default_color(HANDLE hstd){
    SetConsoleTextAttribute(hstd, 15|0);
}


void check_neighbours(int posa, int posb, bool ah[], bool ad[], bool md[], bool status, bool temp[]){
	int asuseds = 0;
	if (posa!=0){
		if (ah[posb-1]==true){asuseds++;}
		if (ah[posb]==true){asuseds++;}
		if (ah[posb+1]==true){asuseds++;}
	}
	if (posa!=19){
		if (ad[posb-1]==true){asuseds++;}
		if (ad[posb]==true){asuseds++;}
		if (ad[posb+1]==true){asuseds++;}
		}
	if (posb!=49){
	if (md[posb+1]==true){asuseds++;}}
	if (posb!=0){
	if (md[posb-1]==true){asuseds++;}}
	if (status==true){
		if (asuseds==3 or asuseds==2){
			temp[posb]=true;
		} else {
			temp[posb]=false;
		}
	} else {if (asuseds==3){temp[posb]=true;}}

}



int main(){
	HANDLE hstd = GetStdHandle(STD_OUTPUT_HANDLE);
	//SetConsoleTextAttribute(hstd, 15|240);
	bool cells[20][50];
	bool temp[20][50];
	for (int i=0;i<20;i++){
		for (int j=0;j<50;j++){
			cells[i][j]=false;
			temp[i][j]=false;
		}
	}



	temp[10][3]=true;temp[10][2]=true;temp[11][3]=true;temp[11][2]=true;
	temp[8][36]=true;temp[8][37]=true;temp[9][36]=true;temp[9][37]=true;
	temp[8][36]=true;temp[8][37]=true;temp[9][36]=true;temp[9][37]=true;
	temp[8][22]=true;temp[8][23]=true;temp[9][22]=true;temp[9][23]=true;temp[10][22]=true;temp[10][23]=true;temp[7][24]=true;temp[7][26]=true;temp[6][26]=true;temp[11][24]=true;temp[11][26]=true;temp[12][26]=true;
	temp[11][19]=true;temp[11][18]=true;temp[12][18]=true;temp[10][18]=true;temp[9][17]=true;temp[13][17]=true;temp[11][16]=true;
	temp[8][15]=true;temp[8][14]=true;temp[9][13]=true;temp[10][12]=true;temp[11][12]=true;temp[12][12]=true;temp[13][13]=true;temp[14][14]=true;temp[14][15]=true;


	

	while (true){
		for (int i=0;i<20;i++){
			for (int j=0;j<50;j++){
				cells[i][j]=temp[i][j];
				temp[i][j]=false;
			}
		}
		for (int i=0;i<20;i++){
			for (int j=0;j<50;j++){
				bool status = cells[i][j];
				if (i!=19 and i!=0){
				check_neighbours(i, j, cells[i-1], cells[i+1], cells[i], status, temp[i]);}
				else if (i==19){check_neighbours(i, j, cells[i-1], cells[i], cells[i], status, temp[i]); }
				else if (i==0) {check_neighbours(i, j, cells[i], cells[i+1], cells[i], status, temp[i]);}

			}
		}
		system("cls");
		for (int i=0;i<20;i++){
			for (int j=0;j<50;j++){
				if (cells[i][j]!=false){
					printf(" ");
				} else {
					SetConsoleTextAttribute(hstd, 15|240); 
					printf(" ");
					set_default_color(hstd);
				}

			} printf("\n");
		}
		Sleep(1);
	}

	printf("\n");
	system("pause");


return 0;
}
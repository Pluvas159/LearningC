#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <stdbool.h>




int main(){
	float uhol;
	bool end = false;

	float* pcesta;
	float* xcesta;
	int pocet = 0;


	scanf("%f",&uhol);
	uhol = uhol/57.29578;

	float yspeed = sin(uhol);
	float xspeed = cos(uhol);

	pcesta = (float*)malloc(pocet*sizeof(float));
	xcesta = (float*)malloc(pocet*sizeof(float));
	float yfull = yspeed;
	float xfull = xspeed;

	while(!end){
		if (pcesta[pocet-1]!=round(yfull) || xcesta[pocet-1]!=round(xfull)){
			pocet++;
			pcesta = (float*)realloc(pcesta, pocet*sizeof(float));
			xcesta = (float*)realloc(xcesta, pocet*sizeof(float));
			pcesta[pocet-1]=round(yfull);
			xcesta[pocet-1]=round(xfull);
		}
		yspeed = yspeed-0.02; 
		yfull = yfull + yspeed;
		xfull = xfull + xspeed;
		if (pcesta[pocet-1]<=0){end=true;break;}
		//printf("%f %f \n", pcesta[pocet-1], xcesta[pocet-1]);
	}
int max =0;
int pmax = 0;
for(int i=0; i<pocet; i++){
	//printf("%f %f \n", pcesta[i], xcesta[i]);

	if (pcesta[i]>max){
		max = pcesta[i];
		pmax = 1;
	} else if (pcesta[i]==max){
		pmax++;
	}
}
//printf("%i",pmax);

int* arry = (int*)malloc(pmax*sizeof(int));;
int* arrx = (int*)malloc(pmax*sizeof(int));;;
int arrp = 0;
printf("\n");

for(int j=0; j<max; j++){
	for(int i=0; i<pocet; i++){
		if (pcesta[i]==max-j){
			arry[arrp]=pcesta[i];
			arrx[arrp]=xcesta[i];
			arrp++;

		}
	}
	for(int i=0; i<arrp; i++){
		if (i==0){
			for (int v = 0; v<arrx[0];v++){
				printf(" ");}
			printf("*");
		} else {
			for (int v = 0; v<arrx[i]-arrx[i-1]-1;v++){
				printf(" ");}
			if (arrx[i]!=arrx[i-1]){
				printf("*");}
			}
		}
	printf("\n");
	arrp=0;

}








free(pcesta);
free(xcesta);
free(arry);
free(arrx);
printf("\n");
system("pause");

return 0;
}
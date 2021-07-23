#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>


int main(){
	char c;
	int y = 0;
	int x = 0;
	int temp = 0;
	char* ptr;
	int* gptr;
	bool zle = false;

	ptr = (char*)malloc(x * sizeof(char));

	while (c!='a'){
		scanf("%c",&c);
		if (c=='\n'){
			if (temp==x){
				temp = 0;
				y++;
				ptr = (char*)realloc(ptr, x*(y+1)*sizeof(char));
			} else {zle = true; break;}
		} else if (c=='.' || c=='*'){
			if (y==0){
				ptr[x] = c;
				x++;
				temp++;
				ptr = (char*)realloc(ptr, x*sizeof(char));
			} else {
				ptr[x*y+temp]=c;
				temp++;
			}
		} else if (c!='a'){zle = true; break;} 
	}
	if (!zle){
		gptr = (int*)malloc(x*y*sizeof(int));
		for(int i = 0; i<x*y;i++){
			*(gptr+i)=0;
			}
		char v;
		for(int i =0; i<x*y;i++){
				v = ptr[i];
				if (v=='*'){
					*(gptr+i)=-1;
					if (i%x!=1){
						if (ptr[i-1]!='*'){*(gptr+i-1) = *(gptr+i-1)+1;}
						if (i/x!=y-1){
							if (ptr[i+x-1]!='*'){*(gptr+i+x-1) = *(gptr+i+x-1)+1;}}
						if (i/x!=0){
							if (ptr[i-x-1]!='*'){*(gptr+i-x-1) = *(gptr+i-x-1)+1;}}
						}
					if (i%x!=0){
							if (ptr[i+1]!='*'){*(gptr+i+1) = *(gptr+i+1)+1;}
							if (i/x!=y-1){
								if (ptr[i+x+1]!='*'){*(gptr+i+x+1) = *(gptr+i+x+1)+1;}}
							if (i/x!=0){
								if (ptr[i-x+1]!='*'){*(gptr+i-x+1) = *(gptr+i-x+1)+1;}}
							}
					if (i/x!=y-1){
					if (ptr[i+x]!='*'){*(gptr+i+x) = *(gptr+i+x)+1;}}
					if (i/x!=0){
					if (ptr[i-x]!='*'){*(gptr+i-x) = *(gptr+i-x)+1;}}
				}
		}
		printf("%c", ptr[30]);
		printf("\n");
		for(int i = 0; i<x*y; i++){
			if(i%x==0 && i!=0){printf("\n");}
			if (*(gptr+i)==-1){printf("*");}
			else if (*(gptr+i)==0){printf(".");}
			else {
			printf("%i",*(gptr+i));}

		}
	} else {
		printf("Zly vstup\n");
	}

free(ptr);
free(gptr);
printf("\n");
system("pause");


return 0;
}
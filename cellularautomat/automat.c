#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>



void set_default_color(HANDLE hstd){
    SetConsoleTextAttribute(hstd, 15|0);
}

int valueinarray(int val, int arr[400], int pos){
    int i;
    for(i = 0; i < pos; i++){
        if(arr[i] == val) return true;
    }
    return false;
}

bool boolinarray(bool value, bool array[400]){
    for (int i = 0; i<400;i++){
        if (array[i]==value){
            return true;
            }
    }
    return false;
}

int get_random(int high){
    int num;
    do {
    num = rand();
    } while (num>high);
    return num;
}


void check_neighbours(int posa, int posb, bool ah[], bool ad[], bool md[], bool* a, bool zodpovedny, bool (*everyone)[400]){
    if (posa!=0){
        if(ah[posb]==false){
            if (!zodpovedny){
                if(get_random(10)>8){
                    ah[posb]=true;
                    *a = true;
                    (*everyone)[(posa-1)*20+posb]=true;
                }
            }
        }
    }
    if (posa!=20){
        if(ad[posb]==false){
            if (!zodpovedny){
                if(get_random(10)>8){
                    ad[posb]=true;
                    *a = true;
                    (*everyone)[(posa+1)*20+posb]=true;
                }
            }
        }  
    } 
    if(md[posb-1]==false){
        if (!zodpovedny){
            if(get_random(10)>8){
                md[posb-1]=true;
                *a = true;
                (*everyone)[posa*20+posb-1]=true;}
            }
        }
    if(md[posb+1]==false){
        if (!zodpovedny){
            if(get_random(10)>8){
                md[posb+1]=true;
                *a = true;
                (*everyone)[posa*20+posb+1]=true;}
            }
        }
} 

int main(){
    srand(time(NULL));
    HANDLE hstd = GetStdHandle(STD_OUTPUT_HANDLE);
    int sizea, sizeb;
    sizea = 20;
    sizeb = 20;
    int data[sizea][sizeb];
    int v = 10;
    bool nakazeny[sizea][sizeb];
    bool zodpovedny[sizea][sizeb];
    int datas[400];
    bool everyone[400];
    int pos = 0;


    for (int i = 0; i<sizea; i++){
        for (int j = 0; j<sizeb; j++){
            everyone[pos]=false;
            data[i][j]=v;
            v++;
            nakazeny[i][j]=false;
            pos++;
            if (get_random(100)>98){
               zodpovedny[i][j]=true;} else {zodpovedny[i][j]=false;}
        }
    }
    int num = get_random(20);
    nakazeny[num][num] = true;
    everyone[num*20+num] = true;

bool a, end;
do {
    pos = 0;
    for (int posa = 0; posa<sizea; posa++){
        for (int posb = 0; posb<sizeb; posb++){
            if(nakazeny[posa][posb]==true){
                datas[pos]=data[posa][posb];
                pos++;

            }    
        }
    }


    a = false;
    end = false;
    for (int posa = 0; posa<sizea; posa++){
        for (int posb = 0; posb<sizeb; posb++){
            if(nakazeny[posa][posb]==true){
                if ((posa!=0) && (posa!=20)){
                    if (valueinarray(data[posa][posb], datas, pos)){
                            check_neighbours(posa, posb, nakazeny[posa-1], nakazeny[posa+1], nakazeny[posa], &a, zodpovedny[posa][posb], &everyone);
                    }
                } else if (posa==0) {
                    check_neighbours(posa, posb, nakazeny[posa], nakazeny[posa+1], nakazeny[posa], &a, zodpovedny[posa][posb], &everyone);
                } else if (posa==20){
                    check_neighbours(posa, posb, nakazeny[posa-1], nakazeny[posa], nakazeny[posa], &a, zodpovedny[posa][posb], &everyone);
                }
            }
        }
    } 

    Sleep(500);
    system("cls");
    for (int i = 0; i<sizea; i++){
        for (int j = 0; j<sizeb; j++){
            if (nakazeny[i][j]==true){
                SetConsoleTextAttribute(hstd, (BACKGROUND_RED));
            } else if (zodpovedny[i][j]==true){ 
                SetConsoleTextAttribute(hstd, (BACKGROUND_BLUE));
            } else {
                SetConsoleTextAttribute(hstd, (BACKGROUND_GREEN));}
            printf("%i ", nakazeny[i][j]);
        }
        set_default_color(hstd);
        printf("\n");
    } 
} while (boolinarray(false, everyone));





    // SetConsoleTextAttribute(hstd, (BACKGROUND_GREEN));
    // set_default_color(hstd);

    printf("\n");
	system("pause");
	return 0;
}



#include <stdio.h>
#include <stdlib.h>

// BÝRÝM MATRÝS OLUSTURMA//
int i,j;
void matrisOlustur(int ***dizi,int satir,int sutun){
	*dizi=(int**)malloc(sizeof(int*)*satir);
	
	for(i=0;i<satir;i++){
		*(*dizi+i)=(int*)malloc(sizeof(int)*sutun);
		for(j=0;j<sutun;j++){
			if(i==j){
				*(*(*dizi+i)+j)=1;
			}else{
				*(*(*dizi+i)+j)=0;
			}
		}
	}
	
}

void matrisYaz(int**dizi,int satir,int sutun){
	for(i=0;i<satir;i++){
		for(j=0;j<sutun;j++){
			printf("%4d",*(*(dizi+i)+j));
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
	int **A;
	matrisOlustur(&A,5,5);
	matrisYaz(A,5,5);
	
	return 0;
}

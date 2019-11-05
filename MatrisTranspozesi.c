#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int i,j,k;
void matrisOlustur(int ***dizi,int satir,int sutun){
    *dizi=(int**)malloc(satir*sizeof(int*));
    for(i=0; i<satir; i++){
        *(*dizi+i)= (int*)malloc(sutun*sizeof(int));         //BURADA BELLEKTEN 2 BOYUTLU MATRIS ÝÇÝN YER AÇIP ELEMAN ATIYORUZ.
        for(j=0; j<sutun; j++)
            *(*(*dizi+i)+j)= rand()%5;
    }
}

void matrisYaz(int **dizi,int satir,int sutun){
    for(i=0; i<satir; i++){
        for(j=0; j<sutun; j++) printf("%4d ",*(*(dizi+i)+j));
        printf("\n");
    }
}

void matrisTranspoz(int **A,int **B,int satir ,int sutun){
	for(i=0;i<satir;i++){                                        //Bir matrisin transpozesi demek satirlarý sutun yapmak demek
		for(j=0;j<sutun;j++){                                     // o halde B matrisini B[i][j] yerine B[j][i] olarak tanýmlamak gerekli.
		    *(*(B+j)+i)=*(*(A+i)+j);                            // Daha sonra A matrisinin ij'nci elemaný B'nin ji'nci elemaný olamlý.
		}
	}
}

int main(int argc, char *argv[]) {
	int **A;
	int **B;
	matrisOlustur(&A,2,3);
	matrisOlustur(&B,3,2);
	matrisYaz(A,2,3);
	printf("*********A MATRISININ TRANSPOZESI***** \n \n");
	matrisTranspoz(A,B,2,3);
    matrisYaz(B,3,2);	
	return 0;
}

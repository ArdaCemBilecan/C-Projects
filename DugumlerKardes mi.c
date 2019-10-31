#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree'deki düğümlerin kardeş olup olmadığını kontrol eden fonksiyon//

int kardesmi(struct ikiliAramaAgaci*agac,struct dugum *aranan1,struct dugum *aranan2){
	struct dugum *d;
	struct dugum *geri;
	d=agac->kok
	while(d->data != aranan1->data){
		geri=d;
		if(d->data > aranan1) d=d->sol;
		else (d->data< aranan1) d= d->sag;
		
	}
	
	if(geri->sag->data == aranan1->data && geri->sol->data==aranan2->data  || geri->sag->data==aranan2->data && geri->sol->data==aranan1->data) return 1;
	else return 0;
	
}

int main(int argc, char *argv[]) {
	return 0;
}

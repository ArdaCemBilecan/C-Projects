#include <stdio.h>
#include <stdlib.h>

// 2 listenin ayný olup olmadýðýný kontrol eden fonksiyon//

int Eslermi(struct hucre **liste1,struct hucre **liste2){
int a = 0;
int b = 0;
	struct hucre *l1 = *liste1;
	struct hucre *l2 = *liste2;

	while(l1!=NULL){
		l1 = l1->ileri;
		a++;
	}
		while(l2!=NULL){
		l2 = l2->ileri;
		b++;
	}
	if(a!=b){		
		return 0;
	}
	else{
		int kontrol = 1;
		l1 = *liste1;
		l2= *liste2;
			while(l1!=NULL){
				if(l1->data == l2->data){
					kontrol = 1;
				}else{
					kontrol = 0;
					break;
				}
				l1 = l1->ileri;
				l2= l2->ileri;
			}
			if (kontrol == 1) return 1;
			else return 0;
		}	
}


int main(int argc, char **argv[]) {	
	return 0;
}

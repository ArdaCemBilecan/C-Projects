#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct dugum{
	int veri;
};

struct heap{
	struct dugum *dizi;
	int kapasite;
	int elemanSayisi;
};

struct heap *heapOlustur(int kapasite){
    struct heap *gecici;
    gecici=(struct heap*)malloc(sizeof(struct heap));

    if(gecici==NULL){
        printf("Malloc basarisiz. Yer ayrilamadi...");
        exit(1);
    }

    gecici->dizi=(struct dugum*)malloc(kapasite*sizeof(struct dugum));

    if(gecici->dizi==NULL){
            printf("Malloc basarisiz. Yer ayrilamadi...");
        exit(1);
    }

    gecici->kapasite=kapasite;
    gecici->elemanSayisi=0;
    return gecici;
}

void heapYazdir(struct heap *heap){
	int i;
	for(i=0;i<heap->elemanSayisi;i++){
		printf("%4d",heap->dizi[i].veri);
	}
}

void initialize(struct heap *heap,int elemanSayisi,int aralik){
    int i,j;
    int yeni,cik;
    
    if(elemanSayisi >heap->kapasite) {
        printf("Heap gerekli kapasiteye sahip degil... exit...\n");
        exit(1);
    }
    srand(time(NULL));
    
    heap->dizi[0].veri=rand()%aralik;
    for(i=1; i<elemanSayisi; i++){
        while(1){
            cik=1;
            yeni=rand()%aralik;
            for(j=0; j<i; j++){
                if(yeni==heap->dizi[j].veri){
                    cik=0; break;
                }
            }
            if(cik==0) continue;
            heap->dizi[i].veri=yeni;
            break;
        }
    }
    heap->elemanSayisi=elemanSayisi;
}
void bubleDown(struct heap*heap,int index){
	int sag = index*2+2;
	int sol = index*2+1;
	int temp;
	while((sol<heap->elemanSayisi && heap->dizi[index].veri<heap->dizi[sol].veri) || 
	(sag<heap->elemanSayisi && heap->dizi[index].veri<heap->dizi[sag].veri)){                  
		if(sag>=heap->elemanSayisi || heap->dizi[sol].veri>heap->dizi[sag].veri){                            
			temp = heap->dizi[sol].veri;
			heap->dizi[sol].veri = heap->dizi[index].veri;
			heap->dizi[index].veri = temp;
			index = index*2+1;                                        // Eger indeximiz degeri sag veya sol index degerinden kucuk ise
		}else{                                                       // Degeri buyuk olan indexle yer degistirerek MAX heap yapiyoruz.
			temp = heap->dizi[sag].veri;                                                                     
			heap->dizi[sag].veri = heap->dizi[index].veri;                     //  0-)     90                                0-)    95
			heap->dizi[index].veri=temp;                                        // 1-)  95   3-) 85 ise     bubleDown ile    1-)  90   2-) 85                               
			index = index*2+2;                                                                                                      
		}                                                                             
		sol = index*2+1;
		sag = index*2+2;
	}	
}

void bubleUp(struct heap*heap,int index){
	int temp;
	int parent;
	parent = (index-1)/2;
	while(heap->dizi[parent].veri<heap->dizi[index].veri){
		temp = heap->dizi[parent].veri;
		heap->dizi[parent].veri = heap->dizi[index].veri;       // Eger indexin atasi indexten kucuk ise atanan indexi ata yapiyoruz.
		heap->dizi[index].veri = temp;                          // Butun Agaci boyle dolasarak agacimizi max heap hale getiriyoruz.
		index = parent;
		parent = (index-1)/2;
	}
}
void makeHeap(struct heap*heap){
	int i;
	for(i=heap->elemanSayisi/2-1;i>=0;i--) bubleDown(heap,i);          // Karmasik olan agaci Heap hale getiriyoruz.
}
void heapInsert(struct heap*heap,int veri){
	if(heap->elemanSayisi<heap->kapasite){
		heap->elemanSayisi++;
		heap->dizi[heap->elemanSayisi-1].veri = veri;
		bubleUp(heap,heap->elemanSayisi-1);
	}
}
int isHeap(struct heap*heap){
	int i;
	if(heap==NULL) return 1;
	for(i=0;i<heap->elemanSayisi/2;i++){
		if(heap->dizi[i].veri<heap->dizi[i*2+1].veri ||heap->dizi[i].veri<heap->dizi[i*2+2].veri ) return 0;
		// Heap mi degil mi onun kontrolu
	}
	return 1;
}


int main(int argc, char *argv[]) {
	struct heap*heap;
	heap = heapOlustur(10);
	initialize(heap,7,101);
	heapYazdir(heap);
	printf(" Heap mi?:  %d ",isHeap(heap));
	makeHeap(heap);
	printf("\n");
	heapYazdir(heap);
	printf(" Heap mi?:  %d ",isHeap(heap));
	return 0;
}


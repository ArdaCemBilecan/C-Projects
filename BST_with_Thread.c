#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h> //process id için   pid_t için
#include <unistd.h>  // fork fonksiyonu için
#include<sys/wait.h> // wait komutu için
#include<time.h>


void yaprak(){
//dosya oluşturacak

char dosyaismi[20];
sprintf(dosyaismi,"%d.txt",getpid()); 
FILE *fp = fopen(dosyaismi,"w");
srand(getpid());
fprintf(fp,"%d",(rand()%100));
fclose(fp);

}

void ebeveyn(int pid1,int pid2){
    // Child'ların dosyalarını açıp okuyacak
    wait(NULL);
    char dosyaismi1[20];
    sprintf(dosyaismi1,"%d.txt",pid1);

    char dosyaismi2[20];
    sprintf(dosyaismi2,"%d.txt",pid2);

    char dosyaismi3[20];
    sprintf(dosyaismi3,"%d.txt",getpid());

    FILE *fp1 , *fp2,*fp3;
    fp1 = fopen(dosyaismi1,"r");
    fp2 = fopen(dosyaismi2,"r");

    int sol,sag;
    fscanf(fp1,"%d",&sol);
    fscanf(fp2,"%d",&sag);

    fclose(fp1);
    fclose(fp2);

    fp3 = fopen(dosyaismi3,"w");
    fprintf(fp3,"%d",(sol+sag));
    fclose(fp3);


}


void agac_olustur(int yukseklik){

if(yukseklik == 0){
    yaprak();
    return;
}
int pid = fork();

if(pid>0){
  int pid2 = fork();
  if(pid2>0){
      // parent işlem
      wait(NULL);
      printf("Parent: %d  c1: %d   c2: %d \n",getpid(),pid,pid2);
      fflush(stdout);
      ebeveyn(pid,pid2);
  }else if(pid2 == 0){
      // sol cocuk
      agac_olustur(--yukseklik);
  }
}
  else if(pid == 0){
      //sag cocuk
      agac_olustur(--yukseklik);
  }
}



int main(){

    agac_olustur(3);

    
 return 0;
}
#include <stdio.h>
#include <stdlib.h>
//Soru geregi aranilan dugumun var oldugunu kabul ediyoruz.
	int i;
int kokeOlanUzaklik(struct dugum*kok,struct dugum*a){
	struct dugum*d;                      
	d=kok;
	while(d->veri != a->veri){           // Burada istenilen dugume gidiyoruz.
	if(d->veri < a->veri){
		d= d->sag;
		i++;
	}     //Aradigimiz sayi, kokun verisinden buyukse kok->sag yapiyoruz. Ve i++ yaparak uzakligi hesapliyoruz.
	   
	    else{
		d=d->sol; 
		i++;
		}     //Aradigimiz Sayi, kokun verisinden kucukse kok->sol yapiyoruz. Ve i++ yaparak uzakligi hesapliyoruz.
	 	             
	}
	
	return i;   // i return ederek kac defa saga veya sola gittigini yani uzakligi bulmus oluyoruz. 	
	
}

/*   
Ornegin:                                                     100
                                                    80                  120
                                                70      85          110      130
                                                                          125   140
                                                                        
                    seklinde bir agacimiz olsun.
                    125 dugumunun uzakligini hesaplayacak olursak.
                    kok = 100 <125  kok = kok->sag  i++
                    kok = 120 <125  kok=kok->sag  i++
                    kok = 130>125    kok = kok->sol i++     kok->veri == a->veri   whileden cikilir.
                    i = 3    retrun 3 olur.
*/

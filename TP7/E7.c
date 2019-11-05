#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>
#include <pcf8591.h>  //librería del ADC para WiringPi

#define Address 0x48  //Dirección del puerto i2c
#define BASE 64	      //Cualquier numero superior a 64
#define A0 BASE+0     //Canales analógicos
#define A1 BASE+1
#define A2 BASE+2
#define A3 BASE+3

int main(void){
	int val;
	if (wiringPiSetup () == -1) exit (1);	
	pcf8591Setup(BASE, Address);				//configura ADC
	while(1)
	{
		val = analogRead(A0);				//lee primer canal
		printf("Potenciometro: %dmv\n",val*3300/255);
		val = analogRead(A1);				//lee segundo canal
		printf("Fotoresistor: %dmv\n",val*3300/255);
		val = analogRead(A2);				//lee tercer canal
		printf("Termistor: %dmv\n\n",val*3300/255);
		delay(1000);
		
	}
	return 0;
}


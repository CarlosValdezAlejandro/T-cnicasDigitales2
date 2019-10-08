//Programa para poner en alto una salida 

#include "EasyPio.h"


void main(void){

//inicializo pioInit para configurar registros
pioInit();

int i=1;

//configuro puertos gpio

pinMode(16, OUTPUT);
pinMode(21, INPUT);
pinMode(20, INPUT);

//Bucle para poner en 1 la salida 16, y salir
//cuando la entrada 21 lea un 1
while(i){

	digitalWrite(16, digitalRead(21));
	i = digitalRead(20);
	
}

//pone en 0  la salida 16
digitalWrite(16, 0);

}

//Programa para poner en alto una salida 
//
// Salida gpio 16, entradas gpio 21 y 20. 20 controla el led, 21 sale del programa


#include "EasyPio.h"


int main(void){

//inicializo pioInit para configurar registros
pioInit();

int i=0;

//configuro puertos gpio

pinMode(23, OUTPUT);
pinMode(24, OUTPUT);
pinMode(25, OUTPUT);
pinMode(12, OUTPUT);

pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(13, INPUT);
pinMode(19, INPUT);
pinMode(17, INPUT);

//Bucle para poner en 1 la salida 16, y salir
//cuando la entrada 21 lea un 1
while(!i){

	digitalWrite(23, digitalRead(5));
	digitalWrite(24, digitalRead(6));
	digitalWrite(25, digitalRead(13));
	digitalWrite(12, digitalRead(19));
	
	i = digitalRead(27);
	
}

//pone en 0  la salida 16
digitalWrite(23, 0);
digitalWrite(24, 0);
digitalWrite(25, 0);
digitalWrite(12, 0);



return 0;

}

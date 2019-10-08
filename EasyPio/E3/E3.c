//Auto fantástico

#include "EasyPio.h"

#define NUM_IN = 1
#define NUM_OUT = 5

void main(void){

//entra
int in[NUM_IN] = {21};
int out[NUM_OUT] = {12, 17, 18, 19, 20};
int i, j, k;

//configuro pines entradas
for(i=0; i <= NUM_IN; i++)
	{
		pinMode(in[i], INPUT);
	}

//configuro pines salidas
for(j=0; j <= NUM_OUT; j++)
	{
		pinMode(out[j], OUTPUT);
	}

//hasta que se oprima un boton
while(!digitalRead(21))
	{
		//hacia un lado
		for(k=0; k <= NUM_OUT; k++ )
		{
			digitalWrite(out[k], 1);
			delayMillis(500);
			digitalWrite(out[k], 0);
		}
		
		//hacia el otro lado
		for(k ; k>=0; k-- )
		{
			digitalWrite(out[k], 0);
			delayMillis(500);
			digitalWrite(out[k],1);
		}
	}

// Prueba para ver si se pueden poner todas las salidas a 0 de una sola vez
digitalWrite(out, 0);

}




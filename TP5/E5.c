//Auto fantástico

#include "EasyPio.h"

#define NUM_IN  1
#define NUM_OUT  8

int main(void){

//entra
int in[NUM_IN] = {17};
int out[NUM_OUT] = {23, 24, 25, 12, 16, 20, 21, 26};
int k, i=0;

pioInit();
//configuro pines entrada
//
pinMode(in[0], INPUT);

//configuro pines salida
pinMode_out(out, NUM_OUT);



//hasta que se oprima un boton
while(!i)
	{
		//hacia un lado
		for(k=0; k < NUM_OUT; k++ )
		{
			digitalWrite(out[k], 1);
			delayMillis(100);
			digitalWrite(out[k], 0);
			
			i=digitalRead(17);
		}
		
		//hacia el otro lado
		for(k=8 ; k>0; k-- )
		{
			digitalWrite(out[k], 1);
			delayMillis(100);
			digitalWrite(out[k], 0);
			i=digitalRead(17);
		}
	}


// Prueba para ver si se pueden poner todas las salidas a 0 de una sola vez
digitalWrite_s(out, NUM_OUT, 0);

return 0;

}




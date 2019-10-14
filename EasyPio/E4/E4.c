// Ejercicio de carrera
//

#include "EasyPio.h"

#define NUM_OUT = 8
#define NUM_IN = 1

void main(void){
	
int out[NUM_OUT] = {9, 11, 0, 5, 6, 13, 19, 26};
int in[NUM_IN] = {21};

int i;

for(i=0; i < NUM_OUT; i++ )
	{
		pinMode(out[i], OUTPUT);

	}

for(i=0; i < NUM_IN; i++ )
	{
		pinMode(in[i], INPUT);
	}

while(!digitalRead(9))
{
	for(i=0; i < NUM_OUT; i++)
		{
			digitalWrite(out[i], 1);
			digitalWrite(out[NUM_OUT - i], 1);
		}
}

digitalWrite(out, 0);

}


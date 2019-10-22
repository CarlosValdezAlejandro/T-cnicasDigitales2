// Ejercicio de carrera
//

#include "EasyPio.h"
//#include <wiringPi.h>

#define NUM_OUT  8
#define NUM_IN  1

int  main(void){

pioInit();
//wiringPiSetup();

//int out[NUM_OUT] = {9, 11, 0, 5, 6, 13, 19, 26};
int in[NUM_IN] = {21};


/*

int i;

//pinMode_out(out, NUM_OUT);


 	for(i=0; i < NUM_OUT; i++ )
	{	
		pinMode(out[i], OUTPUT);

	}

*/	
//noInterrupts();

pinMode(in[0], INPUT);

pinMode(17 , OUTPUT);
pinMode(27 , OUTPUT); 
pinMode(22 , OUTPUT); 
pinMode(10 , OUTPUT); 
pinMode(9  , OUTPUT); 
pinMode(11 , OUTPUT); 
pinMode(0  , OUTPUT); 
pinMode(5  , OUTPUT);
pinMode(6  , OUTPUT);
pinMode(13 , OUTPUT);
pinMode(19 , OUTPUT);
pinMode(26 , OUTPUT);
pinMode(14 , OUTPUT);
pinMode(15 , OUTPUT);
pinMode(18 , OUTPUT);
pinMode(23 , OUTPUT);
pinMode(24 , OUTPUT);
pinMode(25 , OUTPUT);
pinMode(8  , OUTPUT);
pinMode(7  , OUTPUT);
pinMode(1  , OUTPUT);
pinMode(12 , OUTPUT);
pinMode(16 , OUTPUT);
pinMode(20 , OUTPUT);



//digitalWrites(out, NUM_OUT, 0);

delayMillis(1500);

while(!(digitalRead(21)))
//while(1)
{
;	digitalWrite(17, 1);
//	digitalWrite_s(out, NUM_OUT, 1);
/*	for(j=0; j < NUM_OUT;)
		{
			
			digitalWrite(out[j], 1);
			digitalWrite(out[NUM_OUT - j], 1);
			delayMillis(1000);
			digitalWrite(out[j], 0);
			digitalWrite(out[NUM_OUT - j], 0);
			delayMillis(1000);
			j++;
			
			
		}
		*/
}

//digitalWrite_s(out, NUM_OUT, 0);
digitalWrite(17, 0);
//interrupts();

}


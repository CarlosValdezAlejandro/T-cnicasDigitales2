// TP6 con array declarado

#include "EasyPio.h"

#define NUM_OUTS 8
//#define NUM_IN   1

int main(void){

int  i, j;

int outs[NUM_OUTS] = {23, 24, 25, 12, 16, 20, 21, 26};
//int ins[NUM_IN] = {17};

int vector [8][8] = { {1,0,0,0,0,0,0,0},
		      {0,1,0,0,0,0,0,0},
		      {0,0,1,0,0,0,0,0},
		      {0,0,0,1,0,0,0,0},
		      {0,1,0,0,1,0,0,0},
		      {0,0,0,1,0,1,0,0},
		      {0,0,0,0,0,1,1,0},
		      {0,0,0,0,0,0,0,1} };
pioInit();

pinMode_out(outs, NUM_OUTS);
//pinMode_in(ins, NUM_INS);



	for(i=0; i<NUM_OUTS; i++){
		for(j=0; NUM_OUTS > j; j++){
		//	digitalWrite(outs[0], 1);
			digitalWrite(outs[j], vector[i][j]);
		//	k=digitalRead(17);
			
		}
			delayMillis(500);
	}


//digitalWrite_s(outs, NUM_OUTS, 0);

return 0;
}
			


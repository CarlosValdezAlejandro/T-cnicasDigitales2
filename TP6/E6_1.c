// TP6 con array declarado

#include "EasyPio.h"

#define NUM_OUTS 8
#define NUM_IN   2

int main(void){

int outs[NUM_OUTS] = {x, x, x, x, x, x, x, x};
int ins[NUM_IN] = {x, x};

vector [NUM_OUTS][NUM_OUTS] = { {1,0,0,0,0,0,0,1},
			        {0,1,0,0,0,0,1,0},
		      	        {0,0,1,0,0,1,0,0},
			        {0,0,0,1,1,0,0,0},
			        {0,0,0,1,1,0,0,0},
			        {0,0,1,0,0,1,0,0},
			        {0,1,0,0,0,0,1,0},
			        {1,0,0,0,0,0,0,1} };
pioInit();

pinMode_out(outs[], NUM_OUTS);
pinMode_in(ins[], NUM_INS);

while(1){

	for(int i=0; i<NUM_OUTS; i++){
		for(int j; j<NUM_OUTS; j++){
			digitalWrite(outs[j], vector[i][j]);
	}}
}

return 0;
}
			


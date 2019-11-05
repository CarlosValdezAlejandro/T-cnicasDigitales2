//tp uart rppi easypio.h


#include "easypio.h"

#define BAUD 9600
#define MAX_STR_LEN 10

void getStrSerial(char *str){
	int i=0;
	do{
		str[i]=getCharSerial();
	}while((str[i++] != '\r') && (i<MAX_STR_LEN));
	str[i-1]= 0;
}

void putStrSerial(char *str){
	int i=0;
	while(str[i]!=0){
		putCharSerial(str[i++]);
	}
}


int main(void){

char palabra[MAX_STR_LEN];

pioInit();

uartInit(BAUD);

while(1){
	putStrSerial("Ingrese una palabra: \r\n");
	getStrSerial(palabra);
	putStrSerial("Usted ingresó la palabra: ");
	putStrSerial(palabra);
	putStrSerial("\r\n");
}
}







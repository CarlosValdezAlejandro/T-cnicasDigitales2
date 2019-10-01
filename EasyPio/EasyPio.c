#include "EasyPio.h"

#define GPFSEL ((volatile unsigned int *)(gpio + 0))
#define GPSET  ((volatile unsigned int *)(gpio + 7))
#define GPCLR  ((volatile unsigned int *)(gpio + 10))
#define GPLEV  ((volatile unsigned int *)(gpio + 13))
#define INPUT  0
#define OPUTPUT 1

void pinMode(int pin, int function){
	
	int reg = pin/10;
	int offset =(pin%10)*3;
	GPFSEL[reg] &= ~((0b111&~function) <<offset);
	GPFSEL[reg]  =  ((0b111& function) <<offset);
}

void digitalWrite(int pin, int val){

	int reg = pin/32;
	int offset = pin%32;
	
	if (val) GPSET[reg] = 1 << offset;
	else 	 GPCLR[reg] = 1 << offset;
}

int digitalRead(int pin){
	
	int reg = pin/32;
	int offset = pin%32;

	return (GPLEV[reg] >> offset) & 0x00000001;
}

void delayMicros(int micros){
	SYS_TIMER_C1 = SYS_TIMER_CLO + micros; // configura el registro de comparacion
	SYS_TIMER_CSbits.M1 = 1;	       // resetea la bandera
	while (SYS_TIMER_CSbits.M1 == 0);     // espera hasta que se establezca la bandera
}

void delayMillis(int millis){
	delayMicros(millis*1000);   	      // 1000us por ms
}




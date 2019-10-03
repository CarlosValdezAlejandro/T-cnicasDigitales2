#include "EasyPio.h"


void pioInit(void)
{
        int mem_fd;
        void *reg_map;

        //dev/mem es un pseudo controlador para acceder a la memoria en Linux
        mem_fd = open("/dev/mem", O_RDWR|O_SYNC);
        reg_map = mmap(
                        NULL,                   //Direccion en la cual comienza el mapeo local (Null = no importa)
                        BLOCK_SIZE,             //Bloque de memoria mapeado de 4KB
                        PROT_READ|PROT_WRITE,   //Escritura y Lectura habilitado a la memoria mapeada
                        MAP_SHARED,             //Acceso no exclusivo a esta memoria
                        mem_fd,                 //Mapa a /dev/mem
                        GPIO_BASE);             //Desplazamiento a periferico GPIO

        gpio = (volatile unsigned *)reg_map;
        



        //timer
        //

        reg_map = mmap(
                         NULL,             //Address at which to start local mapping (null means don't-care)
                         BLOCK_SIZE,       //Size of mapped memory block
                         PROT_READ|PROT_WRITE,// Enable both reading and writing to the mapped memory
                         MAP_SHARED,       // This program does not have exclusive access to this memory
                         mem_fd,           // Map to /dev/mem
                         SYS_TIMER_BASE);       // Offset to Timer peripheral


        sys_timer = (volatile unsigned *)reg_map;

	close(mem_fd);

}


// Funciones de GPIO



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


//Funciones de Tiempo


void delayMicros(int micros){
	SYS_TIMER_C1 = SYS_TIMER_CLO + micros; // sasconfigura el registro de comparacion
	SYS_TIMER_CSbits.M1 = 1;	       // resetea la bandera
	while (SYS_TIMER_CSbits.M1 == 0);     // espera hasta que se establezca la bandera
}

void delayMillis(int millis){
	delayMicros(millis*1000);   	      // 1000us por ms
}



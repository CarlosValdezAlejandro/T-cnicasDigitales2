#ifndef EASYPIO_H
#define EASYPIO_H


#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BCM2835_PERI_BASE	0x20000000
#define GPIO_BASE		(BCM2835_PERI_BASE + 0x200000) //base de registro de gpio, se realiza un offset de memoria a la base de regitro principal

volatile unsigned int		*gpio; //puntero a la base del gpio

#define GPLEVO			(*(volatile unsigned int *)(gpio +13))
#define BLOCK_SIZE		(4*1024) //tamaño de memoria

// Registro para manejo de tiempos delay
#define SYS_TIMER_BASE		(BCM2835_PERI_BASE + 0x3000);
#define ARM_TIMER_BASE		(BCM2835_PERI_BASE + 0xB000);

volatile unsigned int *sys_timer;

//Funcion que realiza el mapeo de memoria fisica en Linux para los puertos gpio
//
void pioInit()
{
	int mem_fd;
	void *reg_map;

	//dev/mem es un pseudo controlador para acceder a la memoria en Linux
	mem_fd = open("/dev/mem", O_RDWR|O_SYNC);
	reg_map = mmap(
			NULL,			//Direccion en la cual comienza el mapeo local (Null = no importa)
			BLOCK_SIZE,		//Bloque de memoria mapeado de 4KB
			PROT_READ|PROT_WRITE,	//Escritura y Lectura habilitado a la memoria mapeada
			MAP_SHARED,		//Acceso no exclusivo a esta memoria
			mem_fd,			//Mapa a /dev/mem
			GPIO_BASE);		//Desplazamiento a periferico GPIO

	gpio = (volatile unsigned *)reg_map;
	close(mem_fd);



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

}


#endif

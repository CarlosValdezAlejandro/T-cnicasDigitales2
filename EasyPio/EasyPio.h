#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>

#define BCM2835_PERI_BASE	0x20000000
#define GPIO_BASE		(BCM2835_PERI_BASE + 0x200000)

volatile unsigned int		*gpio; //puntero a la base del gpio

#define GPLEVO			(*(volatile unsigned int *)(gpio +13))
#define BLOCK_SIZE		(4*1024)

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

}

#ifndef EASYPIO_H
#define EASYPIO_H


#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>

#define BCM2835_PERI_BASE	0x20000000
#define GPIO_BASE		(BCM2835_PERI_BASE + 0x200000) //base de registro de gpio, se realiza un offset de memoria a la base de regitro principal

volatile unsigned int		*gpio; //puntero a la base del gpio

#define GPLEVO			(*(volatile unsigned int *)(gpio +13))
#define BLOCK_SIZE		(4*1024) //tamaño de memoria


#define GPFSEL ((volatile unsigned int *)(gpio + 0))
#define GPSET  ((volatile unsigned int *)(gpio + 7))
#define GPCLR  ((volatile unsigned int *)(gpio + 10))
#define GPLEV  ((volatile unsigned int *)(gpio + 13))
#define INPUT   0
#define OUTPUT  1



// Registro para manejo de tiempos delay
#define SYS_TIMER_BASE		(BCM2835_PERI_BASE + 0x3000)
#define ARM_TIMER_BASE		(BCM2835_PERI_BASE + 0xB000)

volatile unsigned int		 *sys_timer;


typedef struct
{
	unsigned M0	:1;
	unsigned M1 	:1;
	unsigned M2 	:1;
	unsigned M3 	:1;
	unsigned 	:28;
}sys_timer_csbits;

#define SYS_TIMER_CSbits (*(volatile sys_timer_csbits*) (sys_timer + 0))
#define SYS_TIMER_CS 	(* (volatile unsigned int*)(sys_timer + 0))

#define SYS_TIMER_CLO   (* (volatile unsigned int*)(sys_timer + 1))
#define SYS_TIMER_CHI   (* (volatile unsigned int*)(sys_timer + 2))
#define SYS_TIMER_C0	(* (volatile unsigned int*)(sys_timer + 3))
#define SYS_TIMER_C1	(* (volatile unsigned int*)(sys_timer + 4))
#define SYS_TIMER_C3	(* (volatile unsigned int*)(sys_timer + 6))




//Funcion que realiza el mapeo de memoria fisica en Linux para los puertos gpio
//
void pioInit(void);
void pinMode(int, int );
void digitalWrite(int, int );
int digitalRead(int);
void delayMicros(int);
void delayMillis(int);
void pinMode_in(int [], int);
void pinMode_out(int [], int);
void digitalWrite_s (int [],int, int);

#endif

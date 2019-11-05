#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wiringPi.h>
#include <wiringSerial.h>

#define MAX_CHAR 2

void receiveData(int);
void sendData(int);

int main(){
	int op;
	int file_description = serialOpen("/dev/ttyS0", 115200);
	printf("File description: %d \n", file_description);
	serialFlush(file_description);
	printf("Serial data avail: %d\n\n", serialDataAvail);
	
	
	do{
		
		printf("\nMENU\nQue desea hacer?\n1- Recibir datos.\n2- Enviar datos.\n3- Salir.\nOpcion: ");
		
		scanf("%d", &op);
		
		printf("\n");

		switch(op){
			case 1:
				receiveData(file_description);
				break;
			case 2:
				sendData(file_description);
				break;
			case 3:
				system("clear");
				break;
			default:
				printf("Opcion incorrecta.\n");
		}

	}while(op!=3);
	


	serialClose(file_description);
	return 0;
}

void receiveData(int file_description){
	int b=0;
	system("clear");
	printf("Recibiendo informacion: ");
	for(b=0; b<MAX_CHAR; b++){
		printf("%c", serialGetchar(file_description));
	}	
	printf("\nFin de la comunicacion.\n\n");
}


void sendData(int file_description){
	char a[MAX_CHAR];
	system("clear");
	printf("Enviar informacion\n");
	printf("Ingrese la palabra a transmitir (Maximo %d caracteres): ", MAX_CHAR);
	scanf("%s", a);
		
	serialFlush(file_description);
	for(int i=0; i< MAX_CHAR; i++){
		serialPutchar(file_description, a[in]);
	}
}


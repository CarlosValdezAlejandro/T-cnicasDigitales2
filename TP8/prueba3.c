#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>


#include <wiringPi.h>
#include <wiringSerial.h>

#define TAM 10

void rxData(int);
void txData(int);

int main()
{
	int fd;
	int op;

	fd = serialOpen("/dev/ttyAMA0", 115200);

	if(wiringPiSetup () == -1)
	{
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror (errno));
		return 1;
	}



do{
	printf("\nMenu \n Que desea hacer?:\n1- Recibir datos. \n2- Enviar datos.\n3- Salir.\nOpcion: ");

	scanf("%d", &op);

	printf("\n");
	switch(op){
		case 1:
			rxData(fd);
			break;
		case 2:
			txData(fd);
			break;
		case 3:
			system("clear");
			break;
		default:
			printf("Opcion incorrecta.\n");
	}
}while(op!=3);

serialClose(fd);
return 0;

}

void txData(int fd){
	char palabra[TAM];

	system("clear");
	printf("\n Ingrese una palabra a enviar: ");
	scanf("%s", palabra);
	fflush(stdout);
	serialPuts(fd, palabra);
	
//	delay(100);
}


void rxData(int fd){
		
		system("clear");
		printf("Entrada: ");
		for(int a=0; a < TAM; a++)
		{
		printf("%c", serialGetchar(fd));
		}
	//	fflush (stdout);
	}



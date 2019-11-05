#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	int i=0;
	char clave1 [6] = "68568";
	char *clave2 ;
	

	do
	{

		clave2= getpass ("Ingrese la clave de 5 digitos: ");
		if (strcmp (clave1,clave2) == 0)
		{
			printf ("\nBienvenido al sistema:\n\n");
			getchar();
			i=3;
		}
		else
		{
			printf ("\nLa contraseÃ±a ingresada no es correcta.\n\n");
			i++;
			getchar();
			system ("clear");
		}
	}
	while (i < 3);
	system ("clear");
	printf ("Programa finalizado.\n");
	return 0;
}


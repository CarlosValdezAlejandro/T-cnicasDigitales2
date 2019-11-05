#include <stdio.h>

extern int mate(int a, int b, int c);

int main(void)
{
	int a, b, c, d;

	printf ("\nIngrese un numero: ");
	scanf("%d", &a);
	printf("\nIngrese otro numero: ");
	scanf("%d", &b);
	printf("\nIngrese operacion:\n1-Suma.\n2-Resta.\n3-AND.\n4-OR.\n\nOpcion:");
	scanf("%d", &c);

	d = mate(a, b, c);
	
	printf("\nEl resultado es: %d\n\n", d);

	return d;

}


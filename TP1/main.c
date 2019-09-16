// Archivo de prueba .c
#include<stdio.h>
   extern int suma(int a, int b);
   int main(void)
   {
     int a = 71;
     int b = 29;
     int c=0;
    
    //llamamos a la funcion suma que hace a=r0, b=r1, variable aux=r2
    //r2 se guarda en r0, y r0 es el valor que retorna a 'suma'
     c = suma(a,b);
 
     printf("\nla suma es: %d \n",c);

     return 0;
   }

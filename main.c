// Archivo de prueba .c
#include<stdio.h>
   extern int suma(int a, int b);
   int main(void)
   {
     int a = 71;
     int b = 29;
     int c=0;

     c = suma(a,b);
 
     printf("\nla suma es: %d \n",c);

     return 0;
   }

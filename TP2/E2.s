//Ejercicio 2, en el cual implementamos un "delay" con un while


.text
.arm
.global delay

delay:
	cmp   r0, #0       //comparo si el argumento de la función es igual a 0
	beq end_while      //si es igual salta a la etiqueta end_while
	sub r0, r0, #1     //si no es igual incrementa en 1 el valor r0;
	b delay		   //salto a etiqueta delay
end_while:                    
	mov   pc, lr       //retorna al programa principal


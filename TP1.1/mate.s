.text
.arm
.global mate

mate:
	cmp r2,#1
	addeq r0, r0, r1
	beq SALIR

	cmp r2, #2
	subeq r0, r0, r1
	beq SALIR

	cmp r2, #3
	andeq r0, r0, r1
	beq SALIR

	cmp r2, #4
	orreq r0, r0, r1
	
	SALIR:
		mov pc, lr	


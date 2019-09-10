#Construcción de Makefile para ejemplo suma

CC = gcc
AS =as
LD = ld

OBJETS = main.o suma.o

CFLAGS  = -Wall -g -c
ASFLAGS = -g
LDFLAGS = -g

suma.elf: $(OBJETS)
	$(CC) $(LDFLAGS) $(OBJETS) -o suma.elf

suma.o: suma.s
	$(AS) $(ASFLAGS) suma.s -o suma.o

main.o: main.c
	$(CC) $(CFLAGS) main.c

clean: 
	rm *.o *.elf



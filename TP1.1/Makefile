AS = as
LD = ld
CC = gcc

OBJECTS = main.o mate.o

ASFLAGS = -g
LDFLAGS = -g
CFLAGS = -Wall -g -c

mate.elf: $(OBJECTS)
		$(CC) $(LDFLAGS) $(OBJECTS) -o mate.elf

mate.o: mate.s
		$(AS) $(ASFLAGS) mate.s -o mate.o

main.o: main.c
		$(CC) $(CFLAGS)  main.c

clean:
		rm *.o *.elf


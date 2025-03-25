CC=gcc
CFLAGS=-Wall -I.

p: arch.o
	$(CC) -o p arch.o
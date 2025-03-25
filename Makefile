CC=gcc
CFLAGS=-Wextra -Wall

arch: main.c arch.c arch.h
	$(CC) $(CFLAGS) -o arch main.c arch.c arch.h

clean:
	rm arch
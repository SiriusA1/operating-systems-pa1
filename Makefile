CC=gcc
CFLAGS=-Wall

all: syscall
syscall: syscall.o
syscall.o: syscall.c

clean:
	rm -f syscall syscall.o
run: syscall
	./syscall

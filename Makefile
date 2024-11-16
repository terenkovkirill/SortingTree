CC=g++
CFLAGS=-c -Wall

main.exe: main.o BinTree.o
	$(CC) main.o BinTree.o -o main.exe

main.o: main.cpp Makefile
	$(CC) $(CFLAGS) main.cpp

BinTree.o: BinTree.cpp Makefile
	$(CC) $(CFLAGS) BinTree.cpp

.PHONY: run
run:
	./main.exe



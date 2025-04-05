CC = g++
CFLAGS = -c -Wall -g
LDFLAGS = -g

main.exe: main.o BinTree.o
	$(CC) main.o BinTree.o -o main.exe

main.o: main.cpp BinTree.h Makefile
	$(CC) $(CFLAGS) main.cpp

BinTree.o: BinTree.cpp BinTree.h Makefile
	$(CC) $(CFLAGS) BinTree.cpp

.PHONY: run clean

run:
	./main.exe

clean:
	rm -f *.o main.exe


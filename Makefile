CC = g++
CFLAGS = -Wall -fsanitize=address -g
LDFLAGS = -fsanitize=address -g
DOT = dot
DOTFLAGS = -Tpng

.PHONY: all
all: clean_before_built main.exe

clean_before_built:
	@$(MAKE) clean

main.exe: main.o BinTree.o
	$(CC) main.o BinTree.o $(LDFLAGS) -o main.exe

main.o: main.cpp BinTree.h Makefile
	$(CC) $(CFLAGS) -c main.cpp

BinTree.o: BinTree.cpp BinTree.h Makefile
	$(CC) $(CFLAGS) -c BinTree.cpp


.PHONY: run clean 

run:
	./main.exe && $(DOT) $(DOTFLAGS) BTree.dot -o BTree.png

clean:
	rm -f *.o main.exe BTree.png BTree.dot


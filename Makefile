# General variables
CC=g++
CFLAGS=-Wall
INCLUDE=./include/
SRC=./src/
EXE=exe

# targets
avl:
	$(CC) -o avl.o -I$(INCLUDE) -c $(SRC)functions.cpp

test: avl
	$(CC) -o $(EXE) $(CFLAGS) -I$(INCLUDE) test/main.cpp avl.o
	./exe

clean:
	rm *.o


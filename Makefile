CC=g++
LD=ld

LDFLAGS=-lpng
CXFLAGS=-O3 -std=c++11

OBJ=bin/bitmap.o bin/main.o
BIN="\$bin"

all: $(OBJ)

$(BIN): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(BIN)

bin/main.o: src/main.cpp src/main.hpp
	$(CC) $(CXFLAGS) -c src/main.cpp -o $@

bin/bitmap.o: src/bitmap.cpp src/bitmap.h
	$(CC) $(CXFLAGS) -c src/bitmap.cpp -o $@

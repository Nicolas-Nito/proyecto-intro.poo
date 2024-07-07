CC = g++

CFLAGS = -Wall -std=c++11 

OBJ = main.o

RES = main

($RES): $(OBJ)
	$(CC) $(CFLAGS) -o $(RES) $(OBJ)

main.o: main.cpp Empleado.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	rm -f $(OBJ) $(RES)
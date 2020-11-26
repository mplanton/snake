# Makefile for the snake game

all: main

main: main.o Coord.o Thing.o Random.o Map.o Snake.o
	g++ -g -Wall -o main main.o Coord.o Thing.o Random.o Map.o Snake.o

main.o: main.cpp Coord.h Thing.h Random.h Map.h Food.h Border.h Body.h Snake.h
	g++ -g -Wall -c main.cpp

Coord.o: Coord.cpp Coord.h
	g++ -g -Wall -c Coord.cpp

Thing.o: Thing.cpp Thing.h
	g++ -g -Wall -c Thing.cpp

Random.o: Random.cpp Random.h
	g++ -g -Wall -c Random.cpp

Map.o: Map.cpp Map.h
	g++ -g -Wall -c Map.cpp

Snake.o: Snake.cpp Snake.h
	g++ -g -Wall -c Snake.cpp

clean:
	rm -f main *.o *.h.gch

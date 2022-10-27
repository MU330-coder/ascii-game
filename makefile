CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lncurses

all: 	game

game:   main.o   game.o

	$(CC) $(CFLAGS) main.o game.o -o game $(LIB)

main.o: main.cpp

	$(CC) $(CFLAGS) -c main.cpp

chip8.o:   game.cpp 	game.h

	$(CC) $(CFLAGS) -c game.cpp

lint:

	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir --root=. *
	
clean:

	rm *.o game

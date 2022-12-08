CC = g++
CFLAGS = --std=c++14 -w -g 
LIB = -lncurses

all: 	game

game:   main.o   game.o enemy.o  player.o

	$(CC) $(CFLAGS) main.o game.o enemy.o player.o -o game $(LIB)

main.o: main.cpp

	$(CC) $(CFLAGS) -c main.cpp

game.o:   game.cpp 	game.hpp

	$(CC) $(CFLAGS) -c game.cpp

enemy.o:  enemy.cpp  enemy.hpp

	$(CC) $(CFLAGS) -c enemy.cpp

player.o:  player.cpp  player.hpp

	$(CC) $(CFLAGS) -c player.cpp

lint:

	cpplint --filter=-runtime/references,-build/c++11,-build/include_subdir --root=. *
	
clean:

	rm *.o game

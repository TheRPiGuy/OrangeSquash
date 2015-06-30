CC=g++
BIN=OrangeSquash
OBJS=player.o main.o
FLAGS=-Wall -Werror -c -g --std=c++11
LIBS=-lpthread

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -g $(OBJS) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

player.o: player/player.h player/player.cpp
	$(CC) $(FLAGS) player/player.cpp

clean:
	rm -rf $(OBJS) $(BIN)

sweep:
	rm -rf $(OBJS)

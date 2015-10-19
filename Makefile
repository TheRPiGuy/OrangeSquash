CC=g++
BIN=OrangeSquash
OBJS=playlist.o request.o bucket.o song.o player.o main.o
FLAGS=-Wall -Werror -c -g --std=c++11
LIBS=-lpthread

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -g $(OBJS) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

player.o: player/player.hpp player/player.cpp
	$(CC) $(FLAGS) player/player.cpp

song.o: song/song.hpp song/song.cpp
	$(CC) $(FLAGS) song/song.cpp

bucket.o: bucket/bucket.hpp bucket/bucket.cpp
	$(CC) $(FLAGS) bucket/bucket.cpp

request.o: request/request.hpp request/request.cpp
	$(CC) $(FLAGS) request/request.cpp

playlist.o: playlist/playlist.hpp playlist/playlist.cpp
	$(CC) $(FLAGS) playlist/playlist.cpp

clean:
	rm -rf $(OBJS) $(BIN)

sweep:
	rm -rf $(OBJS)

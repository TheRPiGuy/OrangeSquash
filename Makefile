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

player.o: player/player.h player/player.cpp
	$(CC) $(FLAGS) player/player.cpp

song.o: song/song.h song/song.cpp
	$(CC) $(FLAGS) song/song.cpp

bucket.o: bucket/bucket.h bucket/bucket.cpp
	$(CC) $(FLAGS) bucket/bucket.cpp

request.o: request/request.h request/request.cpp
	$(CC) $(FLAGS) request/request.cpp

playlist.o: playlist/playlist.h playlist/playlist.cpp
	$(CC) $(FLAGS) playlist/playlist.cpp

clean:
	rm -rf $(OBJS) $(BIN)

sweep:
	rm -rf $(OBJS)

CC=g++
BIN=OrangeSquash
OBJS=downloader.o playlist.o request.o bucket.o song.o player.o main.o
FLAGS=-Wall -Werror -c -g --std=c++11
LIBS=-lpthread

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -g $(OBJS) -o $(BIN) $(LIBS)

main.o: src/main.cpp
	$(CC) $(FLAGS) src/main.cpp

player.o: src/player/player.hpp src/player/player.cpp
	$(CC) $(FLAGS) src/player/player.cpp

song.o: src/song/song.hpp src/song/song.cpp
	$(CC) $(FLAGS) src/song/song.cpp

bucket.o: src/bucket/bucket.hpp src/bucket/bucket.cpp
	$(CC) $(FLAGS) src/bucket/bucket.cpp

request.o: src/request/request.hpp src/request/request.cpp
	$(CC) $(FLAGS) src/request/request.cpp

playlist.o: src/playlist/playlist.hpp src/playlist/playlist.cpp
	$(CC) $(FLAGS) src/playlist/playlist.cpp

downloader.o: src/downloader/downloader.hpp src/downloader/downloader.cpp
	$(CC) $(FLAGS) src/downloader/downloader.cpp

clean:
	rm -rf $(OBJS) $(BIN)

sweep:
	rm -rf $(OBJS)

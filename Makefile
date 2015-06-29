CC=g++
BIN=OrangeSquash
OBJS=main.o
FLAGS=-Wall -Werror -c -g --std=c++11
LIBS=

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -g $(OBJS) -o $(BIN) $(LIBS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

clean:
	rm -rf $(OBJS) $(BIN)

sweep:
	rm -rf $(OBJS)

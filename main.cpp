#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include "player/player.h"

bool playing;

int main()
{
	system("mkfifo /tmp/OrangeFifo");

	setPath("/usr/bin/mplayer", "-slave -really-quiet -input file=/tmp/OrangeFifo"); 

	playing = true;

	std::thread player (play, "~/Music/Panda.Eyes.and.Terminite_High.Score.mp3");

	while(playing)
	{
		std::cout << "Command" << std::endl;
		std::cout << "p = toggle pause, q = kill player" << std::endl;
		char in;
		std::cout << ">>";
		std::cin >> in;
		switch(in)
		{
			case 'p':
			case 'P':
				pausePlayer();
				break;

			case 'q':
			case 'Q':
				killPlayer();
				playing = false;
				break;

			default:
				std::cout << "Invalid command" << std::endl;
				break;
		}
	}

	player.join();
	
	return 0;
}

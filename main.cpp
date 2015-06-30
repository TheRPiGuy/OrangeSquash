#include <iostream>
#include <thread>
#include "player/player.h"

void player();
void control();

int main()
{
	system("mkfifo /tmp/OrangeFifo");

	setPath("/usr/bin/mplayer", "-really-quiet -slave -input file=/tmp/OrangeFifo"); 

	std::thread first (play, "~/Pizza_Rolls.mp3");
	std::thread second (control);

	second.join();
	first.join();
	
	return 0;
}

void control()
{
	bool yes = true;
	while(yes)
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
				yes = false;
				break;

			default:
				std::cout << "Invalid command" << std::endl;
				break;
		}
	}
}

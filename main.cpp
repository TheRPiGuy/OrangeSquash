#include <iostream>
#include <future>
#include "player/player.h"

bool playing;

int main()
{
	system("mkfifo /tmp/OrangeFifo");

	Player go("/usr/bin/mplayer", "-slave -really-quiet", "/tmp/OrangeFifo");

	playing = true;

	go.play("~/Music/Panda.Eyes.and.Terminite_High.Score.mp3");	

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
				go.pausePlayer();
				break;

			case 'q':
			case 'Q':
				go.killPlayer();
				playing = false;
				break;

			default:
				std::cout << "Invalid command" << std::endl;
				break;
		}
	}
	
	return 0;
}

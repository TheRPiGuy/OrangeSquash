#include <iostream>
#include <chrono>
#include <thread>
#include "player/player.h"

bool playing;

int main()
{
	system("mkfifo /tmp/OrangeFifo");

	Player go("/usr/bin/mplayer", "-slave -really-quiet", "/tmp/OrangeFifo");

	go.play("~/Music/Terminite.and.Panda.Eyes_High.Score.mp3");

	std::cout << "Killing mplayer after 30 seconds" << std::endl;

	for(int i = 0; i < 30; i++)
	{
		std::cout << i << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	
	std::cout << "Killing player\n Exiting program" << std::endl;

	go.killPlayer();
	
	return 0;
}

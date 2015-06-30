#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>

class Player
{
	private:
		std::string path;
		std::string flags;
		std::string fifoPath;
	public:
		Player(std::string pth, std::string flgs, std::string fifoPth); 
		void play(std::string file);
		void pausePlayer();
		void killPlayer();
};

#endif

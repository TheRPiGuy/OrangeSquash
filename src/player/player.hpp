#ifndef PLAYER_H_
#define PLAYER_H_

#include "../song/song.hpp"
#include <string>

class Player
{
	private:
		std::string timeout = "547";
		std::string playerPath = "/usr/bin/mplayer";
		std::string flags = "-fs -af volnorm -ass -endpos";
		std::string filePath;
		std::string songName;
	public:
		Player(Song s);
		void play();
		void stop();	
};

#endif

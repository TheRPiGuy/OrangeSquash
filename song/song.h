#ifndef SONG_H_
#define SONG_H_

#include<string>

class Song
{
	private:
		std::string path;
		std::string name;
		std::string uid;
	public:
		Song(std::string p, std::string n, std::string u);
		std::string getPath();
		std::string getName();
		std::string getUid();
};

#endif

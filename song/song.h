#ifndef SONG_H_
#define SONG_H_

#include<string>

class Song
{
	private:
		std::string path;
		int length;
		std::string uid;
	public:
		Song(std::string p, int l, std::string u);
		std::string getPath();
		int getLength();
		std::string getUid();
};

#endif

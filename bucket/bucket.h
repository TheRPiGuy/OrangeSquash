#ifndef BUCKET_H_
#define BUCKET_H_

#include <string>
#include "../song/song.h"

class Bucket
{
	private:
		std::vector <Song> songs;
		std::vector <std::string> users;
		int count;
	public:
		Bucket();
		Song getNextSong();
		void addSong();
		bool checkUser();1
};

#endif

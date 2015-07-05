#ifndef BUCKET_H_
#define BUCKET_H_

#include <string>
#include <deque>
#include "../song/song.h"

class Bucket
{
	private:
		std::deque <Song> songs;
		std::deque <std::string> users;
		int count;
	public:
		Bucket();
		Song getNextSong();
		void addSong(Song s);
		bool checkUser(std::string u);
		bool empty();
};

#endif

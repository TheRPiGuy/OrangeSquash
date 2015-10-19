#ifndef BUCKET_H_
#define BUCKET_H_

#include <string>
#include <deque>
#include "../song/song.hpp"

class Bucket
{
	private:
		std::deque <Song> songs;
	public:
		Bucket(){}; //Buckets are created as completly empty
		Song getNextSong();
		void addSong(Song s);
		bool checkUser(std::string u);
		bool empty();
};

#endif

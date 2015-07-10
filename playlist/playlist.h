#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <deque>
#include <string>
#include "../bucket/bucket.h"

class Playlist
{
	private:
		int size;
		std::deque<Bucket> bucky;
	public:
		Playlist(){size = 0;}
		bool queueSong(Song s);
		Song getSong();
		int getSize();		
};

#endif

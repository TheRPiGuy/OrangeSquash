#include "playlist.h"

bool Playlist::queueSong(Song s)
{
	if(bucky.size() == 0)
	{	
		//If bucket is empty, craete a new empty bucket and push to bucky
		Bucket a;
		bucky.push_back(a);
	}
	std::string uid = s.getUid();
	std::deque<Bucket>::iterator it = bucky.begin();	
	
	//Check within each bucket whether a song exists posted by the same Uid
	while(it->checkUser(uid))
	{
		if(it == (bucky.end()-1))
		{
			//If the iterator is at the last bucket, create anew empty bucet and push to bucky
			Bucket a;
			bucky.push_back(a);
		}
		it++;
	}
	//Dereference iterator as bucket object and add song
	size++;
	it->addSong(s);
	return true;
}

Song Playlist::getSong()
{
	if(bucky.size() < 1)
	{
		//Deque is currently void of all objects
		//Need to throw exception (Empty queue)
		std::string e = "Deque empty: No initialised objects";
		throw e;
	}
	else if((bucky.size() == 1) & (bucky.front().empty()))
	{
		//No songs queued but deque is correctly initialiised with objects
		//Need to throw exception (Empty queue)
		std::string e = "Nothing to play";
		throw e;
	}
	else
	{
		if((bucky.size() > 1) & (bucky.front().empty()))
		{	
			//Cleanup of fully emptied buckets with songs waiting in the next bucket
			bucky.pop_front();
		}
		size--;
		return bucky.front().getNextSong();
	}
}

int Playlist::getSize()
{
	return size;
}

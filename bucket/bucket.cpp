#include "bucket.h"
#include <iostream>

Song Bucket::getNextSong()
{
	Song val = songs.front();
	songs.pop_front();
	return val;
}

void Bucket::addSong(Song s)
{
	songs.push_back(s);
}

bool Bucket::checkUser(std::string u)
{
	if(empty())
	{
		return false;
	}
	else
	{
		bool exists = false;
		for(auto it: songs)
		{
			if(it.getUid() == u)
			{
				exists = true;
				break;
			}
		}
		return exists;
	}
}

bool Bucket::empty()
{
	return (songs.size() == 0);
}

void Bucket::dump()
{
	for(auto s: songs)
	{
		std::cout << s.getPath() << " - " << s.getUid() << std::endl;
	}
}

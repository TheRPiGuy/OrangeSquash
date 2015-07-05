#include "bucket.h"

Bucket::Bucket()
{
	count = 0;
}

Song Bucket::getNextSong()
{
	count--;
	users.pop_front();
	Song val = songs.front();
	songs.pop_front();
	return val;
}

void Bucket::addSong(Song s)
{
	users.push_back(s.getUid());
	songs.push_back(s);
	count++;
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
		std::deque <Song>::iterator it = songs.begin();
		while(it != songs.end())
		{
			if((*it).getUid() == u)
			{
				exists = true;
				break;
			}
			it++;
		}
		return exists;
	}
}

bool Bucket::empty()
{
	return (count == 0);
}

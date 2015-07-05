#include <iostream>
#include <chrono>
#include <thread>
#include <deque>
#include <string>
#include "bucket/bucket.h"
#include "user/user.h"
#include "song/song.h"

static std::deque<Bucket> bucky;

void playerHandler();
void bucketHandler(Song s);
void print(std::string s);
void bucketView();

int main()
{
	User jai("XKCD_", "password", "salty");
	User alex("Kirby", "password", "salty");

	Song hotdog("Music/hodoggu.mp3", 100, jai.getUid());
	Song marblesoda("Music/marblesoda.mp3", 100, jai.getUid());
	Song pizzarolls("Music/pizzarolls.mp3", 100, jai.getUid());

	Song chiptune("Music/chiptune.mp3", 100, alex.getUid());
	Song rebbBlack("Music/rebbBlack.mp3", 100, alex.getUid());

	bucketHandler(hotdog);
	bucketHandler(marblesoda);
	bucketHandler(pizzarolls);

	bucketHandler(chiptune);
	bucketHandler(rebbBlack);

	//bucketView();

	playerHandler();
	return 0;
}

void playerHandler()
{
	while(true)
	{	
		//4 cases
		//No buckets
		if(bucky.size() < 1)
		{
			print("Nothing to play");
			exit(0);
		}
		//One bucket, empty
		else if((bucky.size() == 1) & (bucky.front().empty()))
		{
			print("Nothing to play");
			exit(0);
		}
		//More than one bucket, first empty
		else if((bucky.size() > 1) & (bucky.front().empty()))
		{
			bucky.pop_front();
		}
		//1 or more non-empty buckets
		else
		{
			Song nowPlaying = bucky.front().getNextSong();
			std::cout << "Playing song: " << nowPlaying.getPath() << std::endl;
			std::cout << "Queued by user: " << nowPlaying.getUid() << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		}
	}
}

void bucketHandler(Song s)
{
	if(bucky.size() == 0)
	{
		//Creating new empty bucket and pushing into list
		Bucket a;
		bucky.push_back(a);
	}
	std::string uid = s.getUid();
	std::deque<Bucket>::iterator it = bucky.begin();	
	
	while(it->checkUser(uid))
	{
		if(it == (bucky.end()-1))
		{
			Bucket a;
			bucky.push_back(a);
		}
		it++;
	}
	
	it->addSong(s);
}

void print(std::string s)
{
	std::cout << s << std::endl;
}

void bucketView()
{
	std::cout << "Number of buckets: " << bucky.size() << std::endl;
	for(auto b: bucky)
	{	
		std::cout << "Begin bucket ###" << std::endl;
		b.dump();
		std::cout << "End bucket ###" << std::endl;
	}
}

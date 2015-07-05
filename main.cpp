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
int main()
{
	print("Intialising program");
	print("Creating main Bucket list");

	print("Creating user objects");
	User jai("XKCD_", "password", "salty");
	User alex("Kirby", "password", "salty");
	print("Done!");


	std::cout << "Creating test songs for user: " << jai.getUser() << std::endl;
	Song hotdog("Music/hodoggu.mp3", 100, jai.getUid());
	Song marblesoda("Music/marblesoda.mp3", 100, jai.getUid());
	Song pizzarolls("Music/pizzarolls.mp3", 100, jai.getUid());
	print("Done!");


	std::cout << "Creating test songs for user: " << alex.getUser() << std::endl;
	Song chiptune("Music/chiptune.mp3", 100, alex.getUid());
	Song rebbBlack("Music/rebbBlack.mp3", 100, alex.getUid());
	print("Done!");

	print("Done craeting objects");
	print("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

	std::cout << "Using bucket handler on songs by user" << jai.getUser() << std::endl;
	bucketHandler(hotdog);
	print("Added song hotdog");
	bucketHandler(marblesoda);
	print("Added song marble soda");
	bucketHandler(pizzarolls);
	print("Added song pizzarolls");
	print("Done!");

	std::cout << "Using bucket handler on songs by user" << jai.getUser() << std::endl;
	bucketHandler(chiptune);
	bucketHandler(rebbBlack);
	return 0;
}

void playerHandler()
{
}

void bucketHandler(Song s)
{
	if(bucky.size() == 0)
	{
		print("Bucket queue is empty");
		print("Creating new bucket and adding to queue");
		Bucket a;
		bucky.push_back(a);
		print("Done!");
	}
	std::string uid = s.getUid();
	std::deque<Bucket>::iterator it = bucky.begin();	
	
	print("Checking if user has already posted into current bucket");
	while((*it).checkUser(uid))
	{
		print("User has!");
		print("Checking if current bucket is last");
		if(it == bucky.end())
		{
			print("It is!");
			print("Creating new empty bucket to add to back of queue");
			Bucket a;
			bucky.push_back(a);
			print("Done");
		}
		print("Iterating to next bcuket");
		it++;
		print("Iterated!");
		print("Checking if user has already posted into current bucket");
	}
	
	std::cout << "Adding song: " << s.getPath() << std::endl;
	
	(*it).addSong(s);
}

void print(std::string s)
{
	std::cout << s << std::endl;
}

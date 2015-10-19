#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "song/song.hpp"
#include "playlist/playlist.hpp"
#include "player/player.hpp"

int main()
{	
	//Create empty bucket deque
	//Start the webserver and begin to receive requests
	//Main flow
	//*Request object -> youtubedl -> song object -> pushed into bucket deque
	//*Pull next song from deque -> play -> terminate after song end or after certain time -> cleanup files
	//Run * processes in parallel
	Song a("/home/jai/Videos/test.mp4", "Test Song", "XKCD_");
	std::cout << "Created song: " << a.getPath() << " " << a.getName() << " " << a.getUid() << std::endl;
	
	Playlist list;
	list.queueSong(a);

	while(true)
	{
		try
		{
			Song b = list.getSong();
			try
			{
				player(b);
			}
			catch(std::string w)
			{
				std::cout << w << std::endl;
			}
		}
		catch(std::string e)
		{
			std::cout << e << std::endl;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}
	return 0;
}

#include <iostream>
#include <string>
#include "song/song.h"
#include "playlist/playlist.h"
#include "player/player.h"

int main()
{	
	//Create empty bucket deque
	//Start the webserver and begin to receive requests
	//Main flow
	//*Request object -> youtubedl -> song object -> pushed into bucket deque
	//*Pull next song from deque -> play -> terminate after song end or after certain time -> cleanup files
	//Run * processes in parallel
	Song a("media/test.mp3", "Test Song", "XKCD_");
	std::cout << "Created song: " << a.getPath() << " " << a.getName() << " " << a.getUid() << std::endl;
	
	Playlist list;
	list.queueSong(a);
	
	while(true)
	{
		try
		{
			Song b = list.getSong();
			player(b);
		}
		catch(std::string e)
		{
			std::cout << e << std::endl;
		}	
	}
	return 0;
}

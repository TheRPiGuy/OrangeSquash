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
	Song a("media/test.mp4", "Test Song", "XKCD_");
	std::cout << "Created song: " << a.getPath() << " " << a.getName() << " " << a.getUid() << std::endl;

	Player playerObj(a);
	playerObj.play();
	
	return 0;
}

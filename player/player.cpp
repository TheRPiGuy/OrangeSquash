#include "player.h"

#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <signal.h>
#include <iostream>
#include <string>


void player(Song s)
{
	// Fork processe of player
	// Use waitpid on the player process to wait fro exit within a while loop that has a timeout
	// If the player exits, the while loop breaks
	// If timeout is reached, the while loop breaks
	// The player process is kill form its pid after the loop exits
	
	std::string time = "30";

	char* timeout = &time[0u];

	pid_t pid_player = fork();
	
	char* path = &s.getPath()[0u];
	
	switch(pid_player)
	{
		case -1: // Error in fork
		{
			std::string message1 = "Uh-Oh! fork() failed.";
			throw message1;
		}
		case 0: // Child process from fork
		{
			// Execute the program
			execl("/usr/bin/mplayer", "-slave", "-input", "file=/tmp/OrangeFifo", path, "-fs", "-really-quiet", "-endpos", timeout, NULL);
			//execl doesn't return unless there's an error	
			std::string message2 = "Uh-Oh! execl() failed!";
			throw message2;
		}
		default: // Parent process from fork
		{
			std::cout << "Now playing: " << s.getName() << std::endl;
			int status = 200;
			while(true)
			{
				pid_t rc = waitpid(pid_player, &status, WNOHANG);
				if (rc < 0)
				{
					std::cerr << "Player has failed" << std::endl;
					exit(1);
				}
				if(status == 0)
				{
					// it's done
        			break;
				}
				sleep(1);
			}
		}
	}		
}

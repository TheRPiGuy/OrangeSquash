#include "player.hpp"

#include <unistd.h>		//fork()
#include <sys/wait.h>	//waitpid()
#include <signal.h>		//program exit signals
#include <thread>		//this::thread::sleepfor
#include <chrono>		//chrono::milliseconds
#include <iostream>
#include <string>

Player::Player(Song s)
{
	filePath = s.getPath();
	songName = s.getName();
}

void Player::play()
{
	// Fork process of player
	// Execute mplayer in the child process with internal mplayer timeout
	// Use waitpid on the player process to wait for exit within a while loo
	
	// Timeout of the player in seconds
	
	pid_t pid_player = fork();
	
	switch(pid_player)
	{
		case -1: // Error in fork
		{
			std::string message1 = "Uh-Oh! fork() failed.\n Check src/player files";
			throw message1;
		}
		case 0: // Child process from fork
		{
			// Execute the program
			execl(playerPath.c_str(), flags.c_str(), timeout.c_str(), filePath.c_str(), NULL);
			//execl doesn't return unless there's an error	
			std::string message2 = "Uh-Oh! execl() failed!\n Check src/player files";
			throw message2;
		}
		default: // Parent process from fork
		{
			std::cout << "Now playing: " << songName << std::endl;
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
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	}		
}

void Player::stop()
{
	//TODO
	;
}

#include "downloader.hpp"

#include <unistd.h>		//fork()
#include <sys/wait.h>	//waitpid()
#include <signal.h>		//program exit signals
#include <thread>		//this::thread::sleepfor
#include <chrono>		//chrono::milliseconds
#include <iostream>
#include <string>


Downloader::Downloader(Request r)
{
	req = &r;
}

void Downloader::objectDump()
{
	std::cout << "Object dump for req:" << std::endl;
	std::cout << "URL: " << req->getUrl() << std::endl;
	std::cout << "UID: " << req->getUid() << std::endl;
}



void Downloader::check()
{
	// Fork process of player
	// Execute mplayer in the child process with internal mplayer timeout
	// Use waitpid on the player process to wait for exit within a while loo
	
	// Timeout of the player in seconds
	
	pid_t pid_downloader = fork();
	
	switch(pid_downloader)
	{
		case -1: // Error in fork
		{
			std::string message1 = "Uh-Oh! fork() failed.\n Check src/player files";
			throw message1;
		}
		case 0: // Child process from fork
		{
			// Execute the program
			execl("youtube-dl", "--get-filename", "-o", "%(title)s.%(ext)s", "--restrict-filenames", req->getUrl().c_str(), NULL);

			//execl doesn't return unless there's an error	
			std::string message2 = "Uh-Oh! execl() failed!\n Check src/player files";
			throw message2;
		}
		default: // Parent process from fork
		{
			std::cout << "Checking request from: " << req->getUid() << std::endl;
			int status = 200;
			while(true)
			{
				pid_t rc = waitpid(pid_downloader, &status, WNOHANG);
				if (rc < 0)
				{
					std::cerr << "Downloader has failed" << std::endl;
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

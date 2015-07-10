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
	//Verify song file exists at specify path
	//Fork two processes
	//*Start mplayer
	//*Thread that sleeps for a specified time and then exits cleanly
	
	//char* program = "/usr/bin/mplayer";

	pid_t pid_player = fork();
	
	char* path = &s.getPath()[0u];
	
	switch(pid_player)
	{
		case -1: // Error
			std::cerr << "Uh-Oh! fork() failed." << std::endl;
			exit(1);

		case 0: // Child process
			execl("/usr/bin/mplayer", "-slave", "-really-quiet", path, NULL); // Execute the program

			std::cerr << "Uh-Oh! execl() failed!" << std::endl; // execl doesn't return unless there's an error
			exit(1);

		default: // Parent process
			std::cout << "Process created with pid " << pid_player <<  std::endl;
        	
			int status;
			int times = 0;
			while (times < 547)
			{
				sleep(1); // sleep 1 second
				if ((waitpid(-1, &status, WNOHANG)) < 0)
				{
					std::cerr << "waitpid" << std::endl;
					exit(1);
				}
				if (WIFEXITED(status))// || WIFSIGNALED(status))
				{
					/* it's done */
        			break;
				}
				times++;
			}
			if (times == 547)
			{
				kill(pid_player, SIGKILL);
			}
	}
	//Exit cleanly
}


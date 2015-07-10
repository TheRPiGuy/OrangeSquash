#include "player.h"

#include <thread>
#include <chrono>
#include <unistd.h>
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

	pid_t pid = fork();
	
	char* path = &s.getPath()[0u];
	
	switch(pid)
	{
		case -1: /* Error */
			std::cerr << "Uh-Oh! fork() failed.\n";
			exit(1);

		case 0: /* Child process */
			execl("/usr/bin/mplayer", "-really-quiet", path, NULL); /* Execute the program */

			std::cerr << "Uh-Oh! execl() failed!"; /* execl doesn't return unless there's an error */
			exit(1);

		default: /* Parent process */
			std::cout << "Process created with pid " << pid << "\n";
        	
			int status;
			while(!WIFEXITED(status))
			{
				waitpid(pid, &status, 0); /* Wait for the process to complete */
			}
			std::cout << "Process exited with " << WEXITSTATUS(status) << "\n";  	
	}
		
	//Once either of these child processes had ended, kill the other
	//Exit cleanly
}


#include "player.h"

std::string path;
std::string flags;

void setPath(std::string p, std::string f)
{
	path = p;
	flags = f;
}

void play(std::string file)
{
	std::string command = path + " " + flags + " " + file;
	char * c_command = &command[0u]; //Hacky conversion to c string 
	system(c_command);
}

void pausePlayer()
{
	system("echo \"pause\" > /tmp/OrangeFifo");
}

void killPlayer()
{
	system("echo \"stop\" > /tmp/OrangeFifo");
}

#include "player.h"

Player::Player(std::string pth, std::string flgs, std::string fifoPth)
{
	path = pth;
	flags = flgs;
	fifoPath = fifoPth;
}

void Player::play(std::string file)
{
	std::string command = path + " " + flags + " -input file=" + fifoPath + " " + file + "&";
	char * c_command = &command[0u]; //Hacky conversion to c string 
	system(c_command);
}

void Player::pausePlayer()
{
	system("echo \"pause\" > /tmp/OrangeFifo");
}

void Player::killPlayer()
{
	system("echo \"quit\" > /tmp/OrangeFifo");
}

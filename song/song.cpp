#include "song.h"

Song::Song(std::string p, std::string n, std::string u)
{
	path = p;
	name = n;
	uid = u;
}

std::string Song::getPath()
{
	return path;
}
	
std::string Song::getName()
{
	return name;
}

std::string Song::getUid()
{
	return uid;
}

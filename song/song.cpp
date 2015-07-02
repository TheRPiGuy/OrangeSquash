#include "song.h"

Song::Song(std::string p, int l, std::string u)
{
	path = p;
	length = l;
	uid = u;
}

std::string Song::getPath()
{
	return path;
}

int Song::getLength()
{
	return length;
}

std::string Song::getUid()
{
	return uid;
}

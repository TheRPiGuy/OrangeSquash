#include "request.hpp"

Request::Request(std::string p, std::string u)
{
	url = p;
	uid = u;
}

std::string Request::getUrl()
{
	return url;
}

std::string Request::getUid()
{
	return uid;
}

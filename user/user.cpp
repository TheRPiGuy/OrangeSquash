#include "user.h"

User::User(std::string u, std::string pwd, std::string slt)
{
	user = u;
	pwdHash = pwd;
	salt = slt;
	//TODO
	//Come up with a way to generate unique user ids form the given info
	uid = u;
}

std::string User::getUser()
{
	return user;
}


std::string User::getPwdHash()
{
	return pwdHash;
}


std::string User::getSalt()
{
	return salt;
}


std::string User::getUid()
{
	return uid;	
}

#include "user.h"

User::User(std::string u, std::string pwd, std::string slt)
{
	user = u;
	pwdHash = pwd;
	salt = slt;
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

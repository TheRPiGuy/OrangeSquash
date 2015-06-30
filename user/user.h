#ifndef USER_H_
#define USER_H_

#include <string>

class User
{
	private:
		std::string user;
		std::string pwdHash;
		std::string salt;
		std::string uid;
	public:
		User(std::string u, std::string pwd, std::string slt);
		std::string getUser();
		std::string getPwdHash();
		std::string getSalt();
		std::string getUid();
};

#endif

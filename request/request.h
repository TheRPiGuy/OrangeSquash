#ifndef REQUEST_H_
#define REQUEST_H_

#include<string>

class Request
{
	private:
		std::string url;
		std::string uid;
	public:
		Request(std::string p, std::string u);
		std::string getUrl();
		std::string getUid();
};

#endif

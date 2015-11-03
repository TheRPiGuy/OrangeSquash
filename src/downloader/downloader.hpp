#ifndef DOWNLOADER_H_
#define DOWNLOADER_H_

#include "../song/song.hpp"
#include "../request/request.hpp"
#include <iostream>
#include <string>

class Downloader
{
	private:
		Request *req;
	public:
		Downloader(Request r);
		void objectDump();
		void check();
};

#endif

#include <iostream>
#include <string>
#include "downloader/downloader.hpp"
#include "request/request.hpp"

int main()
{	
	Request a("https://www.youtube.com/watch?v=pl57hN4EaLU", "Jai");
	Downloader dlObj(a);
	dlObj.check();
	
	return 0;
}

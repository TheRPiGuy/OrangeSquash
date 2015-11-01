#OrangeSquash

##Info

A music server project in C++ that will hopefully be useful.

Uses standard C++ libraries(so-far) and requires mplayer to be installed and accessed at path "/usr/bin/mplayer"

This project is not yet completed, but if you want to try it out, run the Makefile using the make the command and execute the compiled binary using "./OrangeSquash"

During development of this project files will continually be changing and new files added. The main.cpp file contains some semblance to what the final program may contain but may also frequently contain temporary test code.

##Known Issues

mplayer may become a zombie process if forcibly killed
* temporary solution is to have mplayer use its internal timeout function
* mplayer cannot be killed safely from the main program and has to be terminated via keyboard or internal timout

mplayer can still recieve regular keyboard input
* this is needed to stop mplayer if need be (ie banned song)
* relates to issue above

Web front-end development is at a halt
* I dont have a clear idea of how to get requests from the web to the backend
* Could do javascript -> JSON -> JSON parser in C++ but seems insecure/too hacky/unstable
* Also need to find a way to internally serve http requests in C++ 

##TODO

* Finalise a stable player service that uses mplayer
* Finalise and secure the queue system
* Add the youtube-dl system to auto download and add videos to queue
* Terminal print out of current state of entire queue
* Prevent more than one instance of the program being run at the same time
* The entire web front-end side (-_-)

#Tacoma

##Info

A music server project in C++ that will hopefully be useful.

Uses standard C++ libraries, boost libraries and Wt webtoolkit and requires mplayer to be installed and accessed at path "/usr/bin/mplayer" and youtube-dl to be installed.

I have recently made the decision to use Boost libraries for core functions of the project so some completed sections will have to reimplemented using these libraries as it will produce more robust and readable code.

This project is not yet completed.

##TODO

* Reimplemented using the much nicer boost libraries
* Add the youtube-dl service
* Create test mode that verbosely prints the states of the list and the player actions given common and uncommon test cases
* Add a logging system that caches songs and their hash values as JSON objects
* Add a client service for administrators of the music server
* Add the web front end using Wt webtoolkit

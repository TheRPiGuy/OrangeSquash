#Tacoma

#THIS PROJECT IS ABANDONED

This project was aimed as fun exercise in learning C++ to create a useful piece of software.
"This has made a lot of people very angry and is widely regarded a bad move."
But seriously, I haven't had the time, patience nor the experince to write a web application in a very unsuitable languag such as C++.
Therefore I am abandoning this project.
Anyone can feel free to fork it finish it.
I will still be making a proper music server but in a much more sensible fashion.
('-')/


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

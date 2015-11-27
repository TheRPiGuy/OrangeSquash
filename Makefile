all:
	g++ -o Tacoma src/main.cpp -lwthttp -lwt

clean:
	rm -f Tacoma 

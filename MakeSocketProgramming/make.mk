all: server client

server: servermain.o socketutils.o
	g++ -pthread servermain.o socketutils.o -o server

client: clientmain.o socketutils.o
	g++ -pthread clientmain.o socketutils.o -o client

servermain.o: servermain.cpp
	g++ -c servermain.cpp

clientmain.o: clientmain.cpp
	g++ -c clientmain.cpp

socketutils.o: socketutils.cpp socketutils.h
	g++ -c socketutils.cpp

clean:
	rm *.o server client
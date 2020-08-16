#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>
#include<thread>
#include "socketutils.h"
using namespace std;

server s;

void sendTh(int serverSocket)
{
	while(true)
	{
		s.sendsocket(serverSocket);
	}
}

void receive(int serverSocket)
{
	while(true)
	{
		s.recvsocket(serverSocket);
	}
}



int main()
{

	int listening = socket(AF_INET,SOCK_STREAM,0);
	server s;
	
	int serverSocket = s.serverutils(listening);

    //Close the listening socket
	close(listening);

	thread t1(sendTh,serverSocket);
	thread t2(receive,serverSocket);
	t1.join();
	t2.join();

	close(listening);
	return 0;

}


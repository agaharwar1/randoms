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

void sendTh(int clientSocket)
{
	while(true)
	{

		s.sendsocket(clientSocket);
	}

}

void receiveTh(int clientSocket)
{
	while(true)
	{
		s.recvsocket(clientSocket);
	}

}

int main()
{

	
	
	server s;

	int clientSocket = s.clientutils();
	
	thread t1(sendTh,clientSocket);
	thread t2(receiveTh,clientSocket);
	t1.join();
	t2.join();

	close(clientSocket);
	return 0;



}



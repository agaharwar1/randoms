#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>
#include<thread>
using namespace std;

int sock,serverSocket;
char buf[4096];

void sendTh()
{
	while(true)
	{
		string userInput;
		getline(cin,userInput);
		//Sending msg to server
		int sendRes = send(sock,userInput.c_str(),userInput.size()+1,0);
	}
}

void receiveTh()
{
	while(true)
	{
		memset(buf,0,4096);
		recv(sock,buf,4096, 0);
		cout<<"Server:"<<buf<<endl;
	}

}

int main()
{

	// Creation of socket
	sock = socket(AF_INET,SOCK_STREAM,0);

	if (sock == -1)
	{
		cout << "Socket creation failed" <<endl;
		return 1;
	}

	//Creation of structure for the structure we are connected with

	int port = 54000;
	string ipAddress = "127.0.0.1";


	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port=htons(port);
	inet_pton(AF_INET, ipAddress.c_str(),&hint.sin_addr);

	sockaddr_in server;
	socklen_t serverSize = sizeof(server);
	char host[NI_MAXHOST];
	char svc[NI_MAXSERV];

	//int serverSocket = accept(sock, (sockaddr*)&server, &serverSize);

	
	//Connect to the server on the socket
	int connectRes = connect(sock,(sockaddr*)&hint,sizeof(hint));
	if(connectRes == -1)
	{
		return 1;
	}

	thread t1(sendTh);
	thread t2(receiveTh);
	t1.join();
	t2.join();

	close(sock);
	return 0;

}
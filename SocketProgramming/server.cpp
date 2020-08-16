#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>
#include<thread>
using namespace std;

char buf[4096];
int listening,clientSocket;

void sendTh()
{
	while(true)
	{
		string userInput;
		getline(cin,userInput);
		int sendRes = send(clientSocket,userInput.c_str(),userInput.size()+1,0);
	}
}

void receive()
{
	while(true)
	{
		memset(buf,0,4096);
		//wait for msg
		int bytesRecv = recv(clientSocket, buf,4096,0);
		
		if(bytesRecv <= 0)
		{
			break;
		}
		//display msg
		cout<<"\nClient:"<<string(buf,0,bytesRecv)<<endl;
	}
}

int main()
{

	listening = socket(AF_INET,SOCK_STREAM,0);
	if(listening == -1)
	{
		cerr<<"Cant create socket";
		return -1;
	}

	//Binding socket to an IP/port

	sockaddr_in hint;                               //handling internet address
	hint.sin_family = AF_INET;
	hint.sin_port = htons(54000);                   //htons(host to networkshort)is used for maintaining the arrangement of the bytes according to their endianness
	inet_pton(AF_INET,"0.0.0.0",&hint.sin_addr);  

	bind(listening, (sockaddr*)&hint, sizeof(hint));// converts IP addressess from text to binary form

	//Mark the socket for listening

	listen(listening, SOMAXCONN);

	
	//Accepting call

	sockaddr_in client;
	socklen_t clientSize = sizeof(client);
	char host[NI_MAXHOST];
	char svc[NI_MAXSERV];

	clientSocket = accept(listening, (sockaddr*)&client, &clientSize);

	if(clientSocket == -1)
	{
		cerr<<"Cant connect";
		return -3;
	}

	memset(host,0,NI_MAXHOST);       //Sets the first num bytes of the block of memory pointed by ptr to the specified value 
	memset(svc,0,NI_MAXSERV);

	
	int result =getnameinfo((sockaddr*)&client,sizeof(client),host,	NI_MAXHOST,svc,NI_MAXSERV,0);

	if (result)
	{
		cout<< host <<" connected on "<<svc<<"\n";
	}

	else 
	{
		inet_ntop(AF_INET,&client.sin_addr,host,NI_MAXHOST);
		cout<< host <<" connected on "<<ntohs(client.sin_port);
	}

	

    //Close the listening socket
	close(listening);

	thread t1(sendTh);
	thread t2(receive);
	t1.join();
	t2.join();

	close(listening);
	
	return 0;

}
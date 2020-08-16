#include<iostream>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<string.h>
#include "socketutils.h"
using namespace std;

    int server::serverutils(int listening)
    {
        
        sockaddr_in hint;                               //handling internet address
	    hint.sin_family = AF_INET;
    	hint.sin_port = htons(54000);                   //htons(host to networkshort)is used for maintaining the arrangement of the bytes according to their endianness
        inet_pton(AF_INET,"0.0.0.0",&hint.sin_addr);  

        bind(listening, (sockaddr*)&hint, sizeof(hint));// converts IP addressess from text to binary form

		listen(listening, SOMAXCONN);

		sockaddr_in client;
	    socklen_t clientSize = sizeof(client);
        char host[NI_MAXHOST];
    	char svc[NI_MAXSERV];

	    int serverSocket = accept(listening, (sockaddr*)&client, &clientSize);

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
	
		return serverSocket;

    }

	

	

	int server::clientutils()
	{
    
		int clientSocket = socket(AF_INET,SOCK_STREAM,0);
 	    int port = 54000;
		string ipAddress = "127.0.0.1";
    
	    sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port=htons(port);
		inet_pton(AF_INET, ipAddress.c_str(),&hint.sin_addr);
    
  		int connectRes = connect(clientSocket,(sockaddr*)&hint,sizeof(hint));

		if(connectRes == -1)
	{
		return 1;
	}
		return clientSocket;

   }

	void server::sendsocket(int socketToSend)
	{
			string userInput;
			getline(cin,userInput);
			int sendRes = send(socketToSend,userInput.c_str(),userInput.size()+1,0);
	}
	

	void server::recvsocket(int socketToRecv)
	{
		while(true)
		{
			char buf[4096];

			memset(buf,0,4096);
			
			int bytesRecv = recv(socketToRecv, buf,4096,0);

						
			cout<<"\nMsg:"<<string(buf,0,bytesRecv)<<endl;
			
		}

	}


	


	


	

    
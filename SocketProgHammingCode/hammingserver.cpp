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
int c1,c2,c3,c,i;



void receive()
{
	while(true)
	{
		char data[10];
		char recv_data[4096];
		memset(buf,0,4096);
		//wait for msg
		int bytesRecv = recv(clientSocket, buf,4096,0);
		
		
		if(bytesRecv <= 0)
		{
			break;
		}
		//display msg
		cout<<"\nReceived data: "<<string(buf,0,bytesRecv)<<endl;
		data[0]=buf[0];
		data[1]=buf[1];
		data[2]=buf[2];
		data[4]=buf[3];

		data[6]=data[0]^data[2]^data[4];
    	data[5]=data[0]^data[1]^data[4];
   	 	data[3]=data[0]^data[1]^data[2];
 
        cout<<"Encoded data is: "<<data<<"\n";

		int bytesReceived = recv(clientSocket, buf,4096,0);

		recv_data[bytesReceived] = '\0';
             
    	c1=recv_data[6]^recv_data[4]^recv_data[2]^recv_data[0];
        c2=recv_data[5]^recv_data[4]^recv_data[1]^recv_data[0];
        c3=recv_data[3]^recv_data[2]^recv_data[1]^recv_data[0];
        c=c3*4+c2*2+c1 ;

		if(c==0) 
		{
        	cout<<"No errors while transmission of encoded data...";
    	}
    	else
		{
        	cout<<"Error on position "<<c;
        	cout<<"Correct message is: ";
 	    	if(recv_data[7-c]==0)
            	recv_data[7-c]='1';
        	else
            	recv_data[7-c]='0';
        
        	for (i=0;i<7;i++) 
			{
            	cout<<recv_data[i]<<"\n"; 
        	}
         
		}
	}	
	cout<<"\n*Connection stopped from client side\n";
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

	
	thread t2(receive);
	
	t2.join();

	close(listening);
	


	return 0;


}
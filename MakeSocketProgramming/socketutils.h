#ifndef FUNCTIONS_H  // 'Fileguards'  protect message.h file from being include more than one time
#define FUNCTIONS_H 
  
class server {
	
	public:
      
		int serverutils(int listening);
       
		int clientutils();

		void sendsocket(int socketToSend);
       
		void recvsocket(int socketToRecv);

    };

#endif 
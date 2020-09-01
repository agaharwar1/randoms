#include<iostream>
#include<stdio.h>
using namespace std;
int i,n;

int main(int argc,char *argv[])
{
    cout << "You have entered " <<argc<< " arguments:" << "\n"; 

    for(i=0;i<argc;++i)
    {
        cout << argv[i] << "\n";
    }
    
    for(int j=1;j<argc;++j)
    {
        
        const char *command=argv[j];
        FILE *pipe = popen(command,"r");
        int n=pclose(pipe);
        if(n<=512||n>35000)
        {
            cout<<"\nCommand "<<command<<" exists";
        }
        else if(n>512 && n<35000)
        {
            cout<<"\nCommand "<<command<<" does not exist";            
        }        

    }
  
    return 0;

}
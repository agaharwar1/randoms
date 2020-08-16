#include<iostream>
#include<thread>
using namespace std;

void hundred()
{
	for(int i = 0 ; i<=1000000;++i)
	{
		cout<<i<<"\n";
	}
}


void twohundred()
{
	for(int j = 1000001;j<=2000000;++j)
	{
		cout<<j<<"\n";
	}
}


int main()
{
	thread t1(hundred);
	thread t2(twohundred);
	t1.join();
	t2.join();
}

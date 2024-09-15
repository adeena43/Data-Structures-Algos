#include<iostream>
using namespace std;

int fib(int b)
{
	if(b==0)
	{
		return 0;
	}
	if(b==1)
	{
		return 1;
	}
	
	return fib(b-1)+fib(b-2);
}

int main()
{
	int x;
	cout<<"Enter the nth term of fibonacci: ";
	cin>>x;
	cout<<"\n";
	int ans = fib(x);
	cout<< ans;
}

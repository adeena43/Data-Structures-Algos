#include<iostream>
using namespace std;

/*int fact(int n)
{
	if(n==0 || n==1)
	{
		return 1;
	}
	
	return n*fact(n-1);
	
}

}*/

int powerOfTwo(int n)
{
	if(n==0)
	{
		return 1;
	}
	
	return 2*powerOfTwo(n-1);
}

int main()
{
	int ans;
	ans = powerOfTwo(10);
	cout<<ans;
	return 0;
}

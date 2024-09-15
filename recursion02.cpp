//printing backwards counting
#include<iostream>
using namespace std;

int print(int n)
{
	if(n==1)
	{
		cout<< 1;
		return 0;
	}
	
	//cout<<n<<"\t";
	print(n-1);
	cout<<"\t"<< n;
}

int main()
{
	int x;
	cout<<"Enter upperbound for count: ";
	cin>>x;
	cout<<"\n";
	print(x);
	return 0;
}

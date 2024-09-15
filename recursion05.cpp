#include<iostream>
using namespace std;

bool linearSearch(int arr[] , int size, int target)
{
	if(arr[0]==target)
	{
		return true;
	}
	
	if(size==0)
	{
		return false;
	}
	
	return linearSearch(arr+1, size-1, target);
}

int main()
{
	int arr[5] = {1,2,3,4,5};
	int size = 5;
	bool ans = linearSearch(arr, size, 40);
	if(ans)
	{
		cout<<"yes the element is present"<<endl;
	}
	
	else
	{
		cout<<"Sorry, element not found"<< endl;
	}
}

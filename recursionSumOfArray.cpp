//sum of array elements using recursion
#include<iostream>
using namespace std;

int Sum(int arr[], int size)
{
	if(size == 0)
	{
		return 0;
	}
	if(size == 1)
	{
		return arr[0];
	}
	
	int remaining = arr[0] + Sum(arr+1, size -1);
	return remaining;
}

int main()
{
	int arr[5] = {1000, 2000, 3000, 4000, 5000};
	int size = 5;
	int ans = Sum(arr, size);
	cout<<ans<<endl;
}

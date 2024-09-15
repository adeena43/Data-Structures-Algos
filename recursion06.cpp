//binary search using recursion
#include<iostream>
using namespace std;

int binarySearch(int arr[], int size, int s, int e, int key)
{
	if(size == 0)
	{
		return -1;
	}
	
	int mid = s+(e-s)/2;
	if(key == arr[mid])
	{
		return mid;
	}
	
	if(key>arr[mid])
	{
		return binarySearch(arr,size/2,s = mid+1,e, key);
	}
	if(key<arr[mid])
	{
		return binarySearch(arr,size/2,s,mid-1, key);
	}
}

int main()
{
	int arr[7] = {1,2,3,4,5,6,7};
	int size = 7;
	int index = binarySearch(arr, size, 0, size -1, 4);
	cout<<"Element found at: "<<index<<endl;
}

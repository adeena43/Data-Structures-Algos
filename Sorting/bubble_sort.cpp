#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n)
{
	for(int i =1; i<n; i++)
	{
		for(int j =0; j<n-i; j++)
		{
			bool swapped = false;
			if(arr[j]>arr[j+1])
			{
				swap(arr[j], arr[j+1]);
				swapped = true;
			}
		}
		if(swapped==false)
		{
			break;
		}
	}
}

int main()
{
	int arr[5] = {5,4,3,2,1};
	
}

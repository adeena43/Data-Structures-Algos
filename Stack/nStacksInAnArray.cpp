//implementing N stack in a S sized array
#include<iostream>
#include<vector>
#include<stack>

class NStack{
	int *arr;
	int *top;
	int *next;
	
	int n, s;
	int freespot;
	
	public:
		NStack(int N, int s)
		{
			n = N;
			s = S;
			arr = new int[s];
			top = new int[n];
			next = new int[s];
			
			//top initialize
			for(int i 0; i<n; i++)
			{
				top[i] = -1;
			}
			//next initialization
			for(int i =0; i<s; i++)
			{
				next[i] = i+1;
			}
			//update last index value to -1
			next[s-1] = -1;
			freespot = 0;
		}
		
		bool push(int x, int m)
		{
			//check for overflow
			if(freespot == -1)
			{
				return false;
			}
			
			//find index
			int index = freespot;
			
			//update freespot
			freespot = next[index];
			
			//insert element in the array
			arr[index] = x;
			
			//update next
			next[index] = top[m-1];
			
			//update top
			top[m-1] = index;
			
			return true;
		}
		
		int pop(int m)
		{
			//check underflow condition
			if(top[m-1] == -1)
			{
				return -1;
			}
			
			int index = top[m-1];
			
			top[m-1] = next[index;
			
			next[index] = freespot;
			
			freespot = index;
			
			return arr[index];
		}
};

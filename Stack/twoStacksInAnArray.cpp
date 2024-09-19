//implementing two stacks in an array
#include<iostream>
using namespace std;

class TwoStacks{
	public:
		int *arr;
		int top1, top2;
		int size;
		
		TwoStacks(int s)
		{
			this->size = s;
			top1 = -1;
			top2 = s;
			arr = new int[s];
		}
		
		void push1(int num)
		{
			if(top1 - top2 > 1)
			{
				top1++;
				arr[top1] = num;
			}
			else
			{
				cout<<"StackOverflow"<<endl;
			}
		}
		
		void push2(int num)
		{
			if(top1 - top2 > 1)
			{
				top2--;
				arr[top2] = num;
			}
			else
			{
				cout<<"StackOverflow"<<endl;
			}
		}
		int pop1()
		{
			if(top1 >= 0)
			{
				int ans = arr[top1];
				top1--;
				return ans;
			}
			else
			{
				return -1;
			}
		}
		int pop2()
		{
			if(top2 < size)
			{
				int ans = arr[top2];
				top1++;
				return ans;
			}
			else
			{
				return -1;
			}
		}
};

int main()
{
	return 0;
}

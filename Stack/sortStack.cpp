//sort stack using recursion
#include<iostream>
#include<stack>
using namespace std;

void sortedInsert(stack<int> &stack, int num)
{
	if(stack.empty() || (!stack.empty() && stack.top()< num) )
	{
		stack.push(num);
		return;
	}
	
	int n = stack.top();
	stack.pop();
	
	sortedInsert(sack);
	
	stack.push(n);
	}
	
void sortStack(stack<int> &stack)
{
	//base case
	if(stack.empty())
	{
		return;
	}
	
	int num = stack.top();
	stack.pop();
	
	sortStack(stack);
	sortedInsert(stack, num);
}

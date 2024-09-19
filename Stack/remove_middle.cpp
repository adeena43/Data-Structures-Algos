void solve(stack<int>& inputStack, int count, int size)
{
	//base case
	if(count == size/2)
	{
		inputStack.pop();
		return;
	}
	
	int num = inputStack.top();
	inputStack.pop();
	
	//Recursive call
	solve(inputStack, count+1, size);
	
	inputStack.push(num);
}

void deleteMiddle(stack<int>& inputStack, int size)
{
	int count = 0
	void solve(inputStack,count,size);
}

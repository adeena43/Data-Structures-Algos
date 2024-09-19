//largest rectangle area in a histogram
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vecor<int> nextSmallerElement(vecor<int> &arr, int n)
{
	stack<int> s;
	s.push(-1);
	vector<int> ans(n);
	
	for(int i = n-1; i>=0; i--)
	{
		int curr = arr[i];
		while(s.top()!= -1 && arr[s.top()]>= curr)
		{
			s.pop();
		}
		
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

vecor<int> prevSmallerElement(vecor<int> &arr, int n)
{
	stack<int> s;
	s.push(-1);
	vector<int> ans(n);
	
	for(int i = 0; i<n; i++)
	{
		int curr = arr[i];
		while(s.top()!= -1 && arr[s.top()]>= curr)
		{
			s.pop();
		}
		
		ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

int largestArea(vector<int>& heights)
{
	int n = heights.size();
	
	vector<int> next(n);
	next = nextSmallerElement(heights, n);
	
	vector<int> prev(n);
	next = prevSmallerElement(heights, n);
	
	int area = INT_MIN;
	for(int i =0; i<n; i++)
	{
		int l = hieghts[i];
		
		if(nex[i] == -1)
		{
			next[i] = n;
		}
		//length remains constant while we just calculate the breadth as they keep varying based on their diff heights
		int b = next[i] - prev[i] -1;
		int newArea = l*b;
		area = max(area, newArea);
		
	}
	return area;
	
}

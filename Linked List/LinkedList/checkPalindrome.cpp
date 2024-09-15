//check if a linke dlist is palindrome
#include<vector>

bool checkPalindrome(vector<int> arr)
{
	int n = arr.size();
	int s = 0;
	int e = n-1 ;
	
	while(s<=e)
	{
		if(arr[s] != arr[e])
		{
			return false;
		}
		s++;
		e--;
		
	}
	return true;
}

bool isPalindrome(Node* head)
{
	vector<int> arr;
	
	Node* temp = head;
	while(temp != NULL)
	{
		arr.push_back(temp -> data);
		temp = temp -> next;
	}
	
	return checkPalindorme(arr);
}

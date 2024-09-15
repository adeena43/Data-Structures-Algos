//detect cycle in a linkedlist
#include<iostream>
#include<map>
using namespace std;

bool detectLoop(Node* head)
{
	if (head == NULL)
	{
		return false;
	}
	
	map<Node*, bool> visited;
	Node* temp = head;
	
	while(temp != NULL)
	{
		if(visited[temp] == true)
		{
			cout<<"Present at element: "<<temp->data<<endl;
			return true;
		}
		visited[temp] = true;
		temp = temp -> next;
	}
	return false;
}

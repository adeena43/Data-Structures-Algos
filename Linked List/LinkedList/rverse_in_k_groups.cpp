//reverse in the group of k(an int)
Node* kreverse(Node* head, int k)
{
	if(head == NULL)
	{
		return NULL;
	}
	
	//step: 1 Reverse k nodes
	Node* next = NULL;
	Node* prev = NULL;
	Node* curr = head;
	int count = 0;
	
	while(curr != NULL && count < k)
	{
		next = curr->next;
		curr -> next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	
	//step: 2 Recursion
	if(next!=NULL)
	{
		head -> next = kreverse(next, k);
	}
	
	//step: 3 return head of reversed list
	return prev;
}

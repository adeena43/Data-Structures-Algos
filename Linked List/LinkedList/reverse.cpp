//reversing a ll
//iterative solution (Approach -1)
Node* reversedList(Node* &head)
{
	if(head== NULL || head -> next == NULL)
	{
		return head;
	}
	
	Node* prev = NULL;
	Node* forward = NULL;
	Node* curr = head;
	
	while(curr != NULL)
	{
		forward = curr->next;
		curr -> next = prev;
		prev = curr;
		curr = forward;
	}
	return prev;
}

//recursive solution (Approach 2)
void reverse(Node* &head, Node* curr, Node* prev)
{
	if( curr == NULL)
	{
		head = prev;
		return;
	}
	
	Node* forward = curr -> next;
	reverse(head, forward, curr);
	curr -> next = prev;
}

//recursive solution(Approach 3)
Node* reversedList1(Node* &head)
{
	if(head== NULL || head -> next == NULL)
	{
		return head;
	}
	
	Node* chotaHead = reversedList1(head -> next);
	head -> next -> next = head;
	head -> next = NULL;
	return chotaHead;
}

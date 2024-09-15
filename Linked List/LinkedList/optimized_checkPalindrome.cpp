//optimized solution for checking palindrome in a linked list

Node* getMid(Node* head)
{
	Node* slow = head;
	Node* fast = head -> next;
	
	while(fast!= NULL && fast -> next != NULL)
	{
		fast = fast -> next -> next;
		slow = slow -> next;
	}
	return slow;
}

Node* reverse(Node* head)
{
	Node* curr = head;
	Node* prev = NULL;
	Node* next = NULL;
	
	while(curr != NULL)
	{
		next = curr->next;
		curr -> next = prev;
		prev = curr;
		curr = next;
	}
	
	return prev;
}

bool checkPalindrome(Node* head)
{
	if(head->next == NULL)
	{
		return true;
	}
	//step 1: get the middle
	Node* middle = getMiddle(head);
	
	//step 2: reverse the right side list of middle
	Node* temp = middle->next;
	middle -> next = reverse(temp);
	
	//step 3: compare both halves
	Node* head1 = head;
	Node* head2 = middle-> next;
	
	while(head2 != NULL)
	{
		if(head1 -> data != head2 -> data)
		{
			return false;
		}
		
		head1 = head1 -> next;
		head2 = head2 -> next;
	}
	
	//step 4: repeat step 2 to get the original form of linked list
	temp = middle->next;
	middle -> next = reverse(temp);
	
	return true;
}

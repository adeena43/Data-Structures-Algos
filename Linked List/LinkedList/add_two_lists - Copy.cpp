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

void insertAtTail(struct Node* &head, struct Node* &Tail, int val)
{
	Node* temp = new Node(val)
	if ( head == NULL)
	{
		head = temp;
		Tail = temp;
		return;
	}
	else
	{
		Tail->next = temp;
		Tail = temp;
	}
}

struct Node* add(struct Node* first, struct Node* second)
{
	int carry = 0;
	
	Node* ansHead = NULL;
	Node* ansTail = NULL;
	
	while(first != NULL || second != NULL || carry != 0)
	{
		int val1 = 0;
		if(first!=NULL)
		{
			val1 = first->data;
		}
		int val2 = 0;
		if(first!=NULL)
		{
			val2 = second->data;
		}
		
		int sum = carry + val1 + val2;
		int digit = sum%10;
		
		insertAtTail(ansHead, ansTail, digit);
		carry = sum/10;
		
		if(first!=NULL)
		{
			first=first->next;
		}
		if(second!=NULL)
		{
			second=second->next;
		}
	}
	return ansHead;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
	//step 1: reverse the input lists
	first = reverse(first);
	second = reverse(second);
	//step 2: add both the reversed lists
	Node* ans = add(first, second);
	//step 3: reverse the ans list
	ans = reverse(ans);
	return ans;
}

//floyd detection algorithm
//checks if a loop is present in a ll

bool floydDetect(Node* head)
{
	if(head == NULL)
	{
		return false;
	}
	Node* slow = head;
	Node* fast = head;
	
	while(slow != NULL && fast != NULL)
	{
		fast = fast -> next;
		if(fast != NULL)
		{
			fast = fast -> next;
		}
		slow = slow -> next;
		
		if(slow == fast)
		{
			cout<<"Present at "<<slow -> data<< endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}

Node* getStartingNode(Node* head)
{
	if(head == NULL)
	{
		return NULL;
	}
	
	Node* intersection = floydDetection(head);
	Node* slow = head;
	
	while( slow != inersection)
	{
		slow = slow -> next;
		intersection = intersection -> next;
	}
	
	return slow;
}

void removeLoop(Node* head)
{
	if(head == NULL)
	{
		return;
	}
	Node* startOfLoop = getStartingNode(head);
	if(startOfLoop == NULL)
	{
		return head;
	}
	Node* temp = starOfLoop;
	
	while(temp -> next != startOfLoop)
	{
		temp = temp -> next;
	}
	temp -> next = NULL;
}

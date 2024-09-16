//delete duplicates form a sored linked list

Node* uniqueSortedList(Node* head)
{
	if(head == NULL)
	{
		return NULL;
	}
	//non empty list
	Node* curr = head;
	
	while(curr != NULL)
	{
		if((curr -> next != NULL) && curr ->data == curr->next->data)
		{
			Node* next_next = curr->next->next;
			Node* nodeToDelete = curr -> next;
			delete(nodeToDelete);
			curr -> next = next_next;
		}
		else
		{
			curr = curr->next;
		}
	}
	return head;
}

// Function to remove duplicates from an unsorted linked list
void removeDuplicates(Node* head) {
    Node* curr = head;

    while (curr != NULL) {
        Node* temp = curr;
        // Check for duplicates of the current node
        while (temp->next != nullptr) {
            if (temp->next->data == curr->data) {
                // Remove duplicate node
                Node* duplicate = temp->next;
                temp->next = temp->next->next;
                delete duplicate;
            } else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

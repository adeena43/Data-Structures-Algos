#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    
    ~Node()
    {
    	int val = this -> data;
    	if(next != NULL)
    	{
    		delete next;
    		next = NULL:
		}
		cout<<"Memory free for node with data "<<val<<endl;
	}
};

void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    return length;
}

void insertAtHead(Node* &head, Node* &tail, int d) {
	if(head == NULL)
	{
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else
	{
			
	    Node* temp = new Node(d);
	    if (head != NULL) {
	        head->prev = temp;
	    }
	    temp->next = head;
	    head = temp;
	}
}

void insertAtTail(Node* &tail, Node* &head, int d) {
	if(tail == NULL)
	{
		Node* temp = new Node(d);
		tail = temp;
		head = temp;
	}
	else
	{
			
	    Node* temp = new Node(d);
	    if (tail != NULL) {
	        tail->next = temp;
	    }
	    temp->prev = tail;
	    tail = temp;
	}
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if (position < 1) {
        cout << "Invalid position!" << endl;
        return;
    }
    
    if (position == 1) {
        insertAtHead(head, tail, d);
        if (tail == NULL) {
            tail = head;
        }
        return;
    }
    
    Node* temp = head;
    int cnt = 1;

    // Move temp to the node just before the insertion position
    while (cnt < position - 1 && temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    // Check if temp is NULL (means position is out of bounds)
    if (temp == NULL) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    nodeToInsert->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = nodeToInsert;
    }
    temp->next = nodeToInsert;

    // Update tail if insertion is at the end
    if (nodeToInsert->next == NULL) {
        tail = nodeToInsert;
    }
}

void deleteNode(int position, Node* &head, Node* &tail)
{
    // Deleting first node
    if(position == 1)
    {
        Node* temp = head;
        if(head == tail) // Only one node in the list
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = temp->next;
            head->prev = NULL;
        }
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        
        if(curr == tail) // Deleting the tail node
        {
            prev->next = NULL;
            tail = prev;
        }
        else
        {
            curr->next->prev = prev;
            prev->next = curr->next;
        }
        
        curr->next = NULL;
        delete curr;
    }
}
int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    insertAtTail(tail, head, 53);
    print(head); // Output: 10 53

    int len = getLength(head);
    cout << "The length is: " << len << endl; // Output: The length is: 2

    insertAtPosition(head, tail, 2, 32); // Insert 32 at position 2
    print(head); // Output: 10 32 53

    return 0;
}


#include<iostream>
#include<vector>
using namespace std;

class Node
{
    private:
        int data;
        Node* next;

    public:
        Node(int data)
        {
            this->data = data;
            this->next = nullptr;
        }

        Node()
        {
            this->data = 0;
            this->next = nullptr;
        }

    friend class SinglyLinkedList;
    friend class CircularLinkedList;
};

class CircularLinkedList{
    private:
        Node* head;
        Node* tail;

    public:
        CircularLinkedList(Node* node = nullptr)
        {
            if(!node)
            {
                this->head = tail = node;
                tail->next = head;
            }
            else
            {
                this->head=tail = nullptr;
            }
        }

        int countNodes()
        {
            if (head == nullptr) {
                return 0;  // Empty list
            }

            int cnt = 1;  // Start with 1 since we know the head exists
            Node* temp = head->next;  // Start from the second node

            // Traverse the circular list and count the nodes
            while (temp != head) {
                cnt++;
                temp = temp->next;
            }

            return cnt;  // Return the count of nodes
        }

};

class SinglyLinkedList
{
    private:
        Node* head;

    public:
        // Constructor that initializes head with a given node
        SinglyLinkedList(Node* node = nullptr)  // Default to nullptr for an empty list
        {
            this->head = node;
        }

        // Method to display the list for testing
        void display()
        {
            Node* current = head;
            while (current != nullptr)
            {
                cout << current->data << " -> ";
                current = current->next;
            }
            cout << "nullptr" << endl;
        }
        bool areAdjacent(Node* p, Node* prevP, Node* prevQ, Node* q)
        {
            if(((p->next == q)&&(prevQ == p)) || ((q->next == p)&&(prevP == q)))
            {
                return true;
            }
            else{
                return false;
            }
        }

        //remove the last node of the singly linked list
        void removeLastNode()
        {
            if(head == nullptr)
            {
                cout << "Nothing to delete" << endl;
                return;
            }
            if(head->next == nullptr)
            {
                delete head;  
                head = nullptr;  
                return;
            }

            Node* temp = head;
            Node* prev = nullptr;
            
            while(temp->next)  
            {
                prev = temp;
                temp = temp->next;
            }
            prev->next = nullptr;  
            delete temp;  
        }
};

int main()
{
    SinglyLinkedList list1;
    list1.display();  

    Node* node = new Node(10);
    SinglyLinkedList list2(node);
    list2.display();  
    return 0;
}

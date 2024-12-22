#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* next;
    public:
        Node(int data = 0)
        {
            this->data = data;
            this->next = nullptr;
        }
        friend class CircularLinkedList; 
};

class CircularLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        CircularLinkedList()
        {
            this->head= nullptr;
            this->tail = nullptr;
        }

        Node* findWinner(int n, int k) {
            int arr[n] = {0};
            if (head == NULL) {  
                cout << "List is empty" << endl;
                return;
            }

            Node* current = head; 
            while(head!=tail)
            {
                while(current != head){
                    int i;
                    for(i = 0; i<k; i++)
                    {
                        if(arr[i]==1)
                        {
                            continue;
                        }
                        current = current->next;
                    }
                    arr[i+1] = 1;
                }
            } 
            return head;
            cout << endl;  
        }

};

int main()
{
    return 0;
}
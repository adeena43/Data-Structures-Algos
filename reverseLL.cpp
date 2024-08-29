#include <iostream>
using namespace std;

class node {
public:
    int data;
    node *next;
    
    node(int d) {
        this->data = d;
        this->next = NULL;
    }
};

node* reverseLL(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    
    while (curr != NULL) {
        next = curr->next; 
        curr->next = prev; 
        prev = curr;       
        curr = next;       
    }
    return prev;
}

void printLL(node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->next; 
    }
    cout << endl;
}

int main() {
    node* root = new node(1);
    root->next = new node(2);
    root->next->next = new node(4);
    root->next->next->next = new node(5);
    root->next->next->next->next = new node(6);
    
    cout << "Printing the original linked list: " << endl;
    printLL(root);
    root = reverseLL(root);
    
    cout << "Printing the reversed linked list: " << endl;
    printLL(root);
    while (root != NULL) {
        node* temp = root;
        root = root->next;
        delete temp;
    }
    
    return 0;
}

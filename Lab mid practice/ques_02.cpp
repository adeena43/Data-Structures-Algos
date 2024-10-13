#include <iostream>

using namespace std;

// Define a structure for the linked list node
struct Node {
    int data;        // Data stored in the node
    Node* next;     // Pointer to the next node

    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize a node
};

// Function to find the length of the linked list using tail recursion
int findLength(Node* head, int count = 0) {
    // Base case: If the current node is null, return the count
    if (head == nullptr) {
        return count;
    }

    // Recursive call to the next node, incrementing the count
    return findLength(head->next, count + 1);
}

// Helper function to add a new node at the end of the list
void appendNode(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode; // If the list is empty, set the new node as the head
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the new node at the end
    }
}

// Main function to demonstrate the length finding
int main() {
    Node* head = nullptr; // Initialize the linked list

    // Append some nodes to the list
    appendNode(head, 10);
    appendNode(head, 20);
    appendNode(head, 30);
    appendNode(head, 40);

    // Find the length of the linked list
    int length = findLength(head);
    cout << "Length of the linked list: " << length << endl; // Output: 4

    // Clean up memory (optional, for completeness)
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current; // Free the memory
        current = nextNode;
    }

    return 0;
}

#include <iostream>
using namespace std;

// Node structure for singly linked list
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {} // Constructor to initialize node
};

// Function to insert a new node at the end of the list
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Non-tail recursive function to search for a value in the linked list
bool search(Node* head, int val) {
    // Base case: if the list is empty, return false
    if (head == nullptr) {
        return false;
    }

    // Check if the current node contains the value
    if (head->data == val) {
        return true; // Value found
    }

    // Recursively call search for the next node
    // The check here is non-tail because we have to return its result
    return search(head->next, val);
}

// Main function to test the linked list and search functionality
int main() {
    Node* head = nullptr; // Initialize the linked list

    // Insert some values into the linked list
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    // Value to search for
    int valueToSearch;
    cout << "Enter a value to search for: ";
    cin >> valueToSearch;

    // Search for the value in the linked list
    if (search(head, valueToSearch)) {
        cout << "Value " << valueToSearch << " found in the linked list." << endl;
    } else {
        cout << "Value " << valueToSearch << " not found in the linked list." << endl;
    }

    // Clean up memory (not shown for brevity)

    return 0;
}

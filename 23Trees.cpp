#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Node structure for 2-3 Tree
struct Node {
    vector<int> keys; // Stores the keys within the node (1 or 2 keys)
    vector<Node*> children; // Stores the children of the node (2 or 3 children)
    Node* parent; // Pointer to the parent node
    bool isLeaf; // Flag indicating whether the node is a leaf

    // Constructor to initialize a new node
    Node() : parent(nullptr), isLeaf(true) {}
};

// Function to create a new node
Node* createNode() {
    return new Node();
}

// Function to find the appropriate leaf for insertion
Node* findLeaf(Node* root, int key) {
    Node* current = root; // Start from the root node
    // Traverse down until we reach a leaf node
    while (!current->isLeaf) {
        if (key < current->keys[0]) // If the key is less than the first key, move to the left child
            current = current->children[0];
        else if (current->keys.size() == 1 || key < current->keys[1]) // If the key is between the first and second key, move to the middle child
            current = current->children[1];
        else // If the key is greater than the second key, move to the right child
            current = current->children[2];
    }
    return current; // Return the found leaf node
}

// Function to split a node when it overflows (i.e., has 3 keys)
void split(Node*& root, Node* node) {
    cout << "Splitting node with keys: ";
    for (int k : node->keys) cout << k << " ";
    cout << endl;

    int middleKey = node->keys[1]; // The middle key to be promoted to the parent
    Node* leftChild = createNode(); // Create a new left child node
    Node* rightChild = createNode(); // Create a new right child node

    leftChild->keys.push_back(node->keys[0]); // The left child gets the first key
    rightChild->keys.push_back(node->keys[2]); // The right child gets the third key
    leftChild->isLeaf = rightChild->isLeaf = node->isLeaf; // Set both children as leaves or internal based on the original node

    // If the node is not a leaf, adjust the children pointers
    if (!node->isLeaf) {
        leftChild->children = {node->children[0], node->children[1]}; // Left child takes the first two children
        rightChild->children = {node->children[2], node->children[3]}; // Right child takes the last two children
        for (Node* child : leftChild->children) child->parent = leftChild; // Update parent pointers for left children
        for (Node* child : rightChild->children) child->parent = rightChild; // Update parent pointers for right children
    }

    // If the node has no parent (it is the root), create a new root
    if (!node->parent) {
        Node* newRoot = createNode(); // Create a new root node
        newRoot->keys.push_back(middleKey); // New root takes the middle key
        newRoot->children = {leftChild, rightChild}; // The new root points to the split children
        leftChild->parent = rightChild->parent = newRoot; // Set the parent pointers for the split children
        newRoot->isLeaf = false; // The new root is not a leaf
        root = newRoot; // Update the root of the tree
    } else {
        Node* parent = node->parent; // Get the parent of the node
        parent->keys.push_back(middleKey); // Add the middle key to the parent
        sort(parent->keys.begin(), parent->keys.end()); // Sort the keys in the parent

        // Find the position of the current node in the parent's children
        auto it = find(parent->children.begin(), parent->children.end(), node);
        int index = distance(parent->children.begin(), it);
        parent->children[index] = leftChild; // Replace the current node with the left child
        parent->children.insert(parent->children.begin() + index + 1, rightChild); // Insert the right child

        leftChild->parent = rightChild->parent = parent; // Update parent pointers for the split children

        // If the parent now has 3 keys, split it recursively
        if (parent->keys.size() == 3)
            split(root, parent);
    }
}

// Function to insert a key into the 2-3 Tree
void insert(Node*& root, int key) {
    cout << "Inserting key " << key << endl;

    // If the tree is empty, create the root node
    if (!root) {
        root = createNode();
        root->keys.push_back(key);
        return;
    }

    // Find the appropriate leaf node for the new key
    Node* leaf = findLeaf(root, key);
    leaf->keys.push_back(key); // Add the key to the leaf node
    sort(leaf->keys.begin(), leaf->keys.end()); // Sort the keys in the leaf node

    // If the leaf node now has 3 keys, split it
    if (leaf->keys.size() == 3)
        split(root, leaf);
}

// Function to merge nodes when necessary (after deletion causes underflow)
void merge(Node*& root, Node* node) {
    cout << "Merging nodes due to underflow" << endl;
    Node* parent = node->parent; // Get the parent of the current node

    // Find the index of the current node in its parent's children vector
    int index = 0;
    while (index < parent->children.size() && parent->children[index] != node) {
        index++;
    }

    // Try to merge with the left sibling if possible
    if (index > 0) { // Check if there is a left sibling
        Node* leftSibling = parent->children[index - 1]; // Get the left sibling

        // Move the key from the parent down to the left sibling
        leftSibling->keys.push_back(parent->keys[index - 1]);

        // Merge the keys from the current node into the left sibling
        leftSibling->keys.insert(leftSibling->keys.end(), node->keys.begin(), node->keys.end());

        // Remove the key from the parent
        parent->keys.erase(parent->keys.begin() + index - 1);

        // Remove the merged node (current node) from the parent's children
        parent->children.erase(parent->children.begin() + index);

        // If the parent becomes empty and it's the root, make the left sibling the new root
        if (parent == root && parent->keys.empty()) {
            root = leftSibling;
            root->parent = nullptr; // Update the parent pointer
        } else if (parent->keys.size() == 0) {
            // If the parent still has no keys, continue merging up the tree
            merge(root, parent);
        }
    } else { // If there is no left sibling, try merging with the right sibling
        Node* rightSibling = parent->children[index + 1]; // Get the right sibling

        // Move the key from the parent down to the right sibling
        rightSibling->keys.insert(rightSibling->keys.begin(), parent->keys[index]);

        // Merge the keys from the current node into the right sibling
        rightSibling->keys.insert(rightSibling->keys.begin(), node->keys.begin(), node->keys.end());

        // Remove the key from the parent
        parent->keys.erase(parent->keys.begin() + index);

        // Remove the merged node (current node) from the parent's children
        parent->children.erase(parent->children.begin() + index);

        // If the parent becomes empty and it's the root, make the right sibling the new root
        if (parent == root && parent->keys.empty()) {
            root = rightSibling;
            root->parent = nullptr; // Update the parent pointer
        } else if (parent->keys.size() == 0) {
            // If the parent still has no keys, continue merging up the tree
            merge(root, parent);
        }
    }
}

// Function to delete a key from the 2-3 Tree
void deleteKey(Node*& root, int key) {
    cout << "Deleting key " << key << endl;

    // Find the leaf node containing the key
    Node* leaf = findLeaf(root, key);

    // Find the key in the leaf's keys vector
    auto it = find(leaf->keys.begin(), leaf->keys.end(), key);
    if (it == leaf->keys.end()) { // If the key is not found
        cout << "Key not found in the tree!" << endl;
        return;
    }

    // Remove the key from the leaf node
    leaf->keys.erase(it);

    // Check if the leaf now has no keys (underflow) and it's not the root
    if (leaf->keys.size() < 1 && leaf != root) {
        merge(root, leaf); // Merge nodes to fix underflow
    }
}

// Function to print the 2-3 Tree
void printTree(Node* root, int level = 0) {
    if (!root) return; // If the tree is empty, return

    // Print the keys at the current level
    cout << "Level " << level << ": ";
    for (int key : root->keys) cout << key << " ";
    cout << endl;

    // Recursively print all children of the current node
    for (Node* child : root->children) {
        printTree(child, level + 1); // Increase level by 1 for each child level
    }
}

// Main function
int main() {
    Node* root = nullptr;

    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 30);

    cout << "Tree structure after insertions:" << endl;
    printTree(root);

    deleteKey(root, 15);
    cout << "Tree structure after deletion of 15:" << endl;
    printTree(root);

    deleteKey(root, 10);
    cout << "Tree structure after deletion of 10:" << endl;
    printTree(root);

    return 0;
}

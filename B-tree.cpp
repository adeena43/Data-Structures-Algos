#include <iostream>
using namespace std;

class Node {
    int data;
    Node* left;
    Node* right;

public:
    Node(int d) {
        this->data = d;
        left = NULL;
        right = NULL;
    }
    friend class BinaryTree;
};

class BinaryTree {
public:
    Node* root;
    BinaryTree() : root(NULL) {}

    void addNode(int d) {
        Node* newNode = new Node(d);
        if (root == NULL)
            root = newNode;
        else
            addNodeRecursive(root, newNode);
    }

    void addNodeRecursive(Node* current, Node* newNode) {
        if (current->left == NULL) {
            current->left = newNode;
        } else if (current->right == NULL) {
            current->right = newNode;
        } else {
            if (countNodes(current->left) <= countNodes(current->right))
                addNodeRecursive(current->left, newNode);
            else
                addNodeRecursive(current->right, newNode);
        }
    }

    int countNodes(Node* root) {
        if (root == NULL) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    void inOrder(Node* root) {
        if (root == NULL)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    Node* deleteNode(Node* root, int key) {
        if (root == NULL) return NULL;

        if (root->data == key) {
            // Handle case where node to delete has no children
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }

            // Handle case where node to delete has children
            Node* deepest = findDeepestNode(root);
            root->data = deepest->data;
            deleteDeepest(root, deepest);
            return root;
        }

        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }

    Node* findDeepestNode(Node* root) {
        if (root->left == NULL && root->right == NULL)
            return root;

        if (root->right != NULL)
            return findDeepestNode(root->right);
        else
            return findDeepestNode(root->left);
    }

    void deleteDeepest(Node* parent, Node* target) {
        if (parent == NULL) return;

        if (parent->left == target) {
            delete target;
            parent->left = NULL;
            return;
        }
        if (parent->right == target) {
            delete target;
            parent->right = NULL;
            return;
        }

        deleteDeepest(parent->left, target);
        deleteDeepest(parent->right, target);
    }
};

int main() {
    BinaryTree bt;
    bt.addNode(10);
    bt.addNode(20);
    bt.addNode(30);
    bt.addNode(40);
    bt.addNode(50);
    bt.addNode(60);
    bt.addNode(70);

    cout << "In-order Traversal before Deletion: ";
    bt.inOrder(bt.root);
    cout << "\n";

    cout << "After Deleting Node with Key 30:\n";
    bt.deleteNode(bt.root, 30);
    bt.inOrder(bt.root);
    cout << "\n";

    return 0;
}

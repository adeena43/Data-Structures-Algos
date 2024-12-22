#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Node{
    public:
        int data;
        Node* right;
        Node* left;

        Node(int data)
        {
            this->data = data;
            this->left = right = NULL;
        }
};

class heap{
    public:
        Node* head;

        heap()
        {
            this->head = NULL;
        }

        int isAValidMinHeap(Node* head)
        {
            if(!head)
            {
                return 0;
            }
            bool isHeap = true;
            if(head->right && head->right->data > head->data)
            {
                isHeap = false;
            }
            if(head->left && head->left->data > head->data)
            {
                isHeap = false;
            }

            int leftHeight = isAValidMinHeap(head->left);
            int rightHeight = isAValidMinHeap(head->right);

            return 1+min(leftHeight, rightHeight);
        }
};

int main()
{
    return 0;
}
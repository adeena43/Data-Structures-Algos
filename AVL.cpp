#include<iostream>
using namespace std;

class Node{
    public:
        int data, height;
        Node* left;
        Node* right;

        Node(int value)
        {
            this->data = value;
            this->height = 1;
            this->right = NULL;
            this->left = NULL;
        }
};

int getHeight(Node* root)
{
    if(!root)
    {
        return 0;
    }
    return root->height;
}


int getBalance(Node* root)
{
    return getHeight(root->left) - getHeight(root->right);
}

//right rotation
Node* rigthRotation(Node* root)
{
    Node* child = root->left;
    Node* childRight = child->right;
    child->right = root;
    root->left = childRight;
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

//left rotation->right right
Node* leftRotation(Node* root)
{
    Node* child = root->right;
    Node* childLeft = child->left;
    child->left = root;
    root->right = childLeft;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    return child;
}

//deletion
Node* deleteNode(Node* root, int key)
{
    if(!root)
    {
        return NULL;
    }
    if(key<root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    if(key>root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    //if you have to delete the root node
    else
    {
        //leaf node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        //only one hcild exists
        else if(root->left && !root->right)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left && root->right){
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //both the children exist
        else
        {
            //Right side smallest element
            Node* curr = root->right;
            while(curr->left)
            {
                curr=curr->left;
            }
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    //update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    //check the balance
    int balance = getBalance(root);

    //if bal>1->L
    if(balance>1)
    {
        //LL
        if(getBalance(root->left)>=0)
        {
            return rigthRotation(root);
        }
        //LR
        else
        {
            root->left = leftRotation(root);
            return rigthRotation(root);
        }
    }
    //else right side
    else if(balance<-1)
    {
        //RR
        if(getBalance(root->right)<=0)
        {
            return leftRotation(root);
        }
        //RL
        else
        {
            root->right = rigthRotation(root->right);
            return leftRotation(root);
        }
    }
    else{
        return root;
    }
}

Node* insert(Node* root, int key)
{
    //NULL node
    if(!root)
    {
        return new Node(key);
    }
    //root exists
    if(key<root->data)
    {
        root->left = insert(root->left, key);
    }
    else if(key>root->data)
    {
        root->right = insert(root->right, key);
    }
    else{
        return root;
    }
    //Update height everytime a node is inserted
    root->height=1 + max(getHeight(root->left), getHeight(root->right));

    //check balancing
    int balance = getBalance(root);
    //Left left case
    if(balance>1 && key<root->left->data)
    {
        return rigthRotation(root);
    }
    //right right case
    if(balance < -1 && root->right->data<key)
    {
        return leftRotation(root);
    }
    //left right case
    if(balance>1 && key > root->left->data)
    {
        root->left = leftRotation(root->left);
        return rigthRotation(root);
    }
    //right left case
    if(balance<-1 && root->right->data>key)
    {
        root->right = rigthRotation(root->right);
        return leftRotation(root);
    }
    //no unbalance
    else
    {
        return root;
    }
}

int main()
{
    Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);
    return 0;
}

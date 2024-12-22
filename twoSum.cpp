#include<iostream>
#include<vector>
using namespace std;

void inorder(BinaryTree<int>* root, vector<int> &in)
{
    if(root== NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(BinaryTree<int>* root, int target)
{
    vector<int> inorderVal;
    inorder(root, inorderVal);
    int i = 0;
    int j = inorderVal.size() - 1;

    while(i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if(sum == target)
        {
            return true;
        }

        else if(sum > target)
        {
            j--;
        }

        else
        {
            i++;
        }
    }
    return false;
}
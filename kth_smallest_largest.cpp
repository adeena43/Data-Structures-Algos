int solvekthsmallest(BinaryTreeNode<int>* root, int &i, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = solvekthsmallest(root->left, i, k);
    if(left!=-1)
    {
        return left;
    }

    i++;
    if(i==k)
    {
        return root->data;
    }

    return solvekthsmallest(root->right, i, k);
}

int solvekthlargest(BinaryTreeNode<int>* root, int &i, int k)
{
    if(root == NULL)
    {
        return -1;
    }

    int left = solvekthlargest(root->left, i, k);
    if(left!=-1)
    {
        return left;
    }

    i++;
    if(i == (n-k)  + 1)
    {
        return root->data;
    }

    return solvekthlargest(root->right, i, k);
}

int kthSmallest(BinaryTreeNode<int>* root, int &i, int k)
{
    int i = 0;
    int ans = solvekthsmallest(root, i, k);
    return ans;
}
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> zigzagTraversal(Node* root)
{
    vector<int> result;
    if(root == NULL)
    {
        return result;
    }
    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans;

        for(int i = 0; i<size; i++)
        {
            Node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if(frontNode->left)
            {
                q.push(frontNode->left);
            }
            if(frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight;

        for(int i = 0; i<ans.size(); i++)
        {
            result.push_back(ans);
        }
    }
    return result;
}

int main()
{
    return 0; 
}
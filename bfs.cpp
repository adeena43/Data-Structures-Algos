#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsOfGraph(int v, vector<int> adj[])
{
    queue<int> q;
    vector<int> ans;
    q.push(0);
    vector<bool> visited(v, 0);
    visited[0] = 1;
    int node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);

        for(int j = 0; j<adj[node].size(); j++)
        {
            if(!visited[adj[node][j]])
            {
                visited[adj[node][j]] = 1;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}

void DFS(int node, vector<int> adj[], vector<int> &ans, vector<bool> &visited)
{
    visited[node] = 1;
    ans.push_back(node);


    for(int j = 0; j<adj[node].size(); j++)
    {
        if(!visited[adj[node][j]])
        {
            DFS(adj[node][j], adj, ans, visited);
        }
    }
    
}

vector<int> dfsOfGraph(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);
    vector<int> ans;
    DFS(0, adj, ans, visited);
    return ans;
}

int main()
{
    return 0;
}
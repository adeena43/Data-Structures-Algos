#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

void DFS(int node, vector<int> adj[], vector<bool> &visited, stack<int> &s)
{
    visited[node] = 1;
    for(int i = 0; i<adj[node].size(); i++)
    {
        if(!visited[adj[node][i]])
        {
            DFS(adj[node][i], adj, visited, s);
            
        }
    }
    s.push(node);
}

vector<int> topological_sort(int v, vector<int> adj[])
{
    vector<bool> visited(v, 0);
    stack<int> s;

    for(int i = 0; i<v; i++)
    {
        if(!visited[i])
        {
            DFS(0, adj, visited, s);
        }
        
    }
    
    vector<int> ans;
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

//topological sort using BFS
vector<int> topoSort(int v, vector<int> adj[])
{
    vector<int> ans;
    vector<int> indegree(v, 0);

    //1. calculate th eindegre of all the nodes
    for(int i = 0; i<v; i++)
    {
        for(int j = 0; j<adj[i].size(); j++)
        {
            indegree[adj[i][j]]++;
        }
    }

    //ush all the nodes with 0 indegree into the queue
    queue<int> q;
    for(int i = 0; i<v; i++)
    {
        if(!indegree[i])
        {
            q.push(i);
        }
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(int j = 0; j<adj[node].size(); j++)
        {
            indegree[adj[node][j]]--;
            if(indegree[adj[node][j]]==0)
            {
                q.push(adj[node][j]);
            }
        }
    }

    return ans;
}

int main()
{
    return 0;
}
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

int findParent(int u, vector<int> &parent)
{
    if(u==parent[u])
    {
        return u;
    }
    else{
        //path compression
        return parent[u] = findParent(parent[u], parent);
    }
}

void unionByRank(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);

    //merge the node with smaller node with the node with higher rank
    if(rank[pu] > rank[pv])
    {
        parent[pv] = pu;
    }
    else if(rank[pv] > rank[pu])
    {
        parent[pu] = pv;
    }
    else{
        parent[pv] = pu;
        rank[pu]++;
    }
}

int spanningTree(int v, vector<vector<int>> adj[])
{
    vector<int> parent(v);  //ulimate parent array
    vector<int> rank(v, 0); //helps us to get the rank of the node

    for(int i = 0; i<v; i++)
    {
        parent[i] = i;
    }

    //priority queue
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    for(int i = 0; i<v; i++)
    {
        for(int j = 0; j<adj[i].size(); j++)
        {
            pq.push({adj[i][j][1], {i, adj[i][j][0]}});
        }
    }

    int cost = 0;
    int edges = 0;

    while(pq.empty())
    {
        int wt = pq.top().first;
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        pq.pop();

        //check if thet are in different sets
        if(findParent(u, parent) != findParent(v, parent))
        {
            cost += wt;
            unionByRank(u, v, parent, rank);
            edges++;
            if(edges == v-1)
            {
                break; 
            }
        }
    }

    return cost;
}

int main()
{
    return 0;
}
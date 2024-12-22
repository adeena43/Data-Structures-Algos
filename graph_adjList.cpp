#include<iostream>
#include<vector>
using namespace std;

//undirected graph(with weight)
int main()
{
    int vertex, edges, weight;
    cout<<"Enter the number of vertices: ";
    cin>>vertex;
    cout<<"Enter the number of edges: ";
    cin>>edges;
    cout<<"Enter the weight: ";
    cin>>weight;

    vector<pair<int, int>> adjList[vertex];
    int u, v;
    for(int i = 0; i< edges; i++)
    {
        cin>>u>>v;
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    //print the list
    for(int i = 0; i<vertex; i++)

    {
        cout<<i<<"->";
        for(int j = 0; j<adjList[i].size(); j++)
        {
            cout<<adjList[i][j].first<<" "<<adjList[i][j].second<<" ";
        }
        cout<<endl;
    }
    return 0;
}
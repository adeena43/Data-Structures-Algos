#include<vector>
#include<iostream>
using namespace std;

//representing an undirected unweighted graph by an adjacency matrix
int main()
{
    int vertex, edges;
    cout<<"Enter the number of vertices: ";
    cin>>vertex;
    cout<<"Enter the number of edges: ";
    cin>>edges;

    vector<vector<int> > adjMat(vertex, vector<int>(vertex, 0));

    int u, v, weight;

    cout<<"Enter the edge from u to v"<<endl;

    for(int i = 0; i< edges; i++)
    {
        cout<<"Enter u: ";
        cin>>u;
        cout<<"Enter v: ";
        cin>>v;
        cout<<"Enter weight: ";
        cin>>weight;
        adjMat[u][v] = weight;
        adjMat[v][u] = weight;
    } 

    for(int i = 0; i<vertex; i++)
    {
        for(int j = 0; j<vertex; j++)
        {
            cout<<adjMat[i][j]<<" ";
        }
        cout<<endl;
    }
}
// Nazbii
// 1123547
// 24.12.10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// structure to represent an edge
struct Edge
{
    int u, v, weight;
};

// function to find the parent of a vertex
int findParent(int vertex, vector<int> &parent)
{
    if (parent[vertex] == vertex)
        return vertex;
    return parent[vertex] = findParent(parent[vertex], parent); // Path compression
}

// function to union two sets
void unionSets(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int parentU = findParent(u, parent);
    int parentV = findParent(v, parent);

    if (parentU != parentV)
    {
        if (rank[parentU] < rank[parentV])
        {
            parent[parentU] = parentV;
        }
        else if (rank[parentU] > rank[parentV])
        {
            parent[parentV] = parentU;
        }
        else
        {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
}

// using kruskal's Algorithm to find the MST weight
int findMSTWeight(int V, vector<Edge> &edges)
{
    // sorting edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.weight < b.weight; });

    // initializing parent and rank arrays
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; ++i)
    {
        parent[i] = i;
    }

    int mstWeight = 0;
    for (auto &edge : edges)
    {
        if (findParent(edge.u, parent) != findParent(edge.v, parent))
        {
            mstWeight += edge.weight;
            unionSets(edge.u, edge.v, parent, rank);
        }
    }

    return mstWeight;
}

int main()
{
    int V, E;
    cout << "Enter vertices and edges: ";
    cin >> V >> E;

    cout << "Input the edges: " << endl;
    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // output the weight
    cout << findMSTWeight(V, edges) << endl;

    return 0;
}

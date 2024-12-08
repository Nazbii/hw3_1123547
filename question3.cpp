//Nazbii
//1123547
//24.12.08
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

void dfsAssist(int node, vector<bool>& visited, vector<int>& result, const vector<vector<int>>& adj) {
    // mark the current node as visited and add to the result
    visited[node] = true;
    result.push_back(node);

    // traverse all neighbors in the order of the adjacency list
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsAssist(neighbor, visited, result, adj);
        }
    }
}

vector<int> dfsTraverse(const vector<vector<int>>& adj) {
    int V = adj.size(); // number of vertices
    vector<bool> visited(V, false); // To track visited nodes
    vector<int> result; // To store DFS traversal

    // start DFS from vertex 0
    dfsAssist(0, visited, result, adj);

    return result;
}

int main() {

    vector<vector<int>> adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};


    // using DFS
    vector<int> traversal = dfsTraverse(adj);

    //output
    cout << "[";
    for (size_t i = 0; i < traversal.size(); ++i) {
        cout << traversal[i];
        if (i < traversal.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}

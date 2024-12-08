//Nazbii
//1123547
//24.12.08
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(const vector<vector<int>>& adj) {
    int V = adj.size();  // number of vertices is the size of adj
    vector<int> bfs;     // to store the BFS traversal
    vector<bool> visited(V, false); // to track visited vertices
    queue<int> q;        // queue for BFS

    // start BFS from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        bfs.push_back(current);

        //visit all neighbors of the current vertex
        for (int neighbor : adj[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return bfs;
}

int main() {
    vector<vector<int>> adj = {  {1, 4, 2}, {0}, {0, 3}, {2, 4}, {0, 3}};

    // BFS traversal
    vector<int> result = bfsTraversal(adj);

    cout << "[";
    for (int node : result) {
        cout << node << " ";
    }
    cout << "]";
    cout << endl;

    return 0;
}



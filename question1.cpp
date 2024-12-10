//Nazbii
//1123547
//24.12.10


#include <iostream>
#include <vector>
using namespace  std;

vector<vector<int>> createAdjList(int vi, vector<pair<int, int>> edges) {
  //Initialize an adjacency list with v empty lists
  vector<vector<int>> adjList(vi);

  //Fill in adjacency list
  for (auto edge : edges) {
      int u = edge.first; //first node of the edge
      int v = edge.second; //second node of the edge
      adjList[u].push_back(v);
      adjList[v].push_back(u);
  }
  return adjList;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    //input the edges
    vector<pair<int, int>> edges;
    cout << "Enter the edges: ";
    for(int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u, v});
    }

    vector<vector<int>> adjList = createAdjList(V, edges);

    for (int i = 0;  i < adjList.size(); ++i) {
        cout << i << ": ";
        for (int n : adjList[i]) {
            cout << n << " ";
        }
        cout << endl;
    }
    return 0;
}

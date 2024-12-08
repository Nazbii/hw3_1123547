Question: 1
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input:
V = 4, E = 4
edges = [[0,1], [1,2], [2,3], [3,0]]

Output: 
[[1,3], [0,2], [1,3], [2,0]]
Explanation:
Node 0 is connected to 1 and 3.
Node 1 is connected to 0 and 2.
Node 2 is connected to 1 and 3.
Node 3 is connected to 2 and 0.


Question: 2
Given a connected undirected graph represented by an adjacency list adj, which is a vector of vectors where each adj[i] represents the list of vertices connected to vertex i. Perform a Breadth First Traversal (BFS) starting from vertex 0, visiting vertices from left to right according to the adjacency list, and return a list containing the BFS traversal of the graph.
Note: Do traverse in the same order as they are in the adjacency list.
Examples: (Should not use the examples to submit your code. These examples are for your understanding)
Input: adj = [ [1, 4, 2], [0], [0, 3], [2, 4], [0, 3]]

Output: [0, 1, 4, 2, 3]
Visit 0 → Output: 0
Visit 1 (first neighbor of 0) → Output: 0, 1
Visit 4 (next neighbor of 0) → Output: 0, 1, 4
Visit 2 (next neighbor of 0) → Output: 0, 1, 4, 2
Visit 3 (neighbor of 2) → Final Output: 0, 1, 4, 2, 3

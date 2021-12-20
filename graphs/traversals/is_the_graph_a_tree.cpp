/*
Given a graph with 'V' vertices numbered from 0 to 'V' - 1 and 'E' edges. Determine if it 
is a tree or not?

Approach:

A graph is a tree if the following two conditions are satisfied:

- There are no cycles present in the graph
- The graph is connected

Algorithm for checking cycle in Graph.

1) Create the graph using the given number of edges and vertices.
2) Run a BFS from starting from any vertex along with the track of the parent.
3) Push vertex into queue and mark its parent as -1.
4) Run a loop while the queue is not empty.
5) Dequeue vertex from queue and add all its unvisited adjacent to queue and mark it visited.
6) For vertex ‘v’, if there is an adjacent ‘u’ such that u is already visited and u is not parent of v, then there is a cycle in the graph.

Algorithm for checking whether the graph is connected or not

1) After BFS, check if all the vertex is visited or not.
2) If all the vertices are visited then it is connected.

Time Complexity
O(V+E), where V is the number of vertices and E is the number of Edges.

 
Space Complexity
O(V+E), where V is the number of vertices and E is the number of Edges.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isCyclic(vector<vector<int>> &adj , vector<bool>& visited)
{
    vector<int> parent(adj.size(),-1);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while(!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        for(int i=0;i<adj[currentVertex].size();i++)
        {
            int neighbour = adj[currentVertex][i];
            if(!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour]=true;
                parent[neighbour] =currentVertex;
            }
            else if(parent[currentVertex]!=neighbour)
                return true;
        }
    }
    return false;
}
bool isTree(vector<vector<int>> &adj, int V)
{
    // Write your code here.
	vector<bool> visited(adj.size(), false);

    if (isCyclic(adj, visited))
    {
        return false;
    }

    for (bool val : visited)
    {
        if (!val)
        {
            return false;
        }
    }

    return true;
    
    
}

// Do not change this part of the code. You only need to complete the isTree function above.
int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v);

    for (int i = 0, a, b; i < e; ++i)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if (isTree(adj, v))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}
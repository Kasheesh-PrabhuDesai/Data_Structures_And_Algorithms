/*

You are given a graph with 'N' vertices numbered from '1' to 'N' and 'M' edges. You have 
to colour this graph in two different colours, say blue and red such that no two vertices 
connected by an edge are of the same colour. The given graph may have connected components.

Approach:

DFS
We can approach this problem by running a DFS starting from vertex-1.

We have a total of ‘m’ edges.

When can we achieve the configuration when we see in reference to vertex-1? 

Let's say vertex-1 is ‘Blue’
If all the vertices that connect to vertex-1 are ‘Red’, then we can say that the 
configuration is possible.
If this would be the negation of the last one. Say, vertex-1 is ‘Red’
If all the vertices that connect to vertex-1 are ‘Blue’, then we can say that the 
configuration is possible.
The above idea can be extended further in a Depth First manner to check the above 
condition on every vertex possible.

Time Complexity
O(E + V), Where E and V are the edges and vertices of the graph.

Space Complexity
O(E), Where E is the edges of the graphs. 

*/


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isPossible(vector<vector<int>> &adj, int curr, int parent, int currColour, vector<int> &colour)
{
    // Update the colour of curr
    colour[curr] = currColour;

    bool possible = true;

    // Traverse through all vertices connected with curr by an edge
    for (int i = 0; i < adj[curr].size(); i++)
    {
        // The variable next stores the i-th vertex connected with curr
        int next = adj[curr][i];

        // Colour of curr is equal to colour of next
        if (colour[next] == 0)
        {
            possible = (possible && isPossible(adj, next, curr, -1 * currColour, colour));
        }
        else if (next != parent && colour[next] == currColour)
        {
            return false;
        }
    }

    // Return the variable possible
    return possible;
}
int main()
{
	int n, m;
	cin >> n >> m;
	
    vector<vector<int>> mat(n+1);
    vector<int> colour(n+1, 0);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
        mat[u].push_back(v);
        mat[v].push_back(u);
	}
    
    bool possible = true;

    // Traverse through all vertices
    for (int i = 1; i <= n; ++i)
    {
        if (colour[i] == 0)
        {
            possible = (possible && isPossible(mat, i, -1, 1, colour));
        }
    }

    // Check if possible is equal to true
    if (possible)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }

    return 0;
    
}
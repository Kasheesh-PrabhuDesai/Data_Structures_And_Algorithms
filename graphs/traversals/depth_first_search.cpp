/*

You are given an adjacency list with a set of edges and vertices connecting the edges. You 
need to traverse the edges in a dept first traversal.

Approach:
Initialize a stack to store the edges. Declare an auxilary array with values of 0 and 1. A value
of 1 indicates that the edge has already been visited and need not be visited again. 
While the stack is not empty, traverse the vertexes one after the other. If the vertex visited
has neighbouring vertexes, then add the neigbouring vertexes to the stack. 

Time Complexity: O(N2)
Space Complexity: O(N)

*/

#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void depth_first_iterative(vector<vector<int>>& map_to_traverse)
{
    if(map_to_traverse.size()==0)
        return;
    
    stack<int> vertex;
    vector<int> isVisited(map_to_traverse.size()+1,0);

    vertex.push(map_to_traverse[0][0]);

    isVisited[map_to_traverse[0][0]]=1;

    while(!vertex.empty())
    {
        int currentVertex = vertex.top();
        vertex.pop();

        cout<<currentVertex<<" ";
        
        for(int i=0;i<map_to_traverse.size();i++)
        {
            int neighbour = map_to_traverse[i][1];
            bool neighbourVisited = isVisited[neighbour];
            if(map_to_traverse[i][0]==currentVertex && !neighbourVisited)
            {
                vertex.push(neighbour);
            }
        }

    }
}

void depth_first_recursive(vector<vector<int>> map_to_traverse, int currentVertex)
{
    vector<int> isVisited(map_to_traverse.size()+1,0);

    isVisited[currentVertex]=1;

    cout<<currentVertex<<" ";

    int neighbour = map_to_traverse[currentVertex][1];

    bool neighbourVisited = isVisited[neighbour];

    while(!neighbourVisited)
    {
        depth_first_recursive(map_to_traverse,neighbour);
    }
}

int main()
{
    vector<vector<int>> a  ={{0,1},{1,2},{2,3},{3,5},{4,3}};

    //depth_first_iterative(a);

    depth_first_recursive(a,0);

}




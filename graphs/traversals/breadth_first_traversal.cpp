/*

You are given a directed graph with a set of vertices V and the corresponding edges denoted by E.
You need to traverse the graph in a breadth first traversal method.

Time Complexity: O(V+E) where V is the number of vertices and E the number of edges
Space Complexity: O(V) where V is the total number of vertices

*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void breadth_first_traversal(vector<vector<int>>& map_to_traverse)
{
    if(map_to_traverse.size()==0)
        return;
    
    queue<int> vertex;
    vector<int> isVisited(map_to_traverse.size()+1,0);

    vertex.push(map_to_traverse[0][0]);

    isVisited[map_to_traverse[0][0]]=1;

    while(!vertex.empty())
    {
        int currentVertex = vertex.front();
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

int main()
{
    vector<vector<int>> a  ={{0,1},{1,2},{2,3},{3,5},{4,3}};

    //depth_first_iterative(a);

    breadth_first_traversal(a);

}
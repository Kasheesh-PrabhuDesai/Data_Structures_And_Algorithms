/*

You are given a 2d array/matrix with m number of rows and n number of columns. You need to 
traverse the 2d matrix in a DFS manner iteratively first and then recursively.

Approach:
1) Declare a stack to store the elements traversed.
2) Declare an auxilary array of boolean values which signifies whether the current indices have
already been previously visited.
3) Start of by visiting the first set of indices. Check if its adjacent vertices have already
been visited and add the non visited indices to the top of the stack to be visited next.
4) Follow the same procedure till the entire 2D matrix is traversed.


Time Complexity: O(M*N) where M is number of rows and N the number of cols
Space Complexity: O(M*N) where M is the number of rows

*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> dRow = { 0, 1, 0, -1 };
vector<int> dCol = { -1, 0, 1, 0 };

bool isValid(int row,int col,int row_limit,int col_limit,vector<vector<bool>>& visited)
{
    if(row<0 || row>=row_limit || col<0 || col>=col_limit || visited[row][col])
        return false;
    
    return true;
}


void dfsMatrixTraversal(vector<vector<int>>&mat)
{
    int row_limit = mat.size();
    int col_limit = mat[0].size();
    int totalSize = row_limit+col_limit;

    vector<vector<bool>> visited(row_limit,vector<bool>(col_limit,false));

    stack<pair<int,int>> st;

    st.push({0,0});

    while(!st.empty())
    {
        int currentRow = st.top().first;
        int currentCol = st.top().second;

        st.pop();

        if(!isValid(currentRow,currentCol,row_limit,col_limit,visited))
            continue;
        
        cout<<mat[currentRow][currentCol]<<" ";

        visited[currentRow][currentCol] = true;

        for(int i=0;i<4;i++)
        {
            int adjX = currentRow + dRow[i];
            int adjY = currentCol + dCol[i];
            st.push({adjX,adjY});
        }
    }
}



int main()
{
    vector<vector<int>> mat = {{ -1, 2, 3 },{ 0, 9, 8 },{ 1, 0, 1 }};

    dfsMatrixTraversal(mat);

    return 0;
}
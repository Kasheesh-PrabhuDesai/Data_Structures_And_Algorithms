/*

You have been given a non-empty grid consisting of only 0s and 1s. You have to find the 
maximum area of an island in the given grid.
An island is a group of 1s (representing land) connected horizontally, vertically or 
diagonally. You can assume that all four edges of the grid are surrounded by 0s 
(representing water). If there is no island present in the grid, then the maximum area is 0.

Approach:

The problem boils down to finding the area of each connected component in the grid, then taking the maximum 
of them. If we are on a land cell and explore every cell connected to it 8-directionally
(and recursively cells connected to those cells, and so on), then the total number of cells with land explored 
will be the area of that component. To ensure we don't count cell in the island more than once, we will mark 1
(land) as 0 during the recursion call.

Algorithm:

1) Define a function maxAreaofIsland to iterate over the entire grid. When a 1 is encountered, call the function
dfsArea to determine the max area of island.

2) In the dfsArea function, we first check if the indices are out of bound or if the value at the index is 0.
If the index is valid, then recursively find the area in 8 directions around the given index to get the max area

Time Complexity: O(N * M), Where ‘N’ is the number of rows in the given grid, and 'M' is the number of columns. 

Space Complexity: O(N * M), Where ‘N’ is the number of rows in the given grid, and 'M' is the number of columns. 

*/
#include <iostream>
#include <vector>

using namespace std;

bool isIsland(int val)
{
    if (val==1)
        return true;
    
    return false;
}

int dfsArea(vector<vector<int>>& grid,int row,int col,int row_limit,int col_limit)
{
    if(row< 0 || row>=row_limit || col < 0 || col >= col_limit || grid[row][col]==0)
    {
        return 0;
    }

    grid[row][col]==0;

    int area=1;

    int dir_vec[8][2] = {{-1,0},{0,-1},{1,0},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};

    for(int k=0;k<8;k++)
    {
        area+=dfsArea(grid,row+dir_vec[k][0],col+dir_vec[k][1],row_limit,col_limit);
    }

    return area;
}

int maxAreaofIsland(vector<vector<int>>& grid,int row_limit,int col_limit)
{
    int maxArea=0;

    for(int row=0;row<row_limit;row++)
    {
        for(int col=0;col<col_limit;col++)
        {
            if(grid[row][col]==1)
            {
                maxArea = max(maxArea,dfsArea(grid,row,col,row_limit,col_limit));
            }
        }
    }

    return maxArea
}

int main()
{
    vector<vector<int>> grid = {{0,0,1,1,0},{1,0,1,1,0},{0,1,0,0,0},{0,0,0,0,1}};

    int row_limit = grid.size();
    int col_limit = grid[0].size();

    cout<<row_limit<<" "<<col_limit<<endl;

    int maxArea = maxAreaofIsland(grid,row_limit,col_limit);

    cout<<"THE MAXIMUM AREA OF ISLAND IS: "<<maxArea<<endl;


}
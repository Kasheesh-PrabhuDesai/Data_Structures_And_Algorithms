/*
You are given a matrix 'MAT' of size ‘N’ * ‘M’, where ‘N’ is the number of rows and ‘M’ is 
the number of columns. Value ‘0’ in a cell represents that the cell is set on fire initially,
(at time t = ‘0’), and the cells which don’t have fire initially have value = ‘1’, and are 
called safe cells. If a cell is on fire, then in one second the fire will expand to its 
adjacent cells (left, right, top, bottom) if they are not already on fire. You are given the 
position of a person as integers ‘X’ and ‘Y’ denoting the cell (‘X’, ‘Y’). In one second the 
person can move from its current cell to any one of its adjacent cells, provided they are not 
on fire. You have to determine if the person can move through the matrix to one of the escape 
cells without burning himself i.e. without going through the fire cells. If it’s possible, 
return time taken, else return -1.

Note:
1. Escape cells in this problem are all such cells that lie on the edge of the matrix but 
not on the corner. i.e all such cells which are in the first row, first column, last row, 
and last column excluding the four corner cells are considered as valid escape cells.

2. A cell once set on fire continues to remain on fire till the end.

3. Note that rows are indexed from 0 to ‘N’ - 1 and columns are indexed from 0 to ‘M’ - 1.

4. The escape cells may also be initially on fire or can catch fire from some neighboring cell.


Approach: Multisource BFS
With each passing second fire expands and there are multiple cells at fire initially, (at time t = 0). So we will create an 
auxiliary matrix ‘TIME_OF_FIRE’ of size ‘N’ * ‘M’  to store the minimum time it will take for each cell to catch fire.

Iterate through the given matrix ‘MAT’ [][] and set ‘TIME_OF_FIRE’ [][] for a cell ( ‘i’, ‘j’ ) to 0, if ‘MAT’ [‘i’][‘j’]  = 0, 
(source of fire) because they are on fire from the beginning only.

Fire will expand in four directions(up, down, left, right) from the fired cell and will continue to do so until all the cells 
are set to fire. A better choice is to use multisource BFS to store all the values of the matrix ‘TIME _OF_FIRE’ [][] for each 
cell in the matrix. 

The steps are as follows:

1) Initialise a ‘VISITED’ 2D array of type boolean and mark all cells to false.
2) Those cells which are set to 0 in ‘MAT’[][], push them into a queue and mark them as visited. Also set every cell’s 
‘TIME_OF_FIRE’ = ‘TIMER’. ‘TIMER’ acts as clock time.
3) Multi-source BFS works level by level from each of its source nodes. After each second, source nodes will change. Thus when 
pushing any cell in the queue the minimum time for this cell to catch fire will be the minimum time taken by its parent + 1. 
Here the children nodes will be nothing but the adjacent cells.
4) The next step is to find if the person can reach an escape cell and if yes the minimum time it will take for him to get out 
of it without being burnt.
5) To solve this problem, initialise ‘TIMER’ = 0, and do BFS from the initial cell of the person (X, Y).
How to choose, if the next cell will be possible to be visited by the person? To identify this use ‘TIMER’ + 1. If ‘TIMER’ + 1
is less than ‘TIME_OF_FIRE’ of the cell to be visited next, then that cell is possible to be visited safely, otherwise the 
person will get burnt. So in each iteration insert only those cells in the queue for which ‘TIMER’ + 1 is less than 
‘TIME_OF_FIRE’.
6) To identify if the person has reached escape cells via BFS, there can be these two conditions for escape cells:
Either row  = 0 or row  = ‘N’ - 1:
Either col >= 1 or col <= ‘M’ - 1.
Either col = 0 or col = ‘M’ - 1:
Either row >= 1 or row <= ‘N’ - 1.
7) If the person escapes, then return timer value, else return -1.

Time Complexity: O(N*M), where ‘N’ is the number of rows and ‘M’ is the number of columns in the given matrix.

Space Complexity: O(N*M), where ‘N’ is the number of rows and ‘M’ is the number of columns in the given matrix.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <climits>
#include <map>

using namespace std;

// funciton to check if the current indices are out of bounds of the row and col limit
bool isValid(int curX,int curY, int dX, int dY, int row_limit, int col_limit)
{
    return ((curX+dX >=0 && curX+dX<row_limit) && (curY+dY>=0 && curY+dY<col_limit));
}

//function to check if the current cell at given index is an escape cell

bool isEscapeCell(int curX,int curY, int row_limit,int col_limit)
{
    return (curX==0 && (curY >=1 && curY<col_limit-1) || (curX==row_limit-1 && (curY>=1 && curY<col_limit-1))
            || (curY==0 && (curX>=1 && curX <row_limit-1)) || (curY==col_limit-1 && (curX>=1 && curX<row_limit-1)));
}

int fireInTheCells(vector<vector<int>> &mat, int n, int m, int x, int y){
    // 2D Array to store minimum time in which each point catches fire.
    vector<vector<int>> timeOfFire(n, vector<int>(m, 0));

    // 2D Array to store visited or not during the BFS.
    vector<vector<bool>> vis(n + 2, vector<bool>(m + 2, false));

    // Queue for performing multiSource BFS.
    queue<pair<int, int>> q;

    for (int i = 0; i < n; i++){

        for (int j = 0; j < m; j++){

            if (mat[i][j] == 0){

                 // Each point which is source of fire is enqueued.
                 q.push({i,j});
                 timeOfFire[i][j] = 0;
                 vis[i][j] = true;
            }
        }
    }

    // Array used to represent up,down,right,left moves.
    int x1[5] = {0, 1, 0, -1, 0};
    
    // Intially time is taken to be 1 unit.
    int timer = 1; 

    while (!q.empty()){

        int sz = q.size();

        for (int i = 0; i < sz; i++){

            auto cur = q.front();
            q.pop();

            // Going left,right,up,down from the 'cur' point.
            for (int i = 0; i < 4; i++){
                 
                int dx = x1[i];
                int dy = x1[i + 1];

                if (isValid(cur.first, cur.second, dx, dy, n, m)){

                    if (mat[cur.first + dx][cur.second + dy] == 1 && !vis[cur.first + dx][cur.second + dy] ){

                        vis[cur.first + dx][cur.second + dy] = true;
                        timeOfFire[cur.first + dx][cur.second + dy] = timer;
                        q.push({cur.first + dx,cur.second + dy});
                    }
                }
            }
        }

        // After discovering points of each level time increases/increment.
        timer++;
    }

    bool possible = false;
    timer = 0;

    // Pushing position.
    q.push({x, y}); 
    mat[x][y] = 0;

    // Another BFS to check if person can survive or not.
    while (!q.empty()){ 
        int sz = q.size();

        for (int i = 0; i < sz; i++){

            auto cur = q.front();
            q.pop();

            // Used to check if current cell is the escape cell.
            if (isEscapeCell(cur.first, cur.second, n, m)){

                possible = true;
                break;
            }

            for (int i = 0; i < 4; i++){

                int dx = x1[i];
                int dy = x1[i + 1];
                int nextx = cur.first + dx;
                int nexty = cur.second + dy;

                if (nextx >= 0 && nextx < n && nexty >= 0 && nexty < m && mat[nextx][nexty] == 1){

                    /*
                        Condition to check if the current point we are 
                        moving to is free of fire at that time or not.
                    */
                    if ((timer + 1) < timeOfFire[nextx][nexty]){

                        q.push({nextx, nexty});
                        mat[nextx][nexty] = 0;
                    }
                }
            }
        }
        if (possible){
            break;
        }

        timer++;
    }

    // If possible is false that means the person cannot escape.
    if (!possible){
        return -1;
    }

    else{
        return timer;
    }
}

int main()
{
    vector<vector<int>> mat = {{0,1,1,1},{1,0,1,1},{1,1,1,1},{0,1,1,1},{0,0,0,0}};

    int row = mat.size();
    int col = mat[0].size();

    int x=1,y=2;

    cout<<fireInTheCells(mat,row,col,x,y)<<endl;

    return 0;
}



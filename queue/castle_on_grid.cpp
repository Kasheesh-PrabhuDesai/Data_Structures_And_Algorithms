/*
You are given a square grid with some cells open (.) and some blocked (X). Your playing piece can move along any row or column until it reaches the edge of the grid or a blocked cell. Given a grid, a start and a goal, determine the minmum number of moves to get to the goal.
Example.
The grid is shown below:

...
.X.
...
The starting position is (0,0) so start in the top left corner. The goal is (1,2).
 The path is (0,0)->(0,2)->(1,2) . It takes 2 moves to reach the goal.

Function Description
Complete the minimumMoves function in the editor.

minimumMoves has the following parameter(s):

string grid[n]: an array of strings that represent the rows of the grid
int startX: starting X coordinate
int startY: starting Y coordinate
int goalX: ending X coordinate
int goalY: ending Y coordinate
Returns

int: the minimum moves to reach the goal
Input Format

The first line contains an integer , the size of the array grid.
Each of the next  lines contains a string of length .
The last line contains four space-separated integers, 

Constraints
 1<=n<=100
 0<=startX, startY, goalX, goalY<=n

Sample Input

STDIN       FUNCTION
-----       --------
3           grid[] size n = 3
.X.         grid = ['.X.','.X.', '...']
.X.
...
0 0 0 2     startX = 0, startY = 0, goalX = 0, goalY = 2
Sample Output

3
Explanation

Here is a path that one could follow in order to reach the destination in  steps:
(0,0) -> (2,0) -> (2,2) -> (0,2) */

//#############################################################################################################//


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
using namespace std;

// -1 for break; 0 for continue; 1 for OK
int func(vector<vector<char>>& vlist, deque<int>& pst, vector<vector<int>>& visited, int tx, int ty, int x1, int y1)
 {
    int n = vlist.size();
    
    if(tx < 0 || tx >= n || ty < 0 || ty >= n)
        return -1;
    
    if(vlist[tx][ty] == 'X')
          return -1;

    if(visited[tx][ty] == 1)
        return 0;
    visited[tx][ty] = 1;
    
    pst.push_back(tx  + ty *n);
    if(tx == x1 && ty == y1)
        return 1;
    
    return 0;
}   

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
   
    int n;
    cin >> n;
    

    vector<vector<char>> vlist;
    vector<vector<int>> vvst;
    vlist.resize(n);
    vvst.resize(n);
    
    for(int i = 0; i < n; i ++)
    {
        for(int j =0; j < n; j ++)
        {
            char c;
            cin >> c;
            vlist[i].push_back(c);
            vvst[i].push_back(0);
        }    
    }    
    
    int x0, y0, x1, y1;
    cin >> x0 >> y0 >> x1 >> y1;  
    
    deque<int> pst;
    pst.push_back(x0 + n * y0);
    int level = 0;
    
    bool found = false;
    deque<int> tempst;
    
    while(true)
    {
        if(pst.empty())
        {
            pst = tempst;
            tempst.clear();
         }
        if(pst.empty() || found)
            break;
        level ++;
        while(!pst.empty())
        {
            if(found)
                break;          

            int v = pst.front();
            pst.pop_front();

            int tx = v % n;
            int ty = v / n;

            for(int k = tx - 1; k >=0; k --)
            {
                int rn = func(vlist, tempst, vvst, k, ty, x1, y1);
                if(rn == -1)
                    break;
                else if(rn == 1)
                 {
                    found = true;
                    break;
                  }               
            }
             for(int k = tx + 1; k < n; k ++)
            {
                int rn = func(vlist, tempst, vvst, k, ty, x1, y1);
                if(rn == -1)
                    break;
                else if(rn == 1)
                 {
                    found = true;
                    break;
                  }               
            }

            for(int k = ty - 1; k >=0; k --)
            {
                int rn = func(vlist, tempst, vvst, tx, k, x1, y1);
                if(rn == -1)
                    break;
                else if(rn == 1)
                 {
                    found = true;
                    break;
                  }               
            }
            for(int k = ty + 1; k < n; k ++)
            {
                int rn = func(vlist, tempst, vvst, tx, k, x1, y1);
                if(rn == -1)
                    break;
                else if(rn == 1)
                 {
                    found = true;
                    break;
                  }               
            }
        }    
    }
    cout << level << endl;
    return 0;
}

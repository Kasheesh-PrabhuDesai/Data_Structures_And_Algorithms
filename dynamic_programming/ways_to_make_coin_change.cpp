/*

You are given a vector array of distinct positive integers representing coin 
denominations and a single positive integer n representing the target amount of money.
Write a program to calculate the total number of ways the target amount can be achieved
using the vector array of coin denominations.

Approach:

1) Initialise a vector array say 'ways' of size N+1 where N is the target amount to 
be achieved.
2) Declare ways[0]=1 as the target amount 0 can be achieved only in 1 way i.e. without
any coins.
3) Using two nested for loops, iterate through the entire array of denominations.
At each index compare the value of denomination to value of the pointer in the ways 
vector. 
4) As long as the value of the denom is less than or equal to value of second pointer,
store the value as ways[secondPointer]+=ways[secondPointer - denomValue]
5) Return ways[n]

Time Complexity: O(ND) Where N is the size of the array created and D is number of denoms

Space Complexity: O(N) where N is the size of the auxilary array created

*/

#include <vector>
#include <iostream>

using namespace std;

//function to calculate the number of ways the target amount can be achieved
int numberOfWaysToMakeChange(int n, vector<int> denoms) {
	vector<int> ways(n+1,0); // aux vector array to store the number of ways a target amount can be achieved
	ways[0]=1; // the target amount of 0 can be achieved in only 1 way

    //iterate through the entire denoms array. if the value of denom is less than the value of j, change the number of ways of achieving the amount at index j
	for(int i=0;i<denoms.size();i++)
	{
		for(int j=1;j<ways.size();j++)
		{
			if(denoms[i]<=j)
			{
				ways[j]+=ways[j-denoms[i]];
			}
		}
	}
  return ways[n];
}

int main()
{
    int n = 10;
    vector<int> denoms = {1,5,10,25};

    cout<<numberOfWaysToMakeChange(n,denoms)<<endl;

    return 0;
}

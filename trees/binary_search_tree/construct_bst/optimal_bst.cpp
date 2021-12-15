/*

Given a sorted array of keys of BST and an array of frequency counts of each key 
in the same order as in the given inorder traversal. The frequency of an element 
is the number of searches made to that element. Construct a binary search tree 
from the given keys such that the total cost of all the searches is minimum.

Cost of searching a key is its frequency multiplied by its level number in the BST.

Approach:

1) Create a helper function ‘optimalCostHelper’ to find the minimum cost to construct a bst.
2) Call this helper function by passing the keys, frequencies, starting and the ending index of the keys in consideration, and level/depth of the current root.

Algorithm for optimalCostHelper(keys, frequencies, startIdx, endIdx, curLevel):

1) If we have checked for all the nodes, return 0.
2) Initialise an integer variable ‘minimumCost’ by the maximum positive value.
3) Run a loop from startIdx to endIdx:
- Consider the current node as the root node.
- Recursively find the optimal cost of left and right subtree. The level of a child node is 1 + the level of the parent node i.e 1 + curLevel.
- Now, current’s node cost is the sum of product of its frequency and level, optimal cost for left subtree and optimal cost for right subtree.
- this cost is less than the ‘minimumCost’, update ‘minimumCost’.
4)Return the minimum cost to construct the binary search tree.

Time Complexity: O(N^3)
Space Complexity: O(N)

*/

/*

	Time Complexity: O(3 ^ N) 
	Space Complexity: O(N)

	where N is the number of keys. 

*/


#include<climits>
#include <iostream>
#include <vector>

using namespace std;

int optimalCostHelper(vector<int>& keys, vector<int> &freq, int startIdx, int endIdx, int curLevel)
{
	// Base condition
	if(startIdx > endIdx)
	{
		return 0;
	}

	int minimumCost = INT_MAX; 

	for(int i = startIdx; i <= endIdx; i++)
	{
		// Recursively find the optimal cost for left subtree
		int leftMinimumCost = optimalCostHelper(keys, freq, startIdx, i - 1, curLevel + 1); 

		// Recursively find the optimal cost for right subtree
		int rightMinimumCost = optimalCostHelper(keys, freq, i + 1, endIdx, curLevel + 1); 

		// Current's node cost
		int currentCost = (freq[i] * curLevel) + leftMinimumCost + rightMinimumCost;

		// Update minimum cost 
		if(currentCost < minimumCost)
		{
			minimumCost = currentCost;
		}
	}
	// Return the optimal cost
	return minimumCost;
}

int optimalCost(vector<int>& keys, vector<int>& freq, int n)
{
	return optimalCostHelper(keys, freq, 0, n - 1, 1);
}


int main()
{
    vector<int> keys = {1,2,3,4,5};
    vector<int> freq = {10,30,2,4,5};

    cout<<optimalCost(keys,freq,keys.size())<<endl;

    return 0;
}
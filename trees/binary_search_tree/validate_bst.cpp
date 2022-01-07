/*

Given a potentially invalid BST, write the function in order to test the validity of the given BST.

Approach:

1) Simple recurisve approach to test whether at each point the node value satisfies the following criteria
i) root->value > root->left->value and root->value >= root->right->value;

2) If all the nodes satisfy the above given condition, the given BST is valid.

Time Complexity: O(N) where N is the depth of the tree
Space Complexity: O(N) where N is the depth of the tree

*/

#include <iostream>
#include <climits>

using namespace std;

class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val)
  {
      value=val;
      left=NULL;
      right=NULL;
  };
  BST &insert(int val);
};

bool validateBstHelper(BST *tree,int minValue,int maxValue)
{
	if(tree->value < minValue || tree->value >=maxValue)
	{
		return false;
	}
	if(tree->left!=nullptr && !validateBstHelper(tree->left,minValue,tree->value)){
		return false;
	}
	if(tree->right!=nullptr && !validateBstHelper(tree->right,tree->value,maxValue))
	{
		return false;
	}
	return true;
}

bool validateBst(BST *tree) {
	return validateBstHelper(tree,INT_MIN,INT_MAX);
	
}

int main()
{
    BST *tree = new BST(10);
    tree->left = new BST(5);
    tree->left->left = new BST(6);
    tree->right = new BST(8);

    cout<<validateBst(tree)<<endl;
    
}

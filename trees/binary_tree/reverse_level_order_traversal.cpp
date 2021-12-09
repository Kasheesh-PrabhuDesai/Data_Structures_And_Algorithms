/* 
You are given a binary tree of integers. Return the reverse of level order traversal

The idea behind this solution is to use a queue data structure to store the level order
traversal. A vector will be storing the root value as the tree is traversed in level order.
Since the reverse level order is required, the vector is then reversed to obtain the reverse
level order traversal of the tree.

Time Complexity: O(D) where D is the depth of the tree
Space Complexity: O(N) where N are the total number of nodes in the binary tree
  
*/

#include <algorithm>
#include<queue>
#include <vector>
using namespace std;


template <typename T>

class TreeNode {
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;
    TreeNode(T val) {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};


vector<int> reverseLevelOrder(TreeNode<int> *root){


    vector<int> reverseOrder{};
    queue<TreeNode<int>*> q;
    if(root==NULL)
        return {};
    
	q.push(root);
    
    while(!q.empty())
    {
        TreeNode<int>* removedNode = q.front();
        q.pop();
        reverseOrder.push_back(removedNode->val);
        
        if(removedNode->left!=NULL)
            q.push(removedNode->left);
        if(removedNode->right!=NULL)
            q.push(removedNode->right);
    }
    
    reverse(reverseOrder.begin(),reverseOrder.end());
    
    return reverseOrder;
}



int main()
{
    TreeNode<int> T(-1);


}

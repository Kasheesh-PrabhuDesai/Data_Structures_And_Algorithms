/* 
You are given a binary tree of integers. Return the reverse of level order traversal

The idea behind this solution is to use a queue data structure to store the level order
traversal. A vector will be storing the root value as the tree is traversed in level order.
Since the reverse level order is required, the vector is then reversed to obtain the reverse
level order traversal of the tree.

Time Complexity: O(D) where D is the depth of the tree
Space Complexity: O(N) where N are the total number of nodes in the binary tree

*/
#include<iostream>
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


TreeNode<int>* buildtree(){
  int d;
  cin>>d;
  TreeNode<int>* root;
  if(d==-1){
    return NULL;
  }
  root = new TreeNode<int>(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}

void print(vector<int> reverseOrder){
    for(auto i:reverseOrder)
        cout<<i<<" ";
    cout<<endl;
}


int main()
{
    /*
                    1
                   2 3
                 4 -1 5 6
             -1 7 -1 -1 -1 -1
                  -1 -1
    
    -1 indicates a null value.

    */

   TreeNode<int>* T = buildtree();
   
   vector<int> result = reverseLevelOrder(T);

   print(result);

}

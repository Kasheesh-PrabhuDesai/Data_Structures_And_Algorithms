/*
You have been given a binary tree of integers. Your task is to print the boundary nodes 
of this binary tree in Anti-Clockwise direction starting from the root node.

Idea here is to subdivide the problem into three parts

1) Traverse Left Boundary and append the root values to the vector. The leaf nodes will
not be traversed as this is covered in the next part. Traversal is done in preorder as a 
top down order is required.

2) Traverse the leaf nodes and add the value to the vector. This traversal is done in inorder
fashion.

3) Traverse Right Boundary except the leaf nodes as the leaf nodes were already traversed in 
part 2. Traversal is carried out is postorder fashion to achieve down up order.

Time Complexity: O(N) where N is number of nodes in the tree

Space Complexity: O(N) where N is number of nodes in the tree


*/

#include<iostream>
#include<vector>

using namespace std;



template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

void traverseLeftBoundary(TreeNode<int>* root,vector<int>& boundary)
{
    if(root==NULL || (root->left==nullptr && root->right==nullptr))
    {
       return;
    }
    
    boundary.push_back(root->data);
    
	if(root->left!=NULL)
    {
        traverseLeftBoundary(root->left,boundary);
    }
    else
    {
        traverseLeftBoundary(root->right,boundary);
    }
}
void traverseRightBoundary(TreeNode<int>* root,vector<int>& boundary)
{
    if(root==NULL || (root->left==nullptr && root->right==nullptr))
    {
        return;
    }
    
	if(root->right!=NULL)
    {
        traverseRightBoundary(root->right,boundary);
    }
    else
    {
        traverseRightBoundary(root->left,boundary);
    }
    boundary.push_back(root->data);
}
void traverseLeaves(TreeNode<int>* root,vector<int>& boundary)
{
    if (root==NULL)
        return;
   	
    if(root->left==nullptr && root->right==nullptr)
    {
        boundary.push_back(root->data);
    	return;
    }
    
    traverseLeaves(root->left,boundary);
    traverseLeaves(root->right,boundary);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> boundary;
	
    if(root==NULL)
    {
        return boundary;
    }
        
    boundary.push_back(root->data);
    
    traverseLeftBoundary(root->left,boundary);
    
	traverseLeaves(root->left,boundary);
    traverseLeaves(root->right,boundary);
    
    traverseRightBoundary(root->right,boundary);
    
    return boundary;
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

void print(vector<int>& boundary){
    for(auto i:boundary)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    /*
                    2
        1 2 3 4 -1 5 -1 -1 -1 -1 -1
          1 2 -1 3 -1 4 -1 -1 -1
    
    -1 indicates a null value.

    */

   TreeNode<int>* T = buildtree();
   
   vector<int> result = traverseBoundary(T);

   print(result);

}


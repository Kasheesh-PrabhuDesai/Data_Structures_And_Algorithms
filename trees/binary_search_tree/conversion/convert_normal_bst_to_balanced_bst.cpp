/*

You have been given a binary search tree of integers with ‘N’ nodes. Your task is to convert 
it into a balanced BST with the minimum height possible.

A binary search tree (BST) is a binary tree data structure that has the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.

A Balanced BST is defined as a BST, in which the height of two subtrees of every node differs 
no more than 1.

Approach:

Idea is to first perform inorder traversal to obtain a sorted array. Then perform preorder
traversal using sorted array. At each recursion, change the value of root to the value of mid
of the sorted array. Use two indices start and end. For left subtree change end to mid-1 and 
for right subtree change start to mid+1.

Time Complexity  : O(N)
Space Complexity : O(N)
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
class TreeNode
{
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
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

void inorder(TreeNode<int>* root, vector<int>& nodes)
{
    if(root==NULL)
        return;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}
TreeNode<int>* convertToBalancedBST(vector<int>& nodes, int start, int end)
{
	if(start>end)
        return NULL;
    
    int mid = (start+end)/2;
	TreeNode<int>* root = new TreeNode<int>(nodes[mid]);
    root->left = convertToBalancedBST(nodes,start,mid-1);
    root->right = convertToBalancedBST(nodes,mid+1,end);
    
    return root;
    
}
TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int> nodes;
    
    inorder(root,nodes);
    
    int n = nodes.size();

    return convertToBalancedBST(nodes,0,n-1);
}

void print_level_order(TreeNode<int>* root)
{
    if(root==NULL)
        cout<<"BYE BYE";
    
    queue<TreeNode<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* current = q.front();

        cout<<current->data<<" ";

        if(current->left)
        {
            q.push(current->left);
        }
        if(current->right)
        {
            q.push(current->right);
        }
        q.pop();
    }
}

int main()
{
    TreeNode<int>* root = new TreeNode<int>(10);
    root->left = new TreeNode<int>(6);
    root->left->left = new TreeNode<int>(4);

    TreeNode<int>* result = balancedBst(root);

    print_level_order(result);
}

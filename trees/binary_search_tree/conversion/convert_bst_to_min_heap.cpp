/*

You are given a 'ROOT' of a binary search tree of integers. 
The given BST is also a complete binary tree.
Your task is to convert the given binary search tree into a Min Heap and print the preorder 
traversal of the updated binary search tree.

Approach:
Idea is to first perform an inorder traversal of the given BST. Store the result in an array.
The result is a sorted array. Now, perform a preorder traversal of the binary search tree and
replace root data with elements of sorted array to achieve a Min heap.

Time Complexity: O(N)
Space Complexity: O(N)

*/
#include<iostream>
#include<vector>

using namespace std;

class BinaryTreeNode {
    
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data) {
    this -> left = NULL;
    this -> right = NULL;
    this -> data = data;
    }
};

void inOrder(BinaryTreeNode* root, vector<int>& io)
{
    if(root==NULL)
        return;
    
    inOrder(root->left,io);
    io.push_back(root->data);
    inOrder(root->right,io);
}

void convertToHeap(BinaryTreeNode* root,vector<int> io, int* idx)
{
    if(root==NULL)
        return;
    root->data = io[++*idx];
    convertToHeap(root->left,io,idx);
    convertToHeap(root->right,io,idx);

}
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
	if(root==NULL)
        return root;
    
    vector<int> io;
        
    inOrder(root,io);
    
    int index=-1;
    
    convertToHeap(root,io,&index);
    
    return root;
}

void print_preorder(BinaryTreeNode* root)
{
    if(root==NULL)
        return;
    
    cout<<root->data<<" ";
    print_preorder(root->left);
    print_preorder(root->right);
}

int main()
{
    BinaryTreeNode* root = new BinaryTreeNode(8);
    root->left = new BinaryTreeNode(5);
    root->left->left = new BinaryTreeNode(2);
    root->left->right = new BinaryTreeNode(6);
    root->right =new BinaryTreeNode(10);
    root->right->left = new BinaryTreeNode(7);
    
   root =  convertBST(root);
    
    print_preorder(root);
}
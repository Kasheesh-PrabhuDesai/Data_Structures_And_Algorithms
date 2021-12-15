/*

You are given a binary tree. You have to modify the given binary tree in place to achieve a 
Binary search tree.

Approach:

Perform inorder traversal of binary tree. Sort the array. An inorder traversal of a BST results
in a sorted array. Now since we already have the sorted array, perform an inorder traversal of
the binary tree and replace the value with the value at each index in the sorted array.

Time Complexity: O(NLogN)
Space Complexity: O(N)

*/

#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>

class BinaryTreeNode
{
public :
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};



void inOrderTraversal(BinaryTreeNode<int>* root,vector<int>& ioa)
{
    if(root==NULL)
        return;
    
    inOrderTraversal(root->left,ioa);
    ioa.push_back(root->data);
    inOrderTraversal(root->right,ioa);
    
}
void convertTobst(BinaryTreeNode<int>* root,vector<int>& ioa,int& i)
{
	if(root==NULL)
        return;
    
    convertTobst(root->left,ioa,i);
    
    root->data =ioa[i];
    i++;
    
    convertTobst(root->right,ioa,i);
}
BinaryTreeNode<int>* binaryTreeToBst(BinaryTreeNode<int>* root)
{
    // Write your code here
    if(root==NULL)
        return root;
    
	vector<int> ioa;
    
    inOrderTraversal(root,ioa);
    
    sort(ioa.begin(),ioa.end());
    
    int i=0;
    
	convertTobst(root,ioa,i);

    return root;
}

void inorder_print(BinaryTreeNode<int>* root)
{
    if (root==NULL)
        return;
    
    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
}

int main()
{
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(5);

    root->left = new BinaryTreeNode<int>(6);
    root->left->left = new BinaryTreeNode<int>(2);
    root->left->right = new BinaryTreeNode<int>(3);

    root->right = new BinaryTreeNode<int>(10);
    root->right->right = new BinaryTreeNode<int>(9);

    inorder_print(root);

    binaryTreeToBst(root);

    cout<<endl;

    inorder_print(root);
}

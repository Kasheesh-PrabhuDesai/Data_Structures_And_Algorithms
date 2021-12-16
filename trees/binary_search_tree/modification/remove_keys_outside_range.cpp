/*

Given a Binary Search Tree (BST) and a range [min, max], remove all keys which are outside 
the given range. The resultant tree should also be BST. Return the root of the resultant BST.

Approach:
Similar to the mergin of two bst, first perform inorder traversal of the BST to get a sorted
array. Removes elements from the array which are outside the range. Perform an preorder traversal
on the binary tree and modify root data with the elements from the sorted array.

Time Complexity: O(N)
Space Complexity: O(N)

*/

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

template<typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(BinaryTreeNode<int>* root,vector<int>& nodes)
{
    if(root==NULL)
        return;
    
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
    
}

vector<int> inRange(vector<int>& nodes,int min,int max)
{
    vector<int> range_nodes;
    for(int i=0;i<nodes.size();i++)
    {
        if(nodes[i]>=min && nodes[i]<=max)
        {
            range_nodes.push_back(nodes[i]);
        }
    }
    
    return range_nodes;
}

BinaryTreeNode<int>* convertToBST(vector<int>& nodes,int start,int end)
{
    if(start>end)
        return NULL;
   	
    int mid = (start+end)/2;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(nodes[mid]);
    root->left = convertToBST(nodes,start,mid-1);
    root->right = convertToBST(nodes,mid+1,end);
    
    return root;
}

BinaryTreeNode<int>* removeOutsideRange(BinaryTreeNode<int>* root,int min,int max)
{
    vector<int> nodes,r;
    
    inorder(root,nodes);
    
    r = inRange(nodes,min,max);
    
    int n = r.size();
    
    return convertToBST(r,0,n-1);
}

void print_level_order(BinaryTreeNode<int>* root)
{
    if(root==NULL)
        cout<<"BYE BYE";
    
    queue<BinaryTreeNode<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int>* current = q.front();

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
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(9);
    root->left = new BinaryTreeNode<int>(-10);
    root->left->right = new BinaryTreeNode<int>(-5);
    root->right = new BinaryTreeNode<int>(17);
    root->right->left = new BinaryTreeNode<int>(16);
    root->right->left->left = new BinaryTreeNode<int>(10);
    root->right->right = new BinaryTreeNode<int>(18);

    root = removeOutsideRange(root,-7,16);

    print_level_order(root);
}
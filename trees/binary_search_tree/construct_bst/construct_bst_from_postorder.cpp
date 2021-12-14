/* 

You are given an array of integers representing the postorder traversal sequence.
Construct a binary search tree from the given array.

Approach:
Declare a variable to store the preorder index. Declare two variables storing the minVal and
maxVal possible. Initialize currentVal to be thevalue of the element in the preorder array.
If currentVal is less than minVal or greater than maxVal, then return NULL. Else set the 
value as root. Increment preorder index by 1.Change value of minval to currentVal+1 and 
maxval to currentVal-1.

Time Complexity: O(N) where N is the length of the array
Space Comlexity: O(N) where N is the length of the array

*/

#include <iostream>
#include<queue>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class BinarySearchTree
{
    public:
    T val;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

    BinarySearchTree(T val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinarySearchTree()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

BinarySearchTree<int>* constructBST(vector<int>& po,int preIdx,int minVal,int maxVal)
{
    if(preIdx < 0)
        return NULL;
    
    int currentVal = po[preIdx];

    BinarySearchTree<int>* root = NULL;

    if (currentVal > minVal && currentVal < maxVal)
    {
        
        root = new BinarySearchTree<int>(currentVal);

        preIdx-=1;

        if(preIdx>=0)
        {
            root->left = constructBST(po,preIdx,INT_MIN,currentVal);
        }
        if(preIdx>=0)
        {
            root->right = constructBST(po,preIdx,currentVal,INT_MAX);  
        }


    }


    return root;

}

void printpostOrder(BinarySearchTree<int>* root)
{
    if (root==NULL)
        return;
    
    if(root->left!=NULL)
        printpostOrder(root->left);
    if(root->right!=NULL)
        printpostOrder(root->right);
    
    cout<<root->val<<" ";


}


int main()
{
    vector<int> po = {5, 13, 15, 10, 30, 42, 35, 20};

    BinarySearchTree<int>* root = NULL;

    root = constructBST(po,po.size()-1,INT_MIN,INT_MAX);

    printpostOrder(root);
}
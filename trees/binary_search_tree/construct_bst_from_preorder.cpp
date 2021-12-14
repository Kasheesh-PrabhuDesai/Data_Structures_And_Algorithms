/* 

You are given an array of integers representing the preorder traversal sequence.
Construct a binary search tree from the given array.

Approach:
Decalre a variable to store the preorder index. Declare two variables storing the minVal and
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

BinarySearchTree<int>* constructBST(vector<int>& pr,int preIdx,int minVal,int maxVal)
{
    if(preIdx >= pr.size())
        return NULL;
    
    int currentVal = pr[preIdx];

    BinarySearchTree<int>* root = NULL;

    if (currentVal > minVal && currentVal < maxVal)
    {
        
        root = new BinarySearchTree<int>(currentVal);

        preIdx+=1;

        if(preIdx<pr.size())
        {
            root->left = constructBST(pr,preIdx,INT_MIN,currentVal);
        }
        if(preIdx<pr.size())
        {
            root->right = constructBST(pr,preIdx,currentVal,INT_MAX);  
        }


    }


    return root;

}

void printpreOrder(BinarySearchTree<int>* root)
{
    if (root==NULL)
        return;
    
    cout<<root->val<<" ";

    if(root->left!=NULL)
        printpreOrder(root->left);
    if(root->right!=NULL)
        printpreOrder(root->right);


}


int main()
{
    vector<int> pre = {20, 10, 5, 15, 13, 35, 30, 42};

    BinarySearchTree<int>* root = NULL;

    root = constructBST(pre,0,INT_MIN,INT_MAX);

    printpreOrder(root);
}
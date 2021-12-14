/* 

You are given an array of integers representing level order traversal.
Construct a binary search tree from the given array.

Approach:
Start with the first element of array. If tree has no root, than set the first element as root.
Traverse the remaining elements in the array, while comparing the value of each element to the
value of the root. If value is less insert in left, else insert in right;

Time Complexity: O(N^2) where N is the length of the array
Space Comlexity: O(N) where N is the length of the array

*/

#include <iostream>
#include<queue>
#include <vector>

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

BinarySearchTree<int>* insertValue(BinarySearchTree<int>* root,int val)
{
    if(root==NULL)
    {
        root = new BinarySearchTree<int>(val);
        //return root;
    }

    else if(val<root->val)
    {
        root->left = insertValue(root->left,val);
    }

    else
    {
        root->right = insertValue(root->right,val);
    }

    return root;
}

void printLevelOrder(BinarySearchTree<int>* root)
{
    if (root==NULL)
        return;
    
    queue<BinarySearchTree<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        BinarySearchTree<int>* current = q.front();

        cout<<current->val<<" ";

        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        
        if(current->right!=NULL)
        {
            q.push(current->right);
        }

        q.pop();

    }


}


int main()
{
    vector<int> a = {5,3,6,2,4,7};

    BinarySearchTree<int>* root = NULL;

    for(int i=0;i<a.size();i++)
    {
        root = insertValue(root,a[i]);
    }

    printLevelOrder(root);
}
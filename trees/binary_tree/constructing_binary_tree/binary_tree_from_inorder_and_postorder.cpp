/*

You are given two vectors. The first vector is the sequence obtained from postorder traversal of a
binary tree. The second is the sequence obtained from inorder traversal of a binary tree.
You have to construct a binary tree from these two sequences.

Approach:

Create a helper function that will use recursion to build the binary tree. The input to this
function will be the inorder sequence, postorder sequence , inorder startand inorder end.

Time Complexity: O(N*2)
Space Complexity: O(N*2)


*/

#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class BinaryTree
{
    public:
    T val;
    BinaryTree<T>* left;
    BinaryTree<T>* right;

    BinaryTree(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }

    ~BinaryTree()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

int search(vector<int>& in,int inS,int inE, int val)
{
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==val)
            return i;
    }    
    return -1;
}


BinaryTree<int>* buildtreeHelper(vector<int>& po,vector<int>& in,int inS, int inE)
{
    static int idx= po.size()-1;
    if(inS>inE)
        return NULL;
    
    int root_data = po[idx];
    idx--;

    BinaryTree<int>* root = new BinaryTree<int>(root_data);


    if(inS==inE)
    {
        return root;
    }

    int pos = search(in,inS,inE,root_data);


    root->right = buildtreeHelper(po,in,pos+1,inE);
    root->left = buildtreeHelper(po,in,inS,pos-1);


    return root;

    
}

BinaryTree<int>* buildtree(vector<int>& po, vector<int>& in, int size)
{
    return buildtreeHelper(po,in,0,size-1);
}

void inOrder(BinaryTree<int>* root)
{
    if (root==NULL)
        return;
    
    inOrder(root->left);
    cout<<root->val<<" ";
    inOrder(root->right);
}

int main()
{
    vector<int> po = { 8, 4, 5, 2, 6, 7, 3, 1};
    vector<int> in = { 4, 8, 2, 5, 1, 6, 3, 7};

    BinaryTree<int>* root = buildtree(po,in,in.size());

    inOrder(root); // test if constructed binary tree results in same inorder sequence
}
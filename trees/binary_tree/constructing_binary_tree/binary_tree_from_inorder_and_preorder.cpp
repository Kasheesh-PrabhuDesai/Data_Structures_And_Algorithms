/*

You are given two vectors. The first vector is the sequence obtained from inorder traversal of a
binary tree. The second is the sequence obtained from inorder traversal of a binary tree.
You have to construct a binary tree from these two sequences.

Approach:

Create a helper function that will use recursion to build the binary tree. The input to this
function will be the inorder sequence, pre-order sequence , inorder start, inorder end, 
preorder start and preorder end. 

Time Complexity: O(N)
Space Complexity: O(N)


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


BinaryTree<int>* buildtreeHelper(int* in,int* pr,int inS, int inE,int preS,int preE)
{
    if(inS>inE)
        return NULL;
    
    int root_data = pr[preS];
    int root_index = -1;
    for(int i=inS;i<=inE;i++)
    {
        if(in[i]==root_data)
        {
            root_index = i;
            break;
        }
    }
    int LinS = inS;
    int LinE = root_index-1;
    int LpreS = preS+1;
    int LpreE = LinE - LinS + LpreS;
    int RinS = root_index+1;
    int RinE = inE;
    int RpreS = LpreE+1;
    int RpreE = preE;

    BinaryTree<int>* root = new BinaryTree<int>(root_data);
    root->left = buildtreeHelper(in,pr,LinS,LinE,LpreS,LpreE);
    root->right = buildtreeHelper(in,pr,RinS,RinE,RpreS,RpreE);


    return root;

    
}

BinaryTree<int>* buildtree(int* in,int* pr,int size)
{
    return buildtreeHelper(in,pr,0,size-1,0,size-1);
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
    int in[] = {4,2,7,1,3};
    int pre[] = {1,2,4,7,3};

    BinaryTree<int>* root = buildtree(in,pre,5);

    inOrder(root); // test if constructed binary tree results in same inorder sequence
}
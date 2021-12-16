/*

You have been given a Binary Search Tree (BST) of integers. Exactly two nodes of this tree 
were swapped by mistake.
Your task is to restore or fix the BST, without changing its structure.
Note:
Binary Search Tree is a node-based binary tree data structure that has the following properties:

1. The left subtree of a node contains only nodes with keys lesser than the node’s key.
2. The right subtree of a node contains only nodes with keys greater than the node’s key.
3. The left and right subtree each must also be a binary search tree.

Approach:
The idea is to visit the tree in inorder fashion and search for two swapped nodes. 
After finding the incorrect nodes, we will swap their data. 

In inorder traversal, first, we visit the left subtree, then the root node and the right subtree.
As we are not using recursion or stack, we will be creating back-links between a node and its 
inorder successor.
 

Morris-traversal is similar to recursive/iterative traversal, but we need to modify the tree 
structure during the traversal. Before visiting the left tree of a root, we will build a 
back-link between the rightmost node in the left tree and the root. So, we can go back to 
the root node when we are done with the left tree. Then we locate the rightmost node in 
the left subtree again, cut the back-link, recover the tree structure and start visiting 
the right subtree. 
 
*/

#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;


template <typename T>
class BinaryTreeNode {
    public: 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};


BinaryTreeNode<int>* fixBST(BinaryTreeNode<int>* root)
{
    BinaryTreeNode<int> *first = NULL, *second = NULL;
    BinaryTreeNode<int> *prev = new BinaryTreeNode<int>(-1);

    BinaryTreeNode<int> *curr = root;

    // Using Morris Traversal to traverse the BST in the inorder fashion.
    while (curr != NULL)
    {
        if (curr -> left == NULL)
        {
            if (curr -> data < prev -> data)
            {
                if (first == NULL)
                {
                    first = prev;
                }
                second = curr;
            }
            prev = curr;
            curr = curr -> right;
        }
        else
        {
            BinaryTreeNode<int> *temp = curr -> left;

            while (temp -> right and temp -> right != curr)
            {
                temp = temp -> right;
            }

            if (temp -> right == NULL)
            {
                temp -> right = curr;
                curr = curr -> left;
            }

            else
            {
                temp -> right = NULL;
                if (curr -> data < prev -> data)
                {
                    if (first == NULL)
                    {
                        first = prev;
                    }
                    second = curr;
                }
                prev = curr;
                curr = curr -> right;
            }
        }
    }

    // Swapping the data of the incorrect nodes to fix the BST.
    swap(first -> data, second -> data);

    return root;
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
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(2);
    root->left = new BinaryTreeNode<int>(1);
    root->right = new BinaryTreeNode<int>(3);

    root = fixBST(root);
    
    
    print_level_order(root);
}
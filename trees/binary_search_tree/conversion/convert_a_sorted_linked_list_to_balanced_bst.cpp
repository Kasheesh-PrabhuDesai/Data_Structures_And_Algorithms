/*

You have been given a singly linked list in which nodes are present in increasing order. 
Your task is to construct a Balanced Binary Search Tree with the same data elements as the 
given Linked List.

A Balanced BST is defined as a BST in which the height of two subtrees of every node differs 
no more than 1.

Approach:
Traverse the Linked List to count the number of nodes. Lets say N are the total number of nodes.
Recursively construct the n/2 nodes in left subtree. Link this left subtree to the root.
Similarly recursively construct the n/2 nodes right subtree and then link this right subtree to
the root.

Time Complexity: O(N)
Space Complexity: O(N)

*/

#include<iostream>

using namespace std;
    
template <typename T>
class Node {
    public:
    T data;
    Node* next;

    Node(T data) {
        next = NULL;
        this->data = data;
    }

    ~Node() {
        if (next != NULL) {
            delete next;
        }
    }
};


template <typename T>
class TreeNode {
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
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

TreeNode<int>* constructBST(Node<int>** head_ref,int n)
{
    if (n <= 0)
        return NULL;
 
    TreeNode<int>* left = constructBST(head_ref, n/2);
 
    TreeNode<int>* root = new TreeNode<int>((*head_ref)->data);
    root->left = left;
 
    *head_ref = (*head_ref)->next;
 
    root->right = constructBST(head_ref, n - n / 2 - 1);
 
    return root;
}


TreeNode<int>* sortedListToBST(Node<int>* head) 
{
	int nn=0;
    Node<int>* temp = head;
    while(temp)
    {
        temp = temp->next;
        nn++;
    }
    
    return constructBST(&head,nn);
}

void Inorder(TreeNode<int>* root)
{
    if (root==nullptr)
        return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

int main()
{
    Node<int>* head = new Node<int>(1);
    head->next = new Node<int>(2);
    head->next->next = new Node<int>(3);
    head->next->next->next = new Node<int>(4);

    TreeNode<int>* root = sortedListToBST(head);

    Inorder(root);
    
}


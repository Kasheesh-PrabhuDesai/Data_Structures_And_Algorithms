/*

You are given two balanced binary search trees of integers having ‘N’ and ‘M’ nodes. 
You have to merge the two BSTs into a balanced binary search tree and return the root 
node to that balanced BST.

A binary search tree (BST) is a binary tree data structure with the following properties.
• The left subtree of a node contains only nodes with data less than the node’s data.
• The right subtree of a node contains only nodes with data greater than the node’s data.
• Both the left and right subtrees must also be binary search trees.


*/

 #include <iostream>
 #include <vector>
 #include<algorithm>
 #include <queue>

 using namespace std;   

template <typename T>
class TreeNode{

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
        if (left){
        delete left;
        }

        if (right){
        delete right;
        }
    }   
};

void inOrder(TreeNode<int>* root, vector<int>& nodes)
{
    if(root==NULL)
        return;
    
    inOrder(root->left,nodes);
    nodes.push_back(root->data);
    inOrder(root->right,nodes);
    
}

TreeNode<int>* mergeTwoBST(vector<int>& nodes,int start,int end)
{
    if(start>end)
        return NULL;
   	
    
    int mid = (start+end)/2;
	TreeNode<int>* root = new TreeNode<int>(nodes[mid]);
    root->left = mergeTwoBST(nodes,start,mid-1);
    root->right = mergeTwoBST(nodes,mid+1,end);
    
    return root;
}

TreeNode<int>* mergeBST(TreeNode<int> *root1, TreeNode<int> *root2){
    // Write your code here.
    vector<int> n1,n2;
    
    inOrder(root1,n1);
    inOrder(root2,n2);
    
    n1.insert(n1.end(),n2.begin(),n2.end());
    
    sort(n1.begin(),n1.end());
    
    int n = n1.size();
    
    return mergeTwoBST(n1,0,n-1);
    
    
}

void print_level_order(TreeNode<int>* root)
{
    if(root==NULL)
        cout<<"BYE BYE";
    
    queue<TreeNode<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        TreeNode<int>* current = q.front();

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
    TreeNode<int>* root1 = new TreeNode<int>(2);
    root1->left = new TreeNode<int>(1);
    root1->right = new TreeNode<int>(3);

    TreeNode<int>* root2 = new TreeNode<int>(4);

    TreeNode<int>* result = mergeBST(root1,root2);

    print_level_order(result);
}
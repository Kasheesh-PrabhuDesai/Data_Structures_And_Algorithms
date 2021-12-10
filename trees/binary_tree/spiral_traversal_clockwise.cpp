/*

You are given a binary tree. You need to traverse the tree is clockwise spiral manner.

Idea is to carry out a level order traversal. Declare an extra variable called level.
When level is even traverse the tree left to right. If level is odd traverse the tree right to
left.


*/









#include <iostream>
#include <queue>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class TreeNode
{
    public:
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(T val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    ~TreeNode()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }

};

void spiralTraversal(TreeNode<int>* root)
{
    queue<TreeNode<int>*> q;
    vector<int> r;
    int level = 0;
    if(root==NULL)
        return;
   
    q.push(root);
    
    while(!q.empty())
    {
        int s = q.size();
        vector<int> temp;
        for(int i=0;i<s;i++)
        {
            TreeNode<int>* front = q.front();
            q.pop();
            temp.push_back(front->val);
            if(front->left)
                q.push(front->left);
           	if(front->right)
                q.push(front->right);   
        }
        
        if(level%2==0)
            reverse(temp.begin(),temp.end());
        for(int i=0;i<temp.size();i++)
            r.push_back(temp[i]);
        level++;
  
    }

    for(int i=0;i<r.size();i++)
    {
        cout<<r[i]<<" ";

    }
    cout<<endl;

}

TreeNode<int>* buildtree(){
  int d;
  cin>>d;
  TreeNode<int>* root;
  if(d==-1){
    return NULL;
  }
  root = new TreeNode<int>(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}

void print(vector<int>& preOrder){
    for(auto i:preOrder)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    /*
                1
            2       3
        
        4        5       6
            7       
    
    -1 indicates a null value.

    */

   TreeNode<int>* T = new TreeNode<int>(1);
   T->left = new TreeNode<int>(2);
   T->left->left = new TreeNode<int>(4);
   T->left->left->right = new TreeNode<int>(7);
   T->right = new TreeNode<int>(3);
   T->right->right = new TreeNode<int>(6);
   T->right->left = new TreeNode<int>(5);

   spiralTraversal(T);
   
   

}
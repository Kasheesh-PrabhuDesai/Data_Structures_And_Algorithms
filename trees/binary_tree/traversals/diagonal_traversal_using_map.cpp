/*

You are given two Binary Trees. You need to return true if the diagonals of trees 
are anagram to each other, otherwise you need to return false.

An anagram is a word or phrase formed by rearranging the letters of a different word 
or phrase, typically using all the original letters exactly once. For example, 
the word anagram itself can be rearranged into nag a ram, also the word binary 
into brainy and the word adobe into abode.


*/
#include <iostream>
#include <queue>
#include<map>
#include<algorithm>

using namespace std;

template <typename T>
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


map<int,vector<int>> diagonalTraverse(BinaryTreeNode<int>* root,int d,map<int,vector<int>>& m)
{
    
	if(root==nullptr)
        return m;
    
    m[d].push_back(root->data);
    
    diagonalTraverse(root->left,d+1,m);
    
    diagonalTraverse(root->right,d,m);
    
    return m;
    
}
bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.
    map<int,vector<int>> m1,m2;
    bool same=false;
    
    m1 = diagonalTraverse(root1,0,m1);
    m2 = diagonalTraverse(root2,0,m2);
    
    if (m1.size()!=m2.size())
        return false;
    
    else
    {
        for(int i=0;i<m1.size();i++)
        {
			sort(m1[i].begin(),m1[i].end());
            sort(m2[i].begin(),m2[i].end());
            
            if(m1[i]!=m2[i])
                return false;
        }
        return true;
    }
    
    
}


BinaryTreeNode<int>* buildtree(){
  int d;
  cin>>d;
  BinaryTreeNode<int>* root;
  if(d==-1){
    return NULL;
  }
  root = new BinaryTreeNode<int>(d);
  root->left=buildtree();
  root->right=buildtree();
  return root;
}

void print(map<int,vector<int>>& diagonalOrder){
    for(int i=0;i<diagonalOrder.size();i++)
    {
        for(auto val:diagonalOrder[i])
            cout<<val<<" ";
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
    /*
                    2
        1 2 3 4 -1 5 -1 -1 -1 -1 -1
          1 2 -1 3 -1 4 -1 -1 -1
    
    -1 indicates a null value.

    */

   BinaryTreeNode<int>* T = buildtree();
   
   map<int,vector<int>> res = diagonalTraverse(T,0,res);

   print(res);

}

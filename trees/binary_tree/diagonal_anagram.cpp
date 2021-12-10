#include <queue>
#include<algorithm>
#include <iostream>

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

bool diagonalTraverse(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2)
{
    queue<BinaryTreeNode<int>*> q1,q2;

    if(root1==NULL || root2==NULL)
        return false;
    
    if(root1==NULL && root2==NULL)
        return true;
    
    q1.push(root1);
    q2.push(root2);

    while(!q1.empty() && !q2.empty())
    {

        int s1 = q1.size();
        int s2 = q2.size();
        
        if(s1!=s2)
            return false;
        vector<int> a1,a2;
        while(s1--)
        {
            BinaryTreeNode<int>* temp1 = q1.front();
            BinaryTreeNode<int>* temp2 = q2.front();
            q1.pop();
            q2.pop();

            while(temp1)
            {
                a1.push_back(temp1->data);

                if(temp1->left)
                {
                    q1.push(temp1->left);
                }

                temp1 = temp1->right;
            }
            while(temp2)
            {
                a2.push_back(temp2->data);

                if(temp2->left)
                {
                    q2.push(temp2->left);
                }

                temp2 = temp2->right;
            }
			sort(a1.begin(),a1.end());
            sort(a2.begin(),a2.end());
            if(a1!=a2)
                return false;
        }
    }

    return true;
}

bool diagonalAnagram(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here.
	
    return diagonalTraverse(root1,root2);
    
    
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

/*
void print(map<int,vector<int>>& diagonalOrder){
    for(int i=0;i<diagonalOrder.size();i++)
    {
        for(auto val:diagonalOrder[i])
            cout<<val<<" ";
        cout<<endl;
    }
    cout<<endl;
}
*/

int main()
{
    /*
                    2
        1 2 3 4 -1 5 -1 -1 -1 -1 -1
          1 2 -1 3 -1 4 -1 -1 -1
    
    -1 indicates a null value.

    */

   BinaryTreeNode<int>* T1 = buildtree();
   BinaryTreeNode<int>* T2 = buildtree();
   
   cout<<diagonalAnagram(T1,T2)<<endl;

}

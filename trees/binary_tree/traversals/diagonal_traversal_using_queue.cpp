/* 

You are given a binary tree. Traverse the binary tree in a diaogonal fashion.
For example.

                            2
                        3       4
                    
                      2      4       5
                                        6
                         8                 7

Diagonal 1: 2-4-5-6-7
Diagonal 2: 3-4
Diagonal 3: 2-8

Idea is to traverse the right subtree of a node until it exists. Once it ceases to exist, move
to the next left node and follow the same process until the node results in NULL. 

Use a queue to store only the left node if it exists. Pop the left node once all its right subnodes
are traversed.

Time Complexity: O(N) where N is the number of nodes.
Space Complexity: O(N) where N is the number of nodes.

*/

#include <iostream>
#include <queue>
#include <vector>

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
            left=NULL;
            right=NULL;
        }
};

vector<vector<int>> diagonalTraverse(TreeNode<int>* root)
{
    queue<TreeNode<int>*> q;
    vector<vector<int>> result;

    if(root==NULL)
        return result;
    
    q.push(root);

    while(!q.empty())
    {

        int s = q.size();
        vector<int> ans;
        while(s--)
        {
            TreeNode<int>* temp = q.front();
            q.pop();

            while(temp)
            {
                ans.push_back(temp->val);

                if(temp->left)
                {
                    q.push(temp->left);
                }

                temp = temp->right;
            }

            result.push_back(ans);
        }
    }

    return result;
}

TreeNode<int>* buildtree(){
  int d;
  cin>>d;
  TreeNode<int>* root;
  if(d==-1){
    return NULL;
  }
  root = new TreeNode<int>(d);
  root->left = buildtree();
  root->right = buildtree();
  return root;
}

void print(vector<vector<int>> v){
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
   
}


int main()
{
    TreeNode<int>* T = buildtree();

    vector<vector<int>> r = diagonalTraverse(T);

    print(r);
}
#include <iostream>
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

vector<int> preOrderTraversal(TreeNode<int>* root)
{
    vector<int> preOrder{};

    if(root==NULL)
        return preOrder;

    preOrder.push_back(root->val);
    if(root->left)
        preOrderTraversal(root->left);
    if(root->right)
        preOrderTraversal(root->right);

    return preOrder;
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
                5
            6       10
          2   3   9    5
    
    -1 indicates a null value.

    */

   TreeNode<int>* T = buildtree();
   
   vector<int> result = preOrderTraversal(T);

   print(result);

}
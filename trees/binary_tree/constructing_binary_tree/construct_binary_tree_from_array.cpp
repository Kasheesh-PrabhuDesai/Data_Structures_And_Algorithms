/*

You are given an array of integers. The expected output is a binary tree constructed in 
a level order. 

Approach:

Using a queue, store the address of the root in the queue until both its children are added to 
the binary tree. Once added remove this parent root from the queue and add its left child as
the next parent root in the queue. Repeat this procedure until the end of the vector array.

Time Complexity: O(N) where N are the number of elements in the vector array
Space Complexity: O(N) where N are the number of elements in the vector array

*/


#include <iostream>
#include <queue>
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

BinaryTree <int>* constructCBT(vector <int> arr)
{
    // Write your code here.
    BinaryTree <int>* a = new BinaryTree <int>(arr[0]) ;

    queue<BinaryTree <int>*>q;

    int i = 0;

    q.push(a);

    int s = arr.size()-1;

    while(!q.empty()){

        BinaryTree <int>*c = q.front();

        int l = i+1, r = i+2;

        q.pop();

       if(l<=s){

           c->left=new BinaryTree <int>(arr[l]);

           q.push(c->left);

           i++;

       }else break;

       if(r<=s){

           c->right=new BinaryTree <int>(arr[r]);

           q.push(c->right);

           i++;

       }

   }

   return a;
}

void printLevelOrder(BinaryTree<int>* root)
{
    if(root==NULL)
        return;
    
    queue<BinaryTree<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        BinaryTree<int>* current = q.front();

        cout<<current->val<<" ";

        if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}


int main()
{
    vector<int> arr = {1, 2 ,3, 4, 5};

    BinaryTree<int>* root = constructCBT(arr);

    printLevelOrder(root);
}
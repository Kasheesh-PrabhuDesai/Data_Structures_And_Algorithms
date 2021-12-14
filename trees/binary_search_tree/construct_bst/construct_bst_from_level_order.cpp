/* 

You are given an array of integers representing level order traversal.
Construct a binary search tree from the given array.

Approach:
The idea is to make a class which contains a pointer to the node, minimum data and maximum data 
of the ancestor.

Time Complexity: O(N) where N is the length of the array
Space Comlexity: O(N) where N is the length of the array

*/

#include <iostream>
#include<queue>
#include <vector>
#include<bits/stdc++.h>

using namespace std;

template <typename T>
class BinarySearchTree
{
    public:
    T val;
    BinarySearchTree<T>* left;
    BinarySearchTree<T>* right;

    BinarySearchTree(T val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinarySearchTree()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

class ansd{
public:
    BinarySearchTree<int>* n;
    int mx,mn;
};

BinarySearchTree<int>* constructBstFromLevelOrder(vector<int>& lo)
{
    BinarySearchTree<int>*r = new BinarySearchTree<int>(lo[0]);
    int i = 1;
    queue<ansd>q;
//     for(auto i:lo)cout<<i<<" ";
//     cout<<endl;

    ansd node;
    node.n = r;
    node.mx = INT_MAX;
    node.mn = INT_MIN;
 
    q.push(node);
    int s = lo.size();
    
    while(!q.empty() && i < s){
        ansd c = q.front();
        q.pop();
        if(c.n != NULL){
            if(lo[i] < c.n->val && lo[i] > c.mn ){
                c.n->left = new BinarySearchTree<int>(lo[i++]);
                ansd l ;
                l.n = c.n->left;
                l.mx = c.n->val;
                l.mn = c.mn;
				q.push(l);                
            }
            if(lo[i] > c.n ->val && lo[i] < c.mx ){
                c.n->right = new BinarySearchTree<int>(lo[i++]);
            	ansd r;
                r.n = c.n->right;
                r.mn = c.n->val;
                r.mx = c.mx;
                q.push(r);
            }  
        }
    }
    return r;    
}

void printLevelOrder(BinarySearchTree<int>* root)
{
    if (root==NULL)
        return;
    
    queue<BinarySearchTree<int>*> q;

    q.push(root);

    while(!q.empty())
    {
        BinarySearchTree<int>* current = q.front();

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
    vector<int> a = {5,3,6,2,4,7};

    BinarySearchTree<int>* root = NULL;

    root = constructBstFromLevelOrder(a);

    printLevelOrder(root);
}
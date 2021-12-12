#include<iostream>

using namespace std;

template<typename T>
class BinaryTree
{
    public:
    T data;
    BinaryTree<T>* left;
    BinaryTree<T>* right;

    BinaryTree(T val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
    ~BinaryTree()
    {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};


void inOrderTraversal(BinaryTree<int>* root)
{
    if(root==NULL)
        return;

    inOrderTraversal(root->left);

    cout<<root->data<<" ";

    inOrderTraversal(root->right);
 
}

BinaryTree<int>* buildtree()
{
    int d;
    cin>>d;

    if(d==-1)
        return NULL;
    
    BinaryTree<int>* root;

    root = new BinaryTree<int>(d);
    root->left = buildtree();
    root->right = buildtree();

    return root;


}

int main()
{
            /*
                            1
                        2       3

                            4       5
            */



    BinaryTree<int>* T = new BinaryTree<int>(1);
    T->left = new BinaryTree<int>(2);
    T->right = new BinaryTree<int>(3);
    T->right->left = new BinaryTree<int>(4);
    T->right->right = new BinaryTree<int>(5);


    inOrderTraversal(T);
}
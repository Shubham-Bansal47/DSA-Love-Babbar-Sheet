#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        int val;
        Node* right;

        Node(int value)
        {
            this->left=NULL;
            this->val=value;
            this->right=NULL;
        }
};

void CreateBinaryTree(Node* &root)
{
    int val;
    cin>>val;
    if(val==-1)
        return;

    root=new Node(val);

    cout<<"Enter value in leftsubtree of "<<val<<endl;
    CreateBinaryTree(root->left);
    cout<<"Enter value in rightsubtree of "<<val<<endl;
    CreateBinaryTree(root->right);

    return;
}

void BoundaryTraversalLeft(Node* root)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        return;
    
    cout<<root->val<<" ";

    if(root->left!=NULL)
        BoundaryTraversalLeft(root->left);
    else
        BoundaryTraversalLeft(root->right);

    return;
}

void BoundaryLeafNodes(Node* root)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
    {
        cout<<root->val<<" ";
        return;
    }

    BoundaryLeafNodes(root->left);
    BoundaryLeafNodes(root->right);

    return;
}

void BoundaryTraversalRight(Node* root)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
        return;

    if(root->right!=NULL)
        BoundaryTraversalRight(root->right);
    else
        BoundaryTraversalRight(root->left);

    cout<<root->val<<" ";

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    BoundaryTraversalLeft(root);
    BoundaryLeafNodes(root);
    BoundaryTraversalRight(root->right);

    return 0;
}
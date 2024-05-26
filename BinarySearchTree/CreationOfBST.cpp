#include<bits/stdc++.h>
using namespace std;

// A Binary Tree which has lower value inserted at left subtree of root and greater value inserted at rightsubtree of root.

class Node{
    public:
        Node* left;
        int val;
        Node* right;

        Node(int value)
        {
            this->val=value;
            this->left=NULL;
            this->right=NULL;
        }
};

void InsertInBST(Node* &root,int value)
{
    if(root==NULL)
    {    
        root=new Node(value);
        return;
    }   

    if(root->val>value)
        InsertInBST(root->left,value);
    else
        InsertInBST(root->right,value);

    return;
}

void CreationBST(Node* &root)
{
    int x=1;
    cout<<"Start entering value in BST \nenter -1 to stop"<<endl;
    while(x)
    {
        int value;
        cin>>value;
        InsertInBST(root,value);
        cout<<"Do you want to enter more nodes"<<endl;
        cin>>x;
    }

    return;
}

void InOrderTraversal(Node* root)
{
    if(root==NULL)
        return;

    InOrderTraversal(root->left);
    cout<<root->val<<" ";
    InOrderTraversal(root->right);

    return;
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    InOrderTraversal(root);

    return 0;
}
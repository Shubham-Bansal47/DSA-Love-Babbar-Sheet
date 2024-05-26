#include<bits/stdc++.h>
using namespace std;

//Binary Trees ->a non linear data structure

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

void PrintBinaryTreeInorder(Node* root)
{
    if(root==NULL)
        return;

    PrintBinaryTreeInorder(root->left);
    cout<<root->val<<" ";
    PrintBinaryTreeInorder(root->right);

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    PrintBinaryTreeInorder(root);

    return 0;
}
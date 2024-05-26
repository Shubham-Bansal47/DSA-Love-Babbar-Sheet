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

void CountLeaf(Node* root,int &count)
{
    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL)
    {
        count++;
        return;
    }

    CountLeaf(root->left,count);
    CountLeaf(root->right,count);

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int count=0;
    CountLeaf(root,count);
    cout<<count;

    return 0;
}
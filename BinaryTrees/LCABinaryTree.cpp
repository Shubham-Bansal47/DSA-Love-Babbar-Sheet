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

Node* LCA(Node* root,int &x1,int &x2)
{
    if(root==NULL)
        return NULL;
    if(root->val==x1 || root->val==x2)
        return root;

    Node* left=LCA(root->left,x1,x2);
    Node* right=LCA(root->right,x1,x2);

    if(left!=NULL && right!=NULL)
        return root;
    else if(left!=NULL && right==NULL)
        return left;
    else if(left==NULL && right!=NULL)
        return right;
    else
        return NULL;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int x1,x2;
    cin>>x1;
    cin>>x2;

    Node* ans=LCA(root,x1,x2);
    cout<<ans->val;

    return 0;
}
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

int countsum(Node* root)
{
    if(root==NULL)
        return 0;
    if(root->left!=NULL && root->right!=NULL)
        return root->val;

    int left=countsum(root->left);
    int right=countsum(root->right);

    return left+right+root->val;
}

bool SumTree(Node* root)
{
    if(root==NULL)
        return true;
    if(root->left!=NULL && root->right!=NULL)
        return true;

    bool left=SumTree(root->left);
    bool right=SumTree(root->right);
    bool check=(countsum(root->left)+countsum(root->right))==root->val;

    if(left && right && check)
        return true;
    else    
        return false;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int ans=SumTree(root);
    cout<<ans;

    return 0;
}
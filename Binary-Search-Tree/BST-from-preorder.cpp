#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* inserting(Node* root,int x)
{
    if(root==NULL)
    {
        root=new Node(x);
        return root;
    }

    if(root->data>x)
    {
        root->left=inserting(root->left,x);
    }
    else
    {
        root->right=inserting(root->right,x);
    }

    return root;
}

void inorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

    return;
}

int main()
{
    Node* root=NULL;
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
    {
        cin>>vec[i];
    }
    root=new Node(vec[0]);
    for(int i=1; i<n; i++)
    {
        root=inserting(root,vec[i]);
    }
    inorder(root);

    return 0;
}
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

Node* creatingBST(Node* root,vector<int>& vec,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=start+(end-start)/2;
    root=new Node(vec[mid]);

    root->left=creatingBST(root->left,vec,start,mid-1);
    root->right=creatingBST(root->right,vec,mid+1,end);

    return root;
}

void preorder(Node* root)
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

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
    int start=0;
    int end=vec.size()-1;
    root=creatingBST(root,vec,start,end);
    preorder(root);

    return 0;
}
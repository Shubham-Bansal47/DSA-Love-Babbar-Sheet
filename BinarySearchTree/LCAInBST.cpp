#include<bits/stdc++.h>
using namespace std;

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

Node* LCA(Node* root,int k1,int k2)
{
    if(root==NULL)
        return NULL;

    if(root->val<k1 && root->val<k2)
        return LCA(root->right,k1,k2);
    else if(root->val>k1 && root->val>k2)
        return LCA(root->left,k1,k2);
    else
        return root;
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    cout<<"Enter value of nodes for LCA finding"<<endl;
    int k1,k2;
    cin>>k1;
    cin>>k2;
    Node* ans=LCA(root,k1,k2);
    cout<<ans->val;

    return 0;
}
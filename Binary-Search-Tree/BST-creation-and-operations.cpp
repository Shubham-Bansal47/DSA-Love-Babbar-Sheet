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

void BuildingBST(struct Node* &root,int val)
{
    if(root==NULL)
    {
        root=new Node(val);
        return;
    }

    if(root->data>val)
    {
        BuildingBST(root->left,val);
    }
    else
    {
        BuildingBST(root->right,val);
    }

    return;
}

struct Node* BuildBST(struct Node* &root)
{
    int val;
    cout<<"Enter Data in Tree"<<endl;
    cin>>val;

    while(val!=-1)
    {
        BuildingBST(root,val);
        cin>>val;
    }

    return root;
}

bool SearchBSTnaive(struct Node* root,int val) //using recursion
{
    if(root==NULL)
    {
        return false;
    }

    if(root->data==val)
    {
        return true;
    }

    if(root->data>val)
    {
        SearchBSTnaive(root->left,val);
    }
    else
    {
        SearchBSTnaive(root->right,val);
    }
}

bool SearchBSTOptimised(struct Node* root,int val)
{
    if(root==NULL)
    {
        return false;
    }

    while(root!=NULL)
    {
        if(root->data==val)
        {
            return true;
        }
        if(root->data>val)
        {
            root=root->left;
        }
        else
        {
            root=root->right;
        }
    }

    return false;
}

int minval(struct Node* root)
{
    if(root==NULL)
    {
        return -1;
    }

    while(root->left!=NULL)
    {
        root=root->left;
    }

    return root->data;
}

int maxval(struct Node* root)
{
    if(root==NULL)
    {
        return -1;
    }

    while(root->right!=NULL)
    {
        root=root->right;
    }

    return root->data;
}

struct Node* DeletionBST(struct Node* root,int val)
{
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==val)
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete(root);
            return NULL;
        }
        else if(root->left!=NULL && root->right==NULL)
        {
            struct Node* temp=root->left;
            delete(root);
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL)
        {
            struct Node* temp=root->right;
            delete(root);
            return temp;
        }
        else
        {
            int minimum=minval(root->right);
            root->data=minimum;
            root->right=DeletionBST(root->right,minimum);
            return root;
        }
    }
    
    if(root->data>val)
    {
        root->left=DeletionBST(root->left,val);
    }
    else
    {
        root->right=DeletionBST(root->right,val);
    }

    return root;
}

void order(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    order(root->left);
    cout<<root->data<<" ";
    order(root->right);

    return;
}

int main()
{
    struct Node* root=NULL;
    root=BuildBST(root);
    // order(root);
    cout<<endl;
    root=DeletionBST(root,2);
    // order(root);
}
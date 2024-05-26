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

Node* DeleteNode(Node* root,int k)
{
    if(root->val>k)
        root->left=DeleteNode(root->left,k);
    else if(root->val<k)
        root->right=DeleteNode(root->right,k);
    else
    {
        if(root->left==NULL && root->right==NULL)
            return NULL;
        else if(root->left==NULL && root->right!=NULL)
            return root->right;
        else if(root->left!=NULL && root->right==NULL)
            return root->left;
        else
        {
            Node* temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
            int value=temp->val;
            root->val=value;
            root->left=DeleteNode(root->left,value);
            return root;
        }
    }

    return root;
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
    cout<<"Enter Node to delete"<<endl;
    int k;
    cin>>k;
    root=DeleteNode(root,k);
    InOrderTraversal(root);

    return 0;
}
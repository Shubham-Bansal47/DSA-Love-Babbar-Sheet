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

void PredecessorAndSuccessorOfNodeInBST(Node* root,int key)
{
    int suc=-1,pre=-1;
 
    Node* temp=root;
    while(temp!=NULL && temp->val!=key)
    {
        if(temp->val>key)
            temp=temp->left;
        else if(temp->val<key)
            temp=temp->right;
    }

    if(temp==NULL)
    {
        cout<<"Predecessor "<<pre<<endl;
        cout<<"Successor "<<suc<<endl;
        return;
    }
    else
    {
        Node* prede=temp;
        prede=temp->left;
        if(prede!=NULL)
        {
            while(prede->right!=NULL)
                prede=prede->right;
            
            pre=prede->val;
        }    
        Node* succ=temp;
        succ=temp->right;
        if(succ!=NULL)
        {
            while(succ->left!=NULL)
                succ=succ->left;
            suc=succ->val;
        }

        cout<<"Predecessor "<<pre<<endl;
        cout<<"Successor "<<suc<<endl;
        return;
    }
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    int key;
    cout<<"Enter value of key"<<endl;
    cin>>key;
    PredecessorAndSuccessorOfNodeInBST(root,key);

    return 0;
}
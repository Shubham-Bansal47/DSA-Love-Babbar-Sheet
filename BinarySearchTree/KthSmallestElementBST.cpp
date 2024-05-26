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

void KthSmallestElementInBST(Node* root,int &k,int &ans)
{
    if(root==NULL)
        return;

    KthSmallestElementInBST(root->left,k,ans);
    k--;
    if(k==0)
    {
        ans=root->val;
        return;
    }
    KthSmallestElementInBST(root->right,k,ans);
   

    return;
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    int k;
    cout<<"Enter value of k"<<endl;
    cin>>k;
    int ans=-1;
    KthSmallestElementInBST(root,k,ans);
    cout<<ans;

    return 0;
}
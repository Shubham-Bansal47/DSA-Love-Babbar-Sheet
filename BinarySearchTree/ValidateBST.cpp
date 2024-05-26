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

bool validateBST(Node* root,int min,int max)
{
    if(root==NULL)
        return true;

    bool left=validateBST(root->left,min,root->val);
    bool right=validateBST(root->right,root->val,max);
    bool check=(root->val>min && root->val<max);

    if(left && right && check)
        return true;
    else
        return false;
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    bool ans=validateBST(root,-1e8,1e8);
    cout<<ans;

    return 0;
}
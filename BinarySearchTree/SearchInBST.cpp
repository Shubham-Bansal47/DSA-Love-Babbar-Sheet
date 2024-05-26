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

string SearchInBST(Node* root,int &key)
{
    string ans="";
    while(root!=NULL)
    {
        if(root->val==key)
        {
            ans="Key is present";
            return ans;
        }
        else if(root->val>key)
            root=root->left;
        else
            root=root->right;
    }

    ans="Key is not present";
    return ans;
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    int k;
    cout<<"Enter key you want to find"<<endl;
    cin>>k;
    string ans=SearchInBST(root,k);
    cout<<ans;

    return 0;
}
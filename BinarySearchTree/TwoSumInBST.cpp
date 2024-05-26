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

void InOrderTraversal(Node* root,vector<int> &ans)
{
    if(root==NULL)
        return;

    InOrderTraversal(root->left,ans);
    ans.push_back(root->val);
    InOrderTraversal(root->right,ans);

    return;
}

int main()
{
    Node* root=NULL;
    CreationBST(root);
    int key;
    cout<<"Enter value of key"<<endl;
    cin>>key;
    vector<int> ans;
    InOrderTraversal(root,ans);
    int s,e;
    s=0;
    e=ans.size()-1;
    while(s<e)
    {
        if(ans[s]+ans[e]<key)
            s++;
        else if(ans[s]+ans[e]>key)
            e--;
        else 
        {
            cout<<"Yes pair is Present"<<endl;
            return 0;
        }
    }
    cout<<"Pair not present";

    return 0;
}
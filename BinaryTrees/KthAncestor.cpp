#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        Node* left;
        int val;
        Node* right;

        Node(int value)
        {
            this->left=NULL;
            this->val=value;
            this->right=NULL;
        }
};

void CreateBinaryTree(Node* &root)
{
    int val;
    cin>>val;
    if(val==-1)
        return;

    root=new Node(val);

    cout<<"Enter value in leftsubtree of "<<val<<endl;
    CreateBinaryTree(root->left);
    cout<<"Enter value in rightsubtree of "<<val<<endl;
    CreateBinaryTree(root->right);

    return;
}

Node* KthAncestor(Node* root,int x,int &k)
{
    if(root==NULL)
        return NULL;

    if(root->val==x)
        return root;
    
    Node* left=KthAncestor(root->left,x,k);
    Node* right=KthAncestor(root->right,x,k);

    if(left!=NULL && right==NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return left;
    }
    else if(left==NULL && right!=NULL)
    {
        k--;
        if(k<=0)
        {
            k=INT_MAX;
            return root;
        }
        return right;
    }
    
    return NULL;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int x,k;
    cin>>x;
    cin>>k;
    Node* ans=KthAncestor(root,x,k);
    if(ans==NULL)   
        cout<<-1;
    else
        cout<<ans->val;

    return 0;
}
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

Node* CreateBST(vector<int> &in,int s,int e)
{
    if(s>e)
        return NULL;

    int mid=s+(e-s)/2;
    Node* root=new Node(in[mid]);

    root->left=CreateBST(in,s,mid-1);
    root->right=CreateBST(in,mid+1,e);

    return root;
}

void PreOrderTraversal(Node* root)
{
    if(root==NULL)
        return;

    cout<<root->val<<" ";
    PreOrderTraversal(root->left);
    PreOrderTraversal(root->right);

    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> in(n);
    cout<<"Enter inorder traversal of BST";
    for(int i=0; i<n; i++)
        cin>>in[i];

    Node* root=CreateBST(in,0,n-1);
    PreOrderTraversal(root);

    return 0;
}
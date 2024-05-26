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

Node* Creation(vector<int> &in,vector<int> &post,unordered_map<int,int> &mp,int index,int s,int e)
{
    if(s>e || index<0)
        return NULL;

    int value=post[index];
    int tempindex=mp[post[index]];
    Node* root=new Node(value);
    index--;

    root->right=Creation(in,post,mp,index,tempindex+1,e);
    root->left=Creation(in,post,mp,index,s,tempindex-1);

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
    vector<int> in(n),post(n);
    cout<<"Enter Inorder vector"<<endl;
    for(int i=0; i<n; i++)
        cin>>in[i];
    cout<<"Enter Postorder Vector"<<endl;
    for(int i=0; i<n; i++)
        cin>>post[i];

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++)
        mp[in[i]]=i;

    Node* root=NULL;
    int index=n-1;
    root=Creation(in,post,mp,index,0,n-1);
    PreOrderTraversal(root);

    return 0;
}
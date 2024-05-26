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

Node* Creation(vector<int> &in,vector<int> &pre,unordered_map<int,int> &mp,int index,int s,int e)
{
    if(s>e || index>=in.size())
        return NULL;

    int tempindex=mp[pre[index]];
    int value=pre[index];
    Node* root=new Node(value);
    index++;

    root->left=Creation(in,pre,mp,index,s,tempindex-1);
    root->right=Creation(in,pre,mp,index,tempindex+1,e);

    return root;
}

void PostOrderTraversal(Node* root)
{
    if(root==NULL)
        return;

    PostOrderTraversal(root->left);
    PostOrderTraversal(root->right);
    cout<<root->val<<" ";

    return;
}

int main()
{
    int n;
    cin>>n;
    vector<int> in(n),pre(n);
    cout<<"Enter Inorder vector"<<endl;
    for(int i=0; i<n; i++)  
        cin>>in[i];
    cout<<"Enter Preorder vector"<<endl;    
    for(int i=0; i<n; i++)  
        cin>>pre[i];

    unordered_map<int,int> mp;
    for(int i=0; i<in.size(); i++)
        mp[in[i]]=i;

    Node* root=NULL;
    int index=0;
    root=Creation(in,pre,mp,index,0,n-1);
    PostOrderTraversal(root);

    return 0;
}
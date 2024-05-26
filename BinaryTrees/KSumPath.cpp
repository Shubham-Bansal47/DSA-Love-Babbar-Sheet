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

void KSumPath(Node* root,int &cnt,vector<int> vec,int k)
{
    if(root==NULL)
        return;

    vec.push_back(root->val);

    KSumPath(root->left,cnt,vec,k);
    KSumPath(root->right,cnt,vec,k);

    int sum=0;
    for(int i=vec.size()-1; i>=0; i--)
    {
        sum+=vec[i];
        if(k==sum)
            cnt++;
    }

    vec.pop_back();

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int cnt=0;
    vector<int> vec;
    int k;
    cin>>k;
    KSumPath(root,cnt,vec,k);
    cout<<cnt;

    return 0;
}
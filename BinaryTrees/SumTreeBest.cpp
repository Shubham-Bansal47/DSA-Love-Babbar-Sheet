#include<bits/stdc++.h>
using namespace std;

//Binary Trees ->a non linear data structure

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

pair<int,bool> SumTree(Node* root)
{
    pair<int,bool> temp;
    if(root==NULL)
    {
        temp.first=0;
        temp.second=true;
        return temp;
    }
    if(root->left==NULL && root->right==NULL)
    {
        temp.first=root->val;
        temp.second=true;
        return temp;
    }

    pair<int,bool> left=SumTree(root->left);
    pair<int,bool> right=SumTree(root->right);
    bool check=left.first+right.first==root->val;

    if(left.second && right.second && check)
    {
        temp.first=2*root->val;
        temp.second=true;
    }
    else
    {
        temp.first=0;
        temp.second=false;
    }

    return temp;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    pair<int,bool> ans=SumTree(root);
    cout<<"Sum of Nodes "<<ans.first<<endl;
    cout<<"Answer After Sum Check "<<ans.second;

    return 0;
}
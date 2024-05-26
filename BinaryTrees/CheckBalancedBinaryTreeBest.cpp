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

pair<int,bool> CheckBalancedBTBest(Node* root)
{
    pair<int,bool> ans; // ans.first m height store hoga har node ka and ans.second m bool check
    if(root==NULL)
    {
        ans.first=0;
        ans.second=true;
        return ans;
    }

    pair<int,bool> left=CheckBalancedBTBest(root->left);
    pair<int,bool> right=CheckBalancedBTBest(root->right);
    bool check=abs(left.first - right.first)<=1;

    ans.first=max(left.first,right.first)+1;
    if(check && left.second && right.second)
        ans.second=true;
    else
        ans.second=false;

    return ans;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    pair<int,bool> ans=CheckBalancedBTBest(root);
    cout<<"Height of Binary Tree "<<ans.first<<endl;
    cout<<"Checked Balancing "<<ans.second;

    return 0;
}
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

void BottomView(Node* root)
{
    queue<pair<int,Node*>> q;
    map<int,vector<int>> mp;
    q.push({0,root});
    while(!q.empty())
    {
        pair<int,Node*> temp=q.front();
        q.pop();
        int xaxis=temp.first;
        mp[xaxis].push_back(temp.second->val);

        if(temp.second->left!=NULL)
            q.push({xaxis-1,temp.second->left});
        if(temp.second->right!=NULL)
            q.push({xaxis+1,temp.second->right});
    }

    vector<int> ans;
    for(auto i: mp)
        ans.push_back(i.second.back());
    

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    BottomView(root);

    return 0;
}
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

void VerticalOrderTraversal(Node* root)
{
    queue<pair<Node*,pair<int,int>>> q;
    map<int,map<int,vector<int>>> mp;
    q.push({root,{0,0}});
    while(!q.empty())
    {
        pair<Node*,pair<int,int>> temp=q.front();
        q.pop();
        int xaxis=temp.second.first;
        int yaxis=temp.second.second;
        mp[xaxis][yaxis].push_back(temp.first->val);

        if(temp.first->left!=NULL)
            q.push({temp.first->left,{xaxis-1,yaxis+1}});
        if(temp.first->right!=NULL)
            q.push({temp.first->right,{xaxis+1,yaxis+1}});
    }

    vector<int> ans;
    for(auto i: mp)
    {
        for(auto j: i.second)
        {
            for(auto k: j.second)
                ans.push_back(k);
        }
    }

    for(int i=0 ;i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    VerticalOrderTraversal(root);

    return 0;
}
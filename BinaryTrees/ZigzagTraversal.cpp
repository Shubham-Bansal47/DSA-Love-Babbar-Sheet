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

void ZigzagTraversal(Node* root)
{
    if(root==NULL)
        return;
    
    queue<Node*> q;
    q.push(root);
    vector<vector<int>> ans;
    while(!q.empty())
    {
        int size=q.size();
        vector<int> tempvec;
        for(int i=0; i<size; i++)
        {
            Node* temp=q.front();
            q.pop();
            tempvec.push_back(temp->val);

            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
        ans.push_back(tempvec);
    }

    for(int i=0; i<ans.size(); i++)
    {
        if(i%2==1)
            reverse(ans[i].begin(),ans[i].end());
    }

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    ZigzagTraversal(root);

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct Node* buildtree(struct Node* root)
{
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter data in the left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter data in the right of "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

int heightrecursive(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left=heightrecursive(root->left);
    int right=heightrecursive(root->right);

    return max(left,right) + 1;
}

int heightlevelordertraversal(struct Node* root)
{
    int count=0;
    if(root==NULL)
    {
        return count;
    }

    queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            struct Node* curr=q.front();
            q.pop();

            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
        count++;
    }
    return count;
}

int diameternaive(struct Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int op1 = diameternaive(root->left);
    int op2 = diameternaive(root->right);
    int op3 = heightrecursive(root->left) + heightrecursive(root->right) + 1;

    int ans=max(op1,max(op2,op3));

    return ans;    
}

pair<int,int> diameteroptimize(struct Node* root)
{
    if(root==NULL)
    {
        pair<int,int> ans=make_pair(0,0);
        return ans;
    }

    pair<int,int> left=diameteroptimize(root->left);
    pair<int,int> right=diameteroptimize(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second + right.second + 1;

    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second) + 1;

    return ans;
}

int main()
{
    struct Node* root;
    root=NULL;
    root=buildtree(root);
    // pair<int,int> ans=diameteroptimize(root);
    // int ans=heightlevelordertraversal(root);

    return 0;
}
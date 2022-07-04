#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

struct TreeNode* buildtree(struct TreeNode* root)
{
    cout<<"Enter the Data "<<endl;
    int data;
    cin>>data;
    root=new TreeNode(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter Data in the left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter Data in the right of "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

pair<bool,int> checkoptimised(TreeNode* root,int& height)
    {
        if(root==NULL)
        {
            pair<bool,int> ans=make_pair(true,0);
            return ans;
        }
        
        pair<bool,int> left=checkoptimised(root->left,height);
        pair<bool,int> right=checkoptimised(root->right,height);
        
        int op1=left.second;
        int op2=right.second;
        
        bool ch=(abs(op1-op2))<=1;
        
        pair<bool,int> ans;
        if(left.first && right.first && ch)
        {
            ans.first=true;
            ans.second=max(op1,op2)+1;
            return ans;
        }
        else
        {
            ans.first=false;
            ans.second=max(op1,op2)+1;
            return ans;
        }
    }
    
int height(struct TreeNode* root)
{
    if(root==NULL)
    {
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    return max(left,right)+1;
}

    bool checknaive(struct TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }

        bool left=checknaive(root->left);
        bool right=checknaive(root->right);
        int h=abs(height(root->left)-height(root->right));

        if(left && right && h<=1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int main()
    {
        struct TreeNode* root=NULL;
        root=buildtree(root);
        cout<<checknaive(root);

        return 0;
    }



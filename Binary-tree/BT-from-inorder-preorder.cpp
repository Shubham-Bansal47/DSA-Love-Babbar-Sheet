#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode(int data)
    {
        val=data;
        left=NULL;
        right=NULL;
    }
};

TreeNode* constructTree(int& index,vector<int>& preorder,vector<int>& inorder,int inStart,int inEnd,unordered_map<int,int>& m)
{
    if(index>=preorder.size() || inStart>inEnd)
        return NULL;
    
    TreeNode* root=new TreeNode(preorder[index]);       
    int element=m[preorder[index++]];
    
    root->left=constructTree(index,preorder,inorder,inStart,element-1,m);
    root->right=constructTree(index,preorder,inorder,element+1,inEnd,m);
    
    return root;
}
    
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
{
    unordered_map<int,int> m;
    for(int i=0; i<inorder.size(); i++)
    {
        m[inorder[i]]=i;
    }
    int preStart,preEnd,inStart,inEnd;
    int index=0;
    inStart=0;
    inEnd=inorder.size()-1;
    TreeNode* root=constructTree(index,preorder,inorder,inStart,inEnd,m);
    
    return root;
}
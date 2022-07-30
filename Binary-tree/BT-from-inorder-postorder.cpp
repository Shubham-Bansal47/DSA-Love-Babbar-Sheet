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

TreeNode* constructTree(vector<int>& postorder,vector<int>& inorder,int& index,int inStart,int inEnd,unordered_map<int,int>& m)
{
    if(index<0 || inStart>inEnd)
        return NULL;
    
    TreeNode* root= new TreeNode(postorder[index]);
    int element=m[postorder[index--]];
    
    root->right=constructTree(postorder,inorder,index,element+1,inEnd,m);
    root->left=constructTree(postorder,inorder,index,inStart,element-1,m);
    
    return root;
}
    
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
{
    unordered_map<int,int> m;
    int inStart,inEnd,index;
    index=postorder.size()-1;
    inStart=0;
    inEnd=inorder.size()-1;
    for(int i=0; i<inorder.size(); i++)
        m[inorder[i]]=i;
    
    
    TreeNode* root=constructTree(postorder,inorder,index,inStart,inEnd,m);
    
    return root;
}
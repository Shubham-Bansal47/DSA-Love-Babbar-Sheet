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

bool inorder(TreeNode* p,TreeNode* q)
{
    if(p==NULL && q==NULL)
    {
        return true;
    }
    else if((p!=NULL && q==NULL) || (p==NULL && q!=NULL))
    {
        return false;
    }
    
    bool left=inorder(p->left,q->left);
    bool right=inorder(p->right,q->right);
    bool check = (p->data==q->data);
    if(left && right && check)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) {
    return inorder(p,q);
}

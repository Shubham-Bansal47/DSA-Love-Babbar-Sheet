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

int solve(Node* root)
{
    if(root==NULL)
        return 0;
    
    int left=solve(root->left);
    int right=solve(root->right);
    int newval=root->data;
    root->data=left+right;
    
    return left+right+newval;
}
  
void toSumTree(Node *node)
{
    solve(node);
}

int main()
{
    return 0;
}
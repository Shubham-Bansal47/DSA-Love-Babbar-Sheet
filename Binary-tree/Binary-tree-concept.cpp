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

void solve(Node* root)
{
    //Base case
    if(root==NULL)
    {
        return;
    }

    //jab neeche jaare h tab kya krna h
    
    solve(root->left);

    //left subtree se aate huye kya krna h

    solve(root->right);

    // bahar aate waqt ya fir ekdum returning ke time kya krna h

    return;
}
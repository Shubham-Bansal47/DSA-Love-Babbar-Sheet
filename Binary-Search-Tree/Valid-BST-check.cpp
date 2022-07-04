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

struct Node* BuildingBST(struct Node* &root,int data)
{
    if(root==NULL)
    {
        root=new Node(data);
        return root;
    }

    if(root->data>data)
    {
        root->left=BuildingBST(root->left,data);
    }
    else
    {
        root->right=BuildingBST(root->right,data);
    }

    return root;
}

struct Node* BuildBST(struct Node* &root)
{
    cout<<"Enter Data in tree "<<endl;
    int data;
    cin>>data;

    while(data!=-1)
    {
        root=BuildingBST(root,data);
        cin>>data;
    }

    return root;
}

//              5
//          2       7
//        1   3   6   8          5 2 1 3 4 7 6 8 -1
//              4
int main()
{
    struct Node* root=NULL;
    root=BuildBST(root);
}
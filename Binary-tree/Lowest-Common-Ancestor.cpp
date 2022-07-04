// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node* right;
    
    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

//     1
//    2 5
//   3 4
Node* LCA(Node *root,int n1,int n2)
{
    
    if(root==NULL)
    {
        return NULL;
    }

    if(root->data==n1 || root->data==n2)
    {
        return root;
    }

    Node* leftans=LCA(root->left,n1,n2);
    Node* rightans=LCA(root->right,n1,n2);
    
    if(leftans!=NULL && rightans!=NULL){
        return root;
    }

    if(leftans==NULL || rightans==NULL){
        return NULL;    
    }

    if(leftans!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    else
    {
        return LCA(root->right,n1,n2);
    }
}

int main() {
    
    Node *root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    root->left->right=new Node(4);
    root->right=new Node(5);
    
    Node *temp=LCA(root,3,4);
    cout<<temp->data;

    return 0;
}
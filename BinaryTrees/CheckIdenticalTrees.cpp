#include<bits/stdc++.h>
using namespace std;

//Binary Trees ->a non linear data structure

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

bool CheckIdenticalTrees(Node* root1,Node* root2)
{
    if(root1==NULL && root2==NULL)
        return true;
    else if(root1!=NULL && root2==NULL)
        return false;
    else if(root1==NULL && root2!=NULL)
        return false;

    bool left=CheckIdenticalTrees(root1->left,root2->left);
    bool right=CheckIdenticalTrees(root1->right,root2->right);
    bool check=root1->val==root2->val;
    
    if(left && right && check)
        return true;
    else
        return false;
}

int main()
{
    Node *root1=NULL,*root2=NULL;
    CreateBinaryTree(root1);
    CreateBinaryTree(root2);
    bool ans=CheckIdenticalTrees(root1,root2);
    cout<<ans;

    return 0;
}
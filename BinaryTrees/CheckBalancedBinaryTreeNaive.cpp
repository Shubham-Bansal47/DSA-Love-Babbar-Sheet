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

int HeightOfBT(Node* root)
{
    if(root==NULL)
        return 0;

    int leftHeight=HeightOfBT(root->left);
    int rightHeight=HeightOfBT(root->right);

    return max(leftHeight,rightHeight)+1;
}

bool CheckBalancedBTNaive(Node* root)
{
    if(root==NULL)
        return true;

    bool left=CheckBalancedBTNaive(root->left);
    bool right=CheckBalancedBTNaive(root->right);
    bool check=abs(HeightOfBT(root->left)-HeightOfBT(root->right))<=1;

    if(left && right && check)
        return true;
    else    
        return false;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    bool ans=CheckBalancedBTNaive(root);
    cout<<ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

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

int DiameterOfBTNaive(Node* root)
{
    if(root==NULL)
        return 0;

    int left=DiameterOfBTNaive(root->left);
    int right=DiameterOfBTNaive(root->right);
    int diameter=HeightOfBT(root->left)+HeightOfBT(root->right)+1;

    return max(diameter,max(left,right));
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int ans=DiameterOfBTNaive(root);
    cout<<ans;

    return 0;
}
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

void SumOfLongestBloodline(Node* root,int sumtemp,int heighttemp,int &maxsum,int &maxheight)
{
    if(root==NULL)
    {
        if(heighttemp>maxheight)
        {
            maxsum=sumtemp;
            maxheight=heighttemp;
        }
        else if(heighttemp==maxheight)
            maxsum=max(maxsum,sumtemp);

        return;
    }

    sumtemp+=root->val;
    heighttemp++;
    SumOfLongestBloodline(root->left,sumtemp,heighttemp,maxsum,maxheight);
    SumOfLongestBloodline(root->right,sumtemp,heighttemp,maxsum,maxheight);

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    int sumtemp=0;
    int heighttemp=0;
    int maxsum=0;
    int maxheight=0;
    SumOfLongestBloodline(root,sumtemp,heighttemp,maxsum,maxheight);
    cout<<maxsum;

    return 0;
}
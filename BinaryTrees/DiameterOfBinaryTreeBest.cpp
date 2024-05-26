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

pair<int,int> DiameterOfBTBest(Node* root)
{
    pair<int,int> temp; // ans.first m height store hoga har node ka and ans.second m diameter
    if(root==NULL)
    {
        temp.first=0;
        temp.second=0;
        return temp;
    }

    pair<int,int> left=DiameterOfBTBest(root->left);
    pair<int,int> right=DiameterOfBTBest(root->right);
    int diameter=left.first+right.first+1;

    temp.first=max(left.first,right.first)+1;
    temp.second=max(diameter,max(left.second,right.second));

    return temp;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    pair<int,int> ans=DiameterOfBTBest(root);
    cout<<"Height of Tree "<<ans.first<<endl;
    cout<<"Diameter of Tree "<<ans.second;

    return 0;
}
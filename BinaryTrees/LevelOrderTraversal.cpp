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

void LevelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            Node* temp=q.front();
            q.pop();
            cout<<temp->val<<" ";

            if(temp->left!=NULL)
                q.push(temp->left);

            if(temp->right!=NULL)
                q.push(temp->right);
        }        
    }

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    LevelOrderTraversal(root);

    return 0;
}
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

void PrintTree(Node* root)
{
    stack<Node*> st;
    st.push(root);

    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();
        cout<<temp->val<<" ";

        if(temp->right!=NULL)
            st.push(temp->right);
        
        if(temp->left!=NULL)
            st.push(temp->left);
    }

    return;
}

int main()
{
    Node *root=NULL;
    CreateBinaryTree(root);
    PrintTree(root);

    return 0;
}
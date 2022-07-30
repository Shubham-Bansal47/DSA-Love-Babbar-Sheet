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

Node* Createtree(Node* root)
{
    cout<<"Enter the Data"<<endl;
    int val;
    cin>>val;
    root=new Node(val);
    
    if(val==-1)
    {
        return NULL;
    }

    cout<<"Enter Data in the left of "<<val<<endl;
    root->left=Createtree(root->left);
    cout<<"Enter Data in the right of "<<val<<endl;
    root->right=Createtree(root->right);

    return root;
}

vector<int> inorderusingstack(Node* root)
{
    vector<int> vec;
    if(root==NULL)
    {
        return vec;
    }

    stack<Node*> st;

    while(1)
    {
        if(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            if(st.empty())
            {
                return vec;
            }
            root=st.top();
            st.pop();
            vec.push_back(root->data);
            root=root->right;
        }
    }
}

vector<int> preorderusingstack(Node* root)
{
    vector<int> vec;
    if(root==NULL)
    {
        return vec;
    }

    stack<Node*> st;
    st.push(root);
    
    while(!st.empty())
    {
        Node* temp=st.top();
        st.pop();
        vec.push_back(temp->data);

        if(temp->right!=NULL)
        {
            st.push(temp->right);
        }
        if(temp->left!=NULL)
        {
            st.push(temp->left);
        }
    }
    return vec;
}

int main()
{
    Node* root=NULL;
    root=Createtree(root);
    vector<int> vec=preorderusingstack(root);
    for(int i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
}
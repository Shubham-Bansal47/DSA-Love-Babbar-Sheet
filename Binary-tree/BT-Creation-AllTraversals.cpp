#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};

Node* createtree(Node *root)
{
    cout<<"Enter Data:"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    
    if(data == -1)
    {
        return NULL;
    }
    
    cout<<"Enter Data in left of Node: "<<data<<endl;
    root->left=createtree(root->left);
    cout<<"Enter Data in right of Node: "<<data<<endl;
    root->right=createtree(root->right);
    
    return root;
}

void levelordertraversal(Node *root) //using queue
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty())
    {
        Node* curr=q.front();
        q.pop();

        if(curr == NULL)
        {
            cout<<endl;
            
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<curr->data<<" ";
            
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

vector<vector<int>>  levelordertraversal2(Node *root) //using queue
{
    vector<vector<int>> ans;
    
    if(root==NULL)
    {
        return ans;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        int size=q.size();
        vector<int> vec;
        
        for(int i=0; i<size; i++)
        {
            Node *curr=q.front();
            q.pop();
            
            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }
            
            vec.push_back(curr->data);
        }

        ans.push_back(vec);
    }

    return ans;
}

void inordertraversal(Node *root) //using recursion
{
    if(root==NULL)
    {
        return;
    } 
    
    inordertraversal(root->left);
    cout<<root->data<<" ";
    inordertraversal(root->right);

}

vector<int> inorderiterative(struct Node* root) //using iteration
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }

    stack<struct Node*> st;
    while(true)
    {
        if(root!=NULL)
        {
            st.push(root);
            root=root->left;
        }
        else
        {
            if(st.empty()==true)
            {
                break;
            }
            root=st.top();
            st.pop();
            ans.push_back(root->data);
            root=root->right;
        }
    }

    return ans;
}

void preordertraversal(Node *root) //using recursion
{
    if(root==NULL)
    {
        return;
    }

    cout<<root->data<<" ";
    preordertraversal(root->left);
    preordertraversal(root->right);

}

vector<int> preorderiterative(struct Node* root) //using iteration
{
    vector<int> ans;
    if(root==NULL)
    {
        return ans;
    }

    stack<struct Node*> st;
    st.push(root);
    while(!st.empty())
    {
        struct Node* curr=st.top();
        st.pop();
        ans.push_back(curr->data);

        if(curr->right!=NULL)
        {
            st.push(curr->right);
        }
        
        if(curr->left!=NULL)
        {
            st.push(curr->left);
        }
    }

    return ans;
}

void postordertraversal(Node *root) //using recursion
{
    if(root==NULL)
    {
        return;
    }

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<" ";
}

int main()
{
    Node *root=NULL;
    root=createtree(root);
    // vector<int> ans=preorderiterative(root);
    // for(int i=0; i<ans.size(); i++)
    // {
    //     cout<<ans[i]<<" ";
    // }

    return 0;
}
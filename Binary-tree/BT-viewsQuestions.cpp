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

struct Node* buildtree(struct Node* root)
{
    cout<<"Enter the Data "<<endl;
    int data;
    cin>>data;
    root=new Node(data);

    if(data==-1)
    {
        return NULL;
    }

    cout<<"Enter the Data in the left of "<<data<<endl;
    root->left=buildtree(root->left);
    cout<<"Enter the Data in the right of "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

vector<int> leftview(struct Node* root)
{
    vector<int> ans;
    
    if(root==NULL)
    {
        return ans;
    }

    queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            struct Node* curr=q.front();
            q.pop();

            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }

            if(i==0)
            {
                ans.push_back(curr->data);
            }
        }
    }
    return ans;
}

vector<int> rightview(struct Node* root)
{
    vector<int> ans;
    
    if(root==NULL)
    {
        return ans;
    }

    queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        for(int i=0; i<size; i++)
        {
            struct Node* curr=q.front();
            q.pop();

            if(curr->left!=NULL)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL)
            {
                q.push(curr->right);
            }

            if(i==size-1)
            {
                ans.push_back(curr->data);
            }
        }
    }
    return ans;
}

vector<vector<int>> zigzagtrav(struct Node* root)
{
    vector<vector<int>> ans;
    if(root==NULL)
    {
        return ans;
    }

    queue<struct Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size=q.size();
        vector<int> vec;
        for(int i=0; i<size; i++)
        {
            struct Node* curr=q.front();
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
    for(int i=0; i<ans.size(); i++)
    {
        if(i%2!=0)
        {
            reverse(ans[i].begin(),ans[i].end());
        }
    }

    return ans;
}

void Boundarytravleft(struct Node* root,vector<int>& ans)
{
    if((root==NULL) || (root->left==NULL && root->right==NULL))
    {
        return;
    }

    ans.push_back(root->data);
    if(root->left!=NULL)
    {
        Boundarytravleft(root->left,ans);
    }
    else
    {
        Boundarytravleft(root->right,ans);
    }

    return;
}

void Boundarytravleaf(struct Node* root,vector<int>& ans)
{
    if(root==NULL)
    {
        return;
    }

    if(root->left==NULL && root->right==NULL)
    {
        ans.push_back(root->data);
        return;
    }

    Boundarytravleaf(root->left,ans);
    Boundarytravleaf(root->right,ans);

    return;
}

void Boundarytravright(struct Node* root,vector<int>& ans)
{
    if((root==NULL) || (root->left==NULL && root->right==NULL))
    {
        return;
    }

    if(root->right!=NULL)
    {
        Boundarytravright(root->right,ans);
    }
    else
    {
        Boundarytravright(root->left,ans);
    }

    ans.push_back(root->data);
    return;
}

void verticalordertrav(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    map<int,map<int,vector<int>>> m;
    queue<pair<struct Node*,pair<int,int>>> q;
    q.push({root,{0,0}});

    while(!q.empty())
    {
        pair<struct Node*,pair<int,int>> temp=q.front();
        struct Node* curr=temp.first;
        int hd=temp.second.first;
        int lvl=temp.second.second;
        q.pop();

        m[hd][lvl].push_back(curr->data);
        if(curr->left!=NULL)
        {
            q.push({curr->left,{hd-1,lvl+1}});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,{hd+1,lvl+1}});
        }
    }

    // for(auto i: m)
    // {
    //     for(int j=0; j<i.second.size(); j++)
    //     {
    //         cout<<i.second[j]<<" ";
    //     }
    // }
    for(auto& i: m)
    {
        for(auto& j: i.second)
        {
            for(auto& k: j.second)
            {
                cout<<k<<" ";
            }
        }
    }

    return;
}

void topview(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    map<int,vector<int>> m;
    queue<pair<struct Node*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<struct Node*,int> temp=q.front();
        struct Node* curr=temp.first;
        int hd=temp.second;
        q.pop();

        m[hd].push_back(curr->data);
        if(curr->left!=NULL)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,hd+1});
        }
    }

    for(auto& i: m)
    {
        for(int j=0; j<i.second.size(); j++)
        {
            if(j==0)
            {
                cout<<i.second[j]<<" ";
                break;
            }
        }
    }

    return;
}

void bottomview(struct Node* root)
{
    if(root==NULL)
    {
        return;
    }

    map<int,vector<int>> m;
    queue<pair<struct Node*,int>> q;
    q.push({root,0});

    while(!q.empty())
    {
        pair<struct Node*,int> temp=q.front();
        struct Node* curr=temp.first;
        int hd=temp.second;
        q.pop();

        m[hd].push_back(curr->data);
        if(curr->left!=NULL)
        {
            q.push({curr->left,hd-1});
        }
        if(curr->right!=NULL)
        {
            q.push({curr->right,hd+1});
        }
    }

    for(auto& i: m)
    {
        for(int j=i.second.size()-1; j>=0; j--)
        {
            if(j==i.second.size()-1)
            {
                cout<<i.second[j]<<" ";
                break;
            }
        }
    }

    return;
}

int main()
{
    struct Node* root=NULL;
    root=buildtree(root); 
    verticalordertrav(root);
    
    return 0;
}
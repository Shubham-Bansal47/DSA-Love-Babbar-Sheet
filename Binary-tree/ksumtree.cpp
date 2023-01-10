#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
  
  Node(int val){
      this->data=val;
      this->left=NULL;
      this->right=NULL;
  }
};

Node* create(Node* root)
{
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1)    return NULL;
    
    cout<<"Enter data in the left tree of "<<data<<endl;
    root->left=create(root->left);
    cout<<"Enter data in the right tree of "<<data<<endl;
    root->right=create(root->right);
    
    return root;
}

void solve(Node* root,int& k,vector<int> path,int &ans)
{
    if(root==NULL) 
        return;
    
    path.push_back(root->data);
    
    solve(root->left,k,path,ans);
    solve(root->right,k,path,ans);
    
    int sum=0;
    for(int i=path.size()-1; i>=0; i--){
        sum+=path[i];
        if(sum==k) 
            ans++;
    }
    
    path.pop_back();
    return;
}

int main()
{
    Node* root=NULL;
    root=create(root);
    int k;
    cin>>k;
    vector<int> path;
    int ans=0;
    solve(root,k,path,ans);
    cout<<ans;
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

void CreateAdjacencyListUndirected(map<int,vector<int>> &mp,int n,int m)
{
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }

    return;
}

void DFS(map<int,vector<int>> &mp,vector<int> &vis,int i,int n,int m)
{
    vis[i]=1;
    cout<<i<<" ";
    for(auto it:mp[i])
    {
        if(!vis[it])
            DFS(mp,vis,it,n,m);
    }

    return;
}

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    map<int,vector<int>> mp;
    CreateAdjacencyListUndirected(mp,n,m);
    vector<int> vis(n,0);
    for(int i=0; i<m; i++)
    {
        if(!vis[i])
            DFS(mp,vis,i,n,m);
    }

    return 0;
}

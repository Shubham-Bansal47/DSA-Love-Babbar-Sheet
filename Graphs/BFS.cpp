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

void BFS(map<int,vector<int>> &mp,vector<int> &vis,int i,int n,int m)
{
    vis[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto it:mp[temp])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
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
            BFS(mp,vis,i,n,m);
    }

    return 0;
}

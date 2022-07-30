#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int,list<pair<int,int>>>& mp,unordered_map<int,bool>& visited,stack<int>& topo,int num)
{
    visited[num]=true;
    for(auto i: mp[num])
    {
        if(!visited[i.first])
        {
            dfs(mp,visited,topo,num);
        }
    }
    topo.push(num);
}

int main()
{
    unordered_map<int,list<pair<int,int>>> mp;
    unordered_map<int,bool> visited;
    vector<pair<int,pair<int,int>>> edges(9);
    stack<int> topo;
    for(int i=0; i<9; i++)
    {
        int n;
        cin>>n;
        int u,v;
        cin>>u>>v;
        pair<int,int> pa={u,v};
        pair<int,pair<int,int>> p={n,pa};
        edges.push_back(p);
        mp[p.first].push_back(p.second);
    }
    for(int i=0; i<6; i++)
    {
        if(!visited[i])
        {
            dfs(mp,visited,topo,i);
        }
    }

    int src=1;
    vector<int> dist(6);
    for(int i=0; i<6; i++)
    {
        dist[i]=INT_MAX;
    }
    dist[src]=0;
    while(!topo.empty())
    {
        int temp=topo.top();
        topo.pop();

        if(dist[temp]!=INT_MAX)
        {
            for(auto i: mp[temp])
            {
                if(dist[temp]+i.second<dist[i.first])
                {
                    dist[i.first]=dist[temp]+i.second;
                }
            }
        }
    }
    for(int i=0; i<dist.size(); i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}
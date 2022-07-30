#include<bits/stdc++.h>
using namespace std;

void createlist(unordered_map<int,list<int>>& mp,vector<pair<int,int>>& edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        mp[u].push_back(v);
    }
    return;
}

bool dfs(unordered_map<int,list<int>>& mp,
    unordered_map<int,bool>& visited,unordered_map<int,bool>& dfsvisited,int num)
{
    visited[num]=true;
    dfsvisited[num]=true;
    for(auto i: mp[num])
    {
        if(!visited[i])
        {
            bool ch=dfs(mp,visited,dfsvisited,i);
            if(ch) return true;
            dfsvisited[i]=false;
        }
        else if(visited[i]==true && dfsvisited[i]==true)
        {
            return true;
        }
    }
    dfsvisited[num]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
    unordered_map<int,list<int>> mp;
    unordered_map<int,bool> visited,dfsvisited;
    createlist(mp,edges);
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ch=dfs(mp,visited,dfsvisited,i);
            if(ch) return 1;
        }
    }
    return 0;
}
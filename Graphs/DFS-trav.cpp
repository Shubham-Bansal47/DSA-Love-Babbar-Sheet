#include<bits/stdc++.h>
using namespace std;

void createlist(unordered_map<int,list<int>>& m,vector<vector<int>>& edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        m[u].push_back(v);
        m[v].push_back(u);
    }
    
    return;
}

void dfstrav(unordered_map<int,list<int>>& m,vector<int>& temp,int num,unordered_map<int,bool>& visited)
{
    temp.push_back(num);
    visited[num]=true;
    for(auto i: m[num])
    {
        if(!visited[i])
        {
            dfstrav(m,temp,i,visited);
        }
    }
    
    return;
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int,list<int>> m;
    vector<vector<int>> ans;
    createlist(m,edges);
    unordered_map<int,bool> visited;
    for(int i=0; i<V; i++)
    {
        if(!visited[i])
        {
            vector<int> temp;
            dfstrav(m,temp,i,visited);
            ans.push_back(temp);
        }
    }
    
    return ans;
}
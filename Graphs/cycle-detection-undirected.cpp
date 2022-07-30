#include<bits/stdc++.h>
using namespace std;

void createlist(unordered_map<int, list<int>>& adj,vector<vector<int>>& edges,int& m)
{
    for(int i=0; i<m; i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return;
}

bool cyclecheckBFS(unordered_map<int, list<int>>& adj,unordered_map<int,bool>& visited,
    unordered_map<int,int>& parent,int num)
{
    queue<int> q;
    q.push(num);
    visited[num]=true;
    parent[num]=-1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        
        for(auto i: adj[temp])
        {
            if(visited[i]==true && i!=parent[temp])
                return true;
            
            else if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
                parent[i]=temp;
            }    
        }
    }
    return false;
}

bool cyclecheckDFS(unordered_map<int,list<int>>& adj,unordered_map<int,bool>& visited,int num,int parent)
{
    visited[num]=true;

    for(auto i: adj[num])
    {
        if(!visited[i])
        {
            bool ch=cyclecheckDFS(adj,visited,i,num);
            if(ch==true)
                return true;
        }
        else if(i!=parent)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int,list<int>> adj;
    createlist(adj,edges,m);
    unordered_map<int,bool> visited;
    // unordered_map<int,int> parent;
    // for(int i=0; i<n; i++)
    // {
    //     if(!visited[i])
    //     {
    //        bool ch=cyclecheckBFS(adj,visited,parent,i);
    //         if(ch==true)
    //         {
    //             return "Yes";
    //         }
    //     }
    // } 
    for(int i=0; i<n; i++)
    {
        if(!visited[i])
        {
            bool ch=cyclecheckDFS(adj,visited,i,-1);
            if(ch==true)
            return "Yes";
        }
    }

    return "No";
}

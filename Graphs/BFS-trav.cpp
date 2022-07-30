#include<iostream>
#include<unordered_map>
#include<queue>
#include<set>
using namespace std;

void createlist(unordered_map<int,set<int>>& mp,int vertex,vector<pair<int,int>> edges)
{
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        mp[u].insert(v);
        mp[v].insert(u);
    }
    
    return;
}

void bfstrav(unordered_map<int,set<int>>& mp,unordered_map<int,bool>& visited,vector<int>& ans,int num)
{
    queue<int> q;
    q.push(num);
    visited[num]=true;
    
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        
        ans.push_back(temp);
        for(auto i: mp[temp])
        {
            if(!visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
    
    return;
}

void printans(vector<int>& ans)
{
    for(auto i: ans)
    {
        cout<<i<<" ";
    }
    
    return;
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int,set<int>> mp;
    createlist(mp,vertex,edges);
    vector<int> ans;
    unordered_map<int,bool> visited;
    for(int i=0; i<vertex; i++)
    {
        if(!visited[i])
        {
            bfstrav(mp,visited,ans,i);
        }
    }
//     printans(ans);
    
    return ans;
}
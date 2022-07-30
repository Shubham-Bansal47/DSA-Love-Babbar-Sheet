#include<bits/stdc++.h>
using namespace std;

void dfstopo(unordered_map<int,list<int>>& mp,
    vector<bool>& visited,
    stack<int>& st,int num)
{
    visited[num]=true;
    for(auto i: mp[num])
    {
        if(!visited[i])
        {
            dfstopo(mp,visited,st,i);
        }
    }
    st.push(num);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> mp;
    vector<bool> visited(v);
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        mp[u].push_back(v);
    }
    for(int i=0; i<v; i++)
    {
        if(!visited[i])
        {
            dfstopo(mp,visited,st,i);
        }
    }
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
        unordered_map<int,list<int>> mp;
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i].first;
            int v=edges[i].second;
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(auto i: mp[temp])
            {
                if(!visited[i])
                {
                    parent[i]=temp;
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        vector<int> ans;
        int par=t;
        ans.push_back(t);
        while(par!=s)
        {
            par=parent[par];
            ans.push_back(par);
        }
        reverse(ans.begin(),ans.end());
        return ans;
}

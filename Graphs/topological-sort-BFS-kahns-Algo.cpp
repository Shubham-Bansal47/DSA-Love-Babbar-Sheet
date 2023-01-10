#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,list<int>> mp;
    vector<int> indegree(v);
    vector<int> ans;
    for(int i=0; i<edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        mp[u].push_back(v);
    }
    for(auto i: mp)
    {
        for(auto j: i.second)
        {
            indegree[j]++;
        }
    }
    queue<int> q;
    for(int i=0; i<v; i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        ans.push_back(temp);
        
        for(auto i: mp[temp])
        {
            indegree[i]--;
            if(indegree[i]==0) q.push(i);
        }
    }
    
    return ans;
}
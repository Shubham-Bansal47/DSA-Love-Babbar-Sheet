#include<bits/stdc++.h>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

void create(unordered_map<int,list<pair<int,int>>>& mp,vector<vector<int>> &vec,int vertices,int edges)
{
    for(int i=0; i<vec.size(); i++)
    {
        int u=vec[i][0];
        int v=vec[i][1];
        int w=vec[i][2];
        mp[u].push_back({v,w});
        mp[v].push_back({u,w});
    }
    return;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    unordered_map<int,list<pair<int,int>>> mp;
    create(mp,vec,vertices,edges);
    set<pair<int,int>> se;
    se.insert({0,source});
    vector<int> distance(vertices);
    for(int i=0; i<vertices; i++)
    {
        distance[i]=INT_MAX;
    }
    distance[source]=0;
    while(!se.empty())
    {
        auto top=*(se.begin());
        se.erase(se.begin());
        int dist=top.first;
        int node=top.second;
        for(auto i: mp[node])
        {
            if(i.second+dist<distance[i.first])
            {
                distance[i.first]=i.second+dist;
                auto record=se.find({distance[i.first],i.first});
                if(record!=se.end())
                {
                    se.erase(record);
                }
                se.insert({distance[i.first],i.first});
            }
        }
    }
    return distance;
}

#include<bits/stdc++.h>
using namespace std;

void CreateAdjacencyListDirected(map<int,vector<int>> &mp,int n,int m)
{
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        mp[a].push_back(b);
    }

    return;
}

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

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    map<int,vector<int>> mp;
    CreateAdjacencyListDirected(mp,n,m);
    CreateAdjacencyListUndirected(mp,n,m);


    return 0;
}

#include<bits/stdc++.h>
using namespace std;

class graphcreate{
    
    private:
    map<int,list<int>> m;

    public:
    void addedge(int u,int v,int direction)
    {
        m[u].push_back(v);
        if(direction!=0)
        {
            m[v].push_back(u);
        }
    }

    void printadjlist()
    {
        for(auto i: m)
        {
            cout<<i.first<<"-> ";
            for(auto j:i.second)
            {
                cout<<j<<", ";
            }
            cout<<endl;
        }
    }
};

int main()
{
    graphcreate g;
    int n;
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    
    int m;
    cout<<"Enter number of edges"<<endl;
    cin>>m;

    for(int i=0; i<m; i++)
    {
        int u,v;
        cin>>u>>v;
        g.addedge(u,v,1);
    }
    g.printadjlist();
}
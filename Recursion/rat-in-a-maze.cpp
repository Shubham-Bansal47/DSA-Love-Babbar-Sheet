#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &vis,vector<vector<int>> &arr,string str,int x,int y,string &ans)
{
    if(x==3 && y==3)
    {
        ans=str;
        return;
    }
    if(x<0 || x>=4 || y<0 || y>=4)
        return;

    if(vis[x][y]==1 || arr[x][y]==0)
        return;

    vis[x][y]=1;
    solve(vis,arr,str+'D',x+1,y,ans);
    solve(vis,arr,str+'U',x-1,y,ans);
    solve(vis,arr,str+'R',x,y+1,ans);
    solve(vis,arr,str+'L',x,y-1,ans);
    
    return;
}

int main()
{
    string str="";
    vector<vector<int>> vis(4,vector<int> (4,0));
    vector<vector<int>> arr(4,vector<int> (4,0));
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            vis[i][j]=0;
            cin>>arr[i][j];
        }    
    }
    int x,y;
    x=0;
    y=0;
    string ans;
    solve(vis,arr,str,x,y,ans);
    cout<<ans;

    return 0;
}
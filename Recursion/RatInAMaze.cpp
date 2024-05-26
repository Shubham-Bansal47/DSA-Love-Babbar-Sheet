#include<bits/stdc++.h>
using namespace std;

void ratinamaze(vector<string> &ans,string temp,vector<vector<int>> &vec,int i,int j,vector<vector<int>> vis)
{
    if(i>=vec.size() || i<0 || j>=vec[0].size() || j<0)
        return;

    if(vec[i][j]==0 || vis[i][j]==1)
        return;

    if(i==vec.size()-1 && j==vec[0].size()-1)
    {
        ans.push_back(temp);
        return;
    }

    vis[i][j]=1;
    temp.push_back('U');
    ratinamaze(ans,temp,vec,i-1,j,vis);
    temp.pop_back();
    temp.push_back('R');
    ratinamaze(ans,temp,vec,i,j+1,vis);
    temp.pop_back();
    temp.push_back('D');
    ratinamaze(ans,temp,vec,i+1,j,vis);
    temp.pop_back();
    temp.push_back('L');
    ratinamaze(ans,temp,vec,i,j-1,vis);
    temp.pop_back();
    vis[i][j]=0;

    return;
}

int main()
{
    int n,m;
    cin>>n;
    cin>>m;
    
    vector<vector<int>> vec(n,vector<int>(m,0));
    vector<vector<int>> vis(n,vector<int>(m,0));
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>vec[i][j];
    }

    string temp="";
    vector<string> ans;
    ratinamaze(ans,temp,vec,0,0,vis);

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}
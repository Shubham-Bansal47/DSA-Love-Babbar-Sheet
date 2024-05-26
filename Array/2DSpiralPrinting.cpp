#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    }

    int l,r,u,d;
    l=0;
    r=m-1;
    u=0;
    d=n-1;
    int direction=1;
    vector<int> ans;
    while(l<=r && u<=d)
    {
        if(direction==1)
        {
            for(int i=l; i<=r; i++)
                ans.push_back(arr[u][i]);

            u++;
        }
        else if(direction==2)
        {
            for(int i=u; i<=d; i++)
                ans.push_back(arr[i][r]);

            r--;
        }
        else if(direction==3)
        {
            for(int i=r; i>=l; i--)
                ans.push_back(arr[d][i]);

            d--;
        }
        else
        {
            for(int i=d; i>=u; i--)
                ans.push_back(arr[i][l]);

            l++;
        }
        direction++;
        if(direction>4)
            direction=1;
    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}
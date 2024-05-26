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

    vector<int> ans;
    int x=0;
    for(int i=0; i<m; i++)
    {
        if(x%2==0)
        {
            for(int j=0; j<n; j++)
                ans.push_back(arr[j][i]);
            x++;
        }
        else
        {
            for(int j=n-1; j>=0; j--)
                ans.push_back(arr[j][i]);
            x++;
        }
    }

    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}
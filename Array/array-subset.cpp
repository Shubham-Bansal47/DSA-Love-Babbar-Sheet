#include<bits/stdc++.h>
using namespace std;

string isSubset(int a1[], int a2[], int n, int m) 
{
    int i,j;
    unordered_map<int,int> mp;
    for(i=0; i<n; i++)
    {
        mp[a1[i]]++;
    }
    for(i=0; i<m; i++)
    {
        if(mp[a2[i]]==0)
        {
            return "No";
        }
        mp[a2[i]]--;
    }
    return "Yes";
}

int main()
{
    int n,m;
    cin>>n>>m;
    int a1[n],a2[m];
    for(int i=0; i<n; i++)
    {
        cin>>a1[i];
    }
    for(int i=0; i<n; i++)
    {
        cin>>a2[i];
    }
    cout<<isSubset(a1,a2,n,m);
}
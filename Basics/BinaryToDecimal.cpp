#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int ans=0;
    int cnt=0;
    for(int i=n-1; i>=0; i--)
    {
        ans+=(vec[i]*pow(2,cnt));
        cnt++;
    }

    cout<<ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> ans;
    while(n>0)
    {
        int rem=n%2;
        ans.push_back(rem);
        n=n/2;
    }

    reverse(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";

    return 0;
}
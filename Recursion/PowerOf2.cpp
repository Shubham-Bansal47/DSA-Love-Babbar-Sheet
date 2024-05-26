#include<bits/stdc++.h>
using namespace std;

int findPower(int n)
{
    if(n==0)
        return 1;

    return findPower(n-1)*2;
}

int main()
{
    int n;
    cin>>n;
    int ans=findPower(n);
    cout<<ans;

    return 0;
}
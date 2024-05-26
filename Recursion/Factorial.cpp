#include<bits/stdc++.h>
using namespace std;

int findfactorial(int n)
{
    if(n==0 || n==1)
        return 1;

    return n*findfactorial(n-1);
}

int main()
{
    int n;
    cin>>n;
    int ans=findfactorial(n);
    cout<<ans;

    return 0;
}
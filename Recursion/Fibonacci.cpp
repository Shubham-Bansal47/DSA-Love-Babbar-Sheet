#include<bits/stdc++.h>
using namespace std;
// 0 1 1 2 3 5 8 11
int findFibonacci(int n)
{
    if(n<=0)
        return 0;
    if(n==1)
        return 1;

    return findFibonacci(n-1) + findFibonacci(n-2);
}

int main()
{
    int n;
    cin>>n;
    int ans=findFibonacci(n);
    cout<<ans;

    return 0;
}
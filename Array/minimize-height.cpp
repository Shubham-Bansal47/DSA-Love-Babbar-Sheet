#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    FastIO;
    int i,j,n,k;
    cin>>n>>k;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];
    int max1,min1;
    for(i=1; i<n; i++)
    {
        if(arr[i]>=k)
        {
            max1=max(arr[i-1]+k,arr[n-1]-k);
            min1=min(arr[0]+k,arr[i]-k);
            ans=min(ans,max1-min1);
        }
    }
    cout<<ans;
}
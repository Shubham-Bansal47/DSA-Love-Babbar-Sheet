#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int sum=0,max1=arr[0];
    for(i=0; i<n; i++)
    {
        sum+=arr[i];
        max1=max(sum,max1);
        if(sum<0)
        {
            sum=0;
        }
    }
    cout<<max1;
}
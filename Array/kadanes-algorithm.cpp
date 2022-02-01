#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

ll maxSubarraySum(ll arr[], int n)
{        
        long long int max1=arr[0],sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            max1=max(sum,max1);
            if(sum<0)
            {
                sum=0;
            }
        }
        return max1;
    }

int main()
{
    
    FastIO;
    ll i,j,n;
    cin>>n;
    ll arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<maxSubarraySum(arr,n);
    
    return 0;
}
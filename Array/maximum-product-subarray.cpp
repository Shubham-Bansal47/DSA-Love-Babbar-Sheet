#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

ll maxSubarrayproduct(ll arr[], int n)
{        
        long long int max1=arr[0],min1=arr[0],ans=arr[0];
        for(int i=1; i<n; i++)
        {
            if(arr[i]<0)
            {
                swap(max1,min1);
            }
            max1=max(arr[i],max1*arr[i]);
            min1=min(arr[i],min1*arr[i]);
            ans=max(ans,max1);
        }
        return ans;
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
    cout<<maxSubarrayproduct(arr,n);
    
    return 0;
}
#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n,k,sum=0;
    cin>>n>>k;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    unordered_map<int,int> m;
    for(i=0; i<n; i++)
    {
        if(m[k-arr[i]]>0)
        {
            sum+=m[k-arr[i]];
        }
        m[arr[i]]++;
    }
    cout<<sum;
}
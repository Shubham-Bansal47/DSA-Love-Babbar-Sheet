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
    j=n/k;
    unordered_map<int,int> m;
    for(i=0; i<n; i++)
    {
        m[arr[i]]++;
    }
    for(auto it: m)
    {
        if(it.second>j)
        {
            cout<<it.first<<" occurs "<<it.second<<" times\n";
        }
    }
}
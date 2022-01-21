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
    int sum=0;
    i=0;
    while(1)
    {
        map<int,int> m;
        if(arr[i]>=n-i-1)
        {
            ++sum;
            cout<<sum;
            return 0;
        }
        for(j=1; j<=arr[i]; j++)
        {
            m[arr[i+j]]=i+j;
        }
        ++sum;
        auto it=m.end();
        --it;
        i=(*it).second;
    }
}
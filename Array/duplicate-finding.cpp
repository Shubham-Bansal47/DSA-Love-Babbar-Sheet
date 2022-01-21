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
    int arr[n+1];
    for(i=0; i<=n; i++)
    {
        cin>>arr[i];
    }
    map<int,int> m;
    for(i=0; i<=n; i++)
    {
        m[arr[i]]++;
        if(m[arr[i]]>1)
        {
            cout<<arr[i];
            return 0;
        }
    }
}
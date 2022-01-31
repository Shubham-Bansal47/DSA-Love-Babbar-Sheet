#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    ll i,j,n,y=-1;
    cin>>n;
    ll l=0,h=n;
    ll m=(l+h)/2;
    while(l<=h)
    {
        ll x=m*m;
        if(x<n)
        {
            y=m;
            l=m+1;
        }
        else if(x>n)
        {
            h=m-1;
        }
        else
        {
            y=m;
            cout<<y-1;
            return 0;
        }
        m=(l+h)/2;
    }
    cout<<y;
    return 0;
}
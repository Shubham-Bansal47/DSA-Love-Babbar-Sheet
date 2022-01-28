#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n,x,y=-1,z=-1;
    cin>>n>>x;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int l=0,h=n-1;
    int m=(l+h)/2;
    while(l<=h)
    {
        if(arr[m]<x)
        {
            l=m+1;
        }
        else if(arr[m]>x)
        {
            h=m-1;
        }
        else
        {
            y=m;
            h=m-1;
        }
        m=(l+h)/2;
    }
    l=0,h=n-1;
    m=(l+h)/2;
    while(l<=h)
    {
        if(arr[m]<x)
        {
            l=m+1;
        }
        else if(arr[m]>x)
        {
            h=m-1;
        }
        else
        {
            z=m;
            l=m+1;
        }
        m=(l+h)/2;
    }
    cout<<y<<" "<<z;
}
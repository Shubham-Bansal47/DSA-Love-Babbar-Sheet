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
    j=arr[n-1];
    for(i=n-1; i>0; i--)
    {
        arr[i]=arr[i-1];
    }    
    arr[0]=j;
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}
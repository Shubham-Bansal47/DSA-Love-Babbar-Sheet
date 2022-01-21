#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n,k,c1=0,c2=0,c3=0;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]==0) ++c1;
        else if(arr[i]==1) ++c2;
        else ++c3;
    }
    for(i=0; i<n; i++)
    {
        if(c1!=0)
        {
            arr[i]=0;
            --c1;
        }
        else if(c2!=0)
        {
            arr[i]=1;
            --c2;
        }
        else
        {
            arr[i]=2;
            --c3;
        }
    }
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}
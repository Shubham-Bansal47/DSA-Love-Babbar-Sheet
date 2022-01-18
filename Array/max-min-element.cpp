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
    int min1=INT_MAX,max1=INT_MIN;
    for(i=0; i<n; i++)
    {
        if(arr[i]>max1)
        {
            max1=arr[i];
        }
        if(arr[i]<min1)
        {
            min1=arr[i];
        }
    }
    cout<<min1<<" "<<max1;
}
#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n,temp;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    if(n==1)
    {
        cout<<arr[0];
        return 0;
    }
    int low=0,high=n-1;
    while(low<high)
    {
        if(arr[low]<0 && arr[high]<0) ++low;
        else if(arr[low]>=0 && arr[high]>=0) --high;
        else if(arr[low]<0 && arr[high]>=0)
        {
            --high;
            ++low;
        }
        else
        {
            temp=arr[low];
            arr[low]=arr[high];
            arr[high]=temp;
        }
    }
    for(i=0; i<n; i++)
    {
        cout<<arr[i]<<" "; 
    } 
}
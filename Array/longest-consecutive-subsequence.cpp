#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
    {
        int i,count=1,ans=1;
        sort(arr,arr+N);
        for(i=1; i<N; i++)
        {
            if(arr[i]==arr[i-1])
            {
                continue;
            }
            else if(arr[i]-arr[i-1]==1)
            {
                ++count;
                ans=max(ans,count);
            }
            else
            {
                count=1;
            }
        }
        return ans;
    }

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
    // sort(arr,arr+n);
    cout<<findLongestConseqSubseq(arr,n);
}
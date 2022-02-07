#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) 
{
	    int i=n-1,j=0;
        while(i>=0 && j<m)
        {
            if(arr1[i]>arr2[j])
            {
                swap(arr1[i],arr2[j]);
            }
            --i;
            ++j;
        }
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        // int i=0,j=0;
        // while(j<m)
	    // {
	    //     if(arr1[i]>arr2[j])
	    //     {
	    //         swap(arr1[i],arr2[j]);
	    //         ++i;
	    //         if(i==n)
	    //         {
	    //             i=0;
	    //             ++j;
	    //         }
	    //         continue;
	    //     }
	    //     ++i;
	    //     if(i==n)
	    //     {
	    //         i=0;
	    //         ++j;
	    //     }
	    // }
        // sort(arr2,arr2+m);
        // return;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int arr1[n],arr2[m];
    for(int i=0; i<n; i++)
    {
        cin>>arr1[i];
    }
    for(int i=0; i<m; i++)
    {
        cin>>arr2[i];
    }
    merge(arr1,arr2,n,m);
    for(int i=0; i<n; i++)
    {
        cout<<arr1[i]<<" ";
    }
    for(int i=0; i<m; i++)
    {
        cout<<arr2[i]<<" ";
    }
}
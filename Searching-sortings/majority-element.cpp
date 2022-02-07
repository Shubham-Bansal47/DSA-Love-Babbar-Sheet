#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int majorityElement(int a[], int size)
{     
    if(size==1)
    {
        return a[0];
    }
    int i,j=-1,sum=1;
    sort(a,a+size);
    for(i=1; i<size; i++)
    {
        if(a[i]==a[i-1])
        {
            ++sum;
            if(sum>size/2)
            {
                   j=a[i];
                   return j;
            }
        }
        else
        {
            sum=1;
        }
    }
    return j;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    cout<<majorityElement(a,n);
}
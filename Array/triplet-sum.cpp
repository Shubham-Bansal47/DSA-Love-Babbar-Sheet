#include<bits/stdc++.h>
using namespace std;

bool find3Numbers(int A[], int n, int X)
{
    sort(A,A+n);
    int i;
    if(n<3)
    {
        return false;
    }
    for(i=0; i<n-2; i++)
    {
        int j,k;
        j=i+1;
        k=n-1;
        while(j<k)
        {
            if(A[j]+A[k]+A[i]<X)
            {
                ++j;
            }
            else if(A[i]+A[j]+A[k]>X)
            {
                --k;
            }
            else
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,X;
    cin>>n>>X;
    int A[n];
    for(int i=0; i<n; i++)
    {
        cin>>A[i];
    }
    cout<<find3Numbers(A,n,X);
}
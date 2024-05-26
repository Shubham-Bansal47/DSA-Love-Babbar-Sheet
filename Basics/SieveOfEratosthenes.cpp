#include<bits/stdc++.h>
using namespace std;

// Algorithm used to calculate prime numbers in a range with best time complexity

int main()
{
    int n;
    cin>>n;
    vector<bool> sieve(n+1,true);
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(sieve[i])
        {
            int j=i*2;
            while(j<=n)
            {
                sieve[j]=false;
                j=j+i;
            }
        }
    }

    for(int i=0; i<=n; i++)
    {
        if(sieve[i])
            cout<<i<<" ";
    }

    return 0;
}
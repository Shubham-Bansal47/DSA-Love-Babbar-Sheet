#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,d;
    c=a;
    d=b;
    int gcd;
    cin>>a>>b;
    while(a!=b)
    {
        if(a>=b)
            a=a-b;
        else 
            b=b-a;
    }
    if(a==0)    
        gcd=b;
    else if(b==0)
        gcd=a;

    int lcm;
    lcm=(c*d)/gcd;
    cout<<gcd<<" "<<lcm;

    return 0;
}
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
    char temp;
    cin>>n;
    string s;
    cin>>s;
    for(i=0; i<s.size()/2; i++)
    {
        if(s[i]!=s[n-1-i])
        {
            cout<<"No";
            return 0;
        }    
    }
    cout<<"Yes";
}
#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j;
    string s,s1;
    cin>>s;
    cin>>s1;
    if(s.size()!=s1.size())
    {
        cout<<"No";
    }
    s+=s;
    for(i=0; i<s.size()/2; i++)
    {
        string s2;
        s2=s.substr(i,(s.size()/2));
        if(s2==s1)
        {
            cout<<"Yes";
            return 0;
        }
    }
    cout<<"No";
}
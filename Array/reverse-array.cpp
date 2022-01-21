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
    string s;
    cin>>s;
    for(i=0; i<s.size()/2; i++)
    {
        string s1="";
        s1+=s[i];
        s[i]=s[s.size()-1-i];
        s[s.size()-1-i]=s1[0];
    }
    cout<<s;
}
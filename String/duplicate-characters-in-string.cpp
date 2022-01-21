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
    unordered_map<char,int> m;
    for(i=0; i<s.size(); i++)
    {
        m[s[i]]++;
    }
    for(auto it: m)
    {
        if(it.second>1)
        {
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
}
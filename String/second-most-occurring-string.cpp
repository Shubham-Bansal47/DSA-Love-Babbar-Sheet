#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

bool cmp( pair<string,int> a, pair<string,int> b)
{
          return a.second > b.second;
}

int main()
{
    FastIO;
    ll t;
    cin>>t;
    up:
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0; i<n; i++)
        {
                  cin>>arr[i];
        }
        unordered_map<string,int> m;
        for(int i=0; i<n; i++)
        {
            m[arr[i]]++;
        }
        vector<pair<string,int>> v(m.begin(),m.end());
        sort(v.begin(),v.end(),cmp);
          for(int i=0; i<v.size(); i++)
          {
                if(v[0].second>v[i].second)
                {
                    cout<<v[i].first;
                    return 0;
                }
          }
    }
}

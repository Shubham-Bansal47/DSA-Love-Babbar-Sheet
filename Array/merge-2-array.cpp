#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    FastIO;
    int i,j,n,m;
    cin>>n>>m;
    int arr[n],arr1[m];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<m; i++)
    {
        cin>>arr1[i];
    }
    vector<int> vec;
    for(i=0; i<n; i++)
    {
        vec.push_back(arr[i]);
    }
    for(i=0; i<m; i++)
    {
        vec.push_back(arr1[i]);
    }
    sort(vec.begin(),vec.end());
    for(i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }

}
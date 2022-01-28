#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    vector<int> vec;
    int i,j,n;
    cin>>n;
    int arr[n];
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<n; i++)
    {
        if((i+1)==arr[i])
        {
            vec.push_back(i+1);
        }
    }
    for(i=0; i<vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
}
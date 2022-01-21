#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    
    FastIO;
    int i,j,n1,n2;
    cin>>n1>>n2;
    int arr1[n1],arr2[n2];
    for(i=0; i<n1; i++)
    {
        cin>>arr1[i];
    }
    for(i=0; i<n2; i++)
    {
        cin>>arr2[i];
    }
    vector<int> vec;
    for(i=0; i<n1; i++)
    {
        vec.push_back(arr1[i]);
    }
    for(i=0; i<n2; i++)
    {
        vec.push_back(arr2[i]);
    }
    sort(vec.begin(),vec.end());
    if(vec.size()%2!=0)
    {
        cout<<vec[vec.size()/2];
    }
    else
    {
        j=(vec[vec.size()/2]+vec[(vec.size()/2)-1])/2;
        cout<<j;
    }
}
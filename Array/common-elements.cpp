#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

int main()
{
    FastIO;
    int i,j,n1,n2,n3;
    cin>>n1>>n2>>n3;
    int arr1[n1],arr2[n2],arr3[n3];
    set<int> s1,s2,s3;
    for(i=0; i<n1; i++)
    {
        cin>>arr1[i];
        s1.insert(arr1[i]);
    }
    for(i=0; i<n2; i++)
    {
        cin>>arr2[i];
        s2.insert(arr2[i]);
    }
    for(i=0; i<n3; i++)
    {
        cin>>arr3[i];
        s3.insert(arr3[i]);
    }
    map<int,int> m;
    for(auto it: s1)
    {
        m[it]++;
    }
    for(auto it: s2)
    {
        m[it]++;
    }
    for(auto it: s3)
    {
        m[it]++;
    }
    int sum=0;
    vector<int> vec;
    for(auto it: m)
    {
        if(it.second==3)
        {
            vec.push_back(it.first);
        }
    }
    for(auto it: vec)
    {
        cout<<it<<" ";
    }
}
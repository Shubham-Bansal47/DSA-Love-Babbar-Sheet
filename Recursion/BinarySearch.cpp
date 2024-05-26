#include<bits/stdc++.h>
using namespace std;

bool findKey(int s,int e,vector<int> &vec,int &key)
{
    if(s>e)
        return false;

    int mid=s+(e-s)/2;
    if(vec[mid]==key)
        return true;
    else if(vec[mid]>key)
        return findKey(s,mid-1,vec,key);
    else
        return findKey(mid+1,e,vec,key);
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int key;
    cin>>key;

    int s,e;
    s=0;
    e=vec.size()-1;
    bool ans=findKey(s,e,vec,key);
    cout<<ans;

    return 0;
}
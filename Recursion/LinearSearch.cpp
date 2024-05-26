#include<bits/stdc++.h>
using namespace std;

bool findKey(vector<int> &vec,int i,int &key)
{
    if(i<0)
        return false;

    if(vec[i]==key)
        return true;

    return findKey(vec,i-1,key);
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
    
    int i=vec.size()-1;
    bool ans=findKey(vec,i,key);
    cout<<ans;

    return 0;
}
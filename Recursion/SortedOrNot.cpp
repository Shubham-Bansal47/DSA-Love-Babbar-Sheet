#include<bits/stdc++.h>
using namespace std;

bool findSorted(vector<int> &vec,int i)
{
    if(i<=0)
        return true;

    if(vec[i]<vec[i-1])
        return false;

    return findSorted(vec,i-1);
}

int main()
{
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
        cin>>vec[i];

    int i=vec.size()-1;
    bool ans=findSorted(vec,i);
    cout<<ans;

    return 0;
}
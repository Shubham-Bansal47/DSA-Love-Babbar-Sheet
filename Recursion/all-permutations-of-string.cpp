#include<bits/stdc++.h>
using namespace std;

void finding(string s,vector<string>& vec,int i)
{
    if(i==s.size()-1)
    {
        vec.push_back(s);
        return;
    }
    for(int j=i; j<s.size(); j++)
    {
        swap(s[i],s[j]);
        finding(s,vec,i+1);
        swap(s[i],s[j]);
    }

    return;
}

int main()
{
    string s;
    cin>>s;
    vector<string> vec;
    int i=0;
    finding(s,vec,i);

    for(auto i: vec)
    {
        cout<<i<<" ";
    }

    return 0;
}
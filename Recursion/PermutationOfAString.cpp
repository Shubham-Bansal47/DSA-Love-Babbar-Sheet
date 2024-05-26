#include<bits/stdc++.h>
using namespace std;

void permutationsofstring(vector<string> &ans,string &s,int i)
{
    if(i>=s.size())
    {
        ans.push_back(s);
        return;
    }

    for(int j=i; j<s.size(); j++)
    {
        swap(s[i],s[j]);
        permutationsofstring(ans,s,i+1);
        swap(s[i],s[j]);
    }

    return;
}

int main()
{
    string s;
    cin>>s;
    vector<string> ans;
    permutationsofstring(ans,s,0);
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}
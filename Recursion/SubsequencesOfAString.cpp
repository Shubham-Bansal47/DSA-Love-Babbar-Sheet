#include<bits/stdc++.h>
using namespace std;

void subsequenceofstring(vector<string> &ans,string temp,string &s,int i)
{
    if(i>=s.size())
    {
        ans.push_back(temp);
        return;
    }

    subsequenceofstring(ans,temp,s,i+1);
    temp.push_back(s[i]);
    subsequenceofstring(ans,temp,s,i+1);

    return;
}

int main()
{
    string s;
    cin>>s;
    string temp="";
    vector<string> ans;
    subsequenceofstring(ans,temp,s,0);
    sort(ans.begin(),ans.end());
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<endl;

    return 0;
}
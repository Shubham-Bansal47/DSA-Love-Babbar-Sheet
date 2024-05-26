#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    string ans="";
    vector<string> vec;
    string str;
    stringstream ss(s);
    
    while(ss>>str)
        vec.push_back(str);
    
    for(int i=vec.size()-1; i>=0; i--)
    {
        ans+=vec[i];
        ans+=" ";
    }
    ans.pop_back();
    cout<<ans;

    return 0;
}
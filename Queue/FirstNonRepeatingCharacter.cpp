#include<bits/stdc++.h>
using namespace std;

string FirstNonRepeatingCharacter(string s)
{// a a b c
    string ans="";
    queue<int> q;
    unordered_map<char,int> mp;
    for(int i=0; i<s.size(); i++)
    {   
        mp[s[i]]++;
        q.push(s[i]);
        while(!q.empty() && mp[q.front()]>1)
            q.pop();

        if(!q.empty())
            ans.push_back(q.front());
        else
            ans.push_back('#');
    }

    return ans;
}

int main()
{
    string s;
    cin>>s;
    string ans=FirstNonRepeatingCharacter(s);
    cout<<ans;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

/* Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.
*/

int main()
{
    bool check=false;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    if(s1.size()>s2.size())
    {
        check=false;
        cout<<check;
        return 0;
    }

    map<char,int> m1,m2;
    for(int i=0; i<s1.size(); i++)
        m1[s1[i]]++;

    for(int i=0; i<s1.size(); i++)
        m2[s2[i]]++;

    if(m1==m2)
    {
        check=true;
        cout<<check;
        return 0;
    }
    
    for(int i=s1.size(); i<s2.size(); i++)
    {
        int index=i-s1.size();
        m2[s2[index]]--;
        if(m2[s2[index]]==0)
            m2.erase(s2[index]);

        m2[s2[i]]++;

        if(m1==m2)
        {
            check=true;
            cout<<check;
            return 0;
        }
    }
    cout<<check;

    return 0;
}
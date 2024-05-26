#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    bool check=true;
    for(int i=0; i<s.size()/2; i++)
    {
        if(s[i]!=s[s.size()-1-i])
        {
            check=false;
            break;
        }
    }
    cout<<check;

    return 0;
}
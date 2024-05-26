#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int i=0;
    while(s.size()>1 && i>=0 && i+1<s.size())
    {
        if(s[i]==s[i+1])
        {
            s.erase(s.begin()+i,s.begin()+i+2);
            i--;
            if(i<0)
                i=0;
            continue;
        }
        else
            i++;
    }
    cout<<s;

    return 0;
}
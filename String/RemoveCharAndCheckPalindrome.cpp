#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin,s);
    string str="";
    for(int i=0; i<s.size(); i++)
    {
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
            str+=toupper(s[i]);
    }
    
    bool check=true;
    for(int i=0; i<str.size()/2; i++)
    {
        if(str[i]!=str[str.size()-1-i])
        {
            check=false;
            break;
        }
    }
    cout<<check;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    while(!s1.empty() && s1.find(s2)<s1.size())
        s1.erase(s1.find(s2),s2.size());

    cout<<s1;

    return 0;
}
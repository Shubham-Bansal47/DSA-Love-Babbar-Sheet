#include<bits/stdc++.h>
using namespace std;

void ReverseString(string &str,int s,int e)
{
    if(s>e)
        return;

    swap(str[s],str[e]);

    return ReverseString(str,s+1,e-1);
}

int main()
{
    string str;
    cin>>str;
    int s,e;
    s=0;
    e=str.size()-1;
    ReverseString(str,s,e);
    cout<<str;

    return 0;
}
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

char* reverse(char *S, int len)
{
    stack<char> se;
    // char s[len];
    for(int i=0; i<len; i++)
    {
        se.push(S[i]);
    }
    int x=0;
    while(!se.empty())
    {
        S[x]=se.top();
        se.pop();
        ++x;
    }
    return S; 
}

int main()
{
    int len,i;
    cin>>len;
    char S[len];
    for(i=0; i<len; i++)
    {
        cin>>S[i];
    }
    reverse(S,len);
    for(i=0; i<len; i++)
    {
        cout<<S[i]<<" ";
    }
    return 0;
}
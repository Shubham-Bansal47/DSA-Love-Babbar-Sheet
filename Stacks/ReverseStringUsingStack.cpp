#include<bits/stdc++.h>
using namespace std;

void ReverseStringUsingStack(stack<int> &st,string &s)
{
    for(int i=0; i<s.size(); i++)
        st.push(s[i]);

    int i=0;
    while(!st.empty())
    {
        s[i++]=st.top();
        st.pop();
    }

    return;
}

int main()
{
    stack<int> st;
    string s;
    cin>>s;
    ReverseStringUsingStack(st,s);
    cout<<s;

    return 0;
}
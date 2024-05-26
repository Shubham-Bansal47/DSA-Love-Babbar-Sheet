#include<bits/stdc++.h>
using namespace std;

bool ParenthesisCheck(string s)
{
    stack<int> st;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            st.push(s[i]);
        else if(s[i]==')')
        {
            if(st.top()=='(')
                st.pop();
            else
                return false;
        }
        else if(s[i]=='}')
        {
            if(st.top()=='{')
                st.pop();
            else
                return false;
        }
        else if(s[i]==']')
        {
            if(st.top()=='[')
                st.pop();
            else
                return false;
        }
    }

    return st.empty();
}

int main()
{
    string s;
    cin>>s;
    bool check=ParenthesisCheck(s); 
    cout<<check;

    return 0;
}
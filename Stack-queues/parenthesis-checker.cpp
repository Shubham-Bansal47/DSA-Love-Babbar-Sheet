#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

bool ispar(string x)
    {
        int i,j;
        stack<char> st;
        string s;
        for(i=0; i<x.size(); i++)
        {
            if(st.empty())
            {
                st.push(x[i]);
            }
            else
            {
                if((st.top()=='(' && x[i]==')') || (st.top()=='[' && x[i]==']') || (st.top()=='{' && x[i]=='}'))
                {
                    st.pop();
                }
                else
                {
                    st.push(x[i]);
                }
            }
        }
        return st.empty();
    }

int main()
{
    string x;
    cin>>x;
    cout<<ispar(x);
    return 0;
}    
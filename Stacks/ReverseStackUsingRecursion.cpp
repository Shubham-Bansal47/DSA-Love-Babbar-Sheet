#include<bits/stdc++.h>
using namespace std;

void InsertAtBottomStack(stack<int> &st,int &temp)
{
    if(st.size()==0)
    {
        st.push(temp);
        return;
    }

    int x=st.top();
    st.pop();
    InsertAtBottomStack(st,temp);
    st.push(x);

    return;
}

void ReverseStackUsingRecursion(stack<int> &st)
{
    if(st.size()==1)
        return;
    
    int temp=st.top();
    st.pop();
    ReverseStackUsingRecursion(st);
    InsertAtBottomStack(st,temp);

    return;
}

void PrintStack(stack<int> st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    ReverseStackUsingRecursion(st);
    PrintStack(st);

    return 0;
}
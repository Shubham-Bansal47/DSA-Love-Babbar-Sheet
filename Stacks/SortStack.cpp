#include<bits/stdc++.h>
using namespace std;

void InnerSort(stack<int> &st,int &temp)
{
    if(st.size()==0)
    {
        st.push(temp);
        return;
    }

    if(st.top()>temp)
    {
        int x=st.top();
        st.pop();
        InnerSort(st,temp);
        st.push(x);
    }
    else
        st.push(temp);
    
    return;
}
// 5 4 3 2
void SortStack(stack<int> &st)
{
    if(st.size()<=1)
        return;
    
    int temp=st.top();
    st.pop();
    SortStack(st);
    InnerSort(st,temp);
    
    return;
}

void PrintStack(stack<int> &st)
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
    st.push(5);
    st.push(2);
    st.push(4);
    st.push(3);
    SortStack(st);
    PrintStack(st);

    return 0;
}
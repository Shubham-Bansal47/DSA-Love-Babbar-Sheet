#include<bits/stdc++.h>
using namespace std;

void InsertAtBottomStack(stack<int> &st,int &x)
{
    if(st.size()==0)
    {
        st.push(x);
        return;
    }

    int temp=st.top();
    st.pop();
    InsertAtBottomStack(st,x);
    st.push(temp);

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
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout<<"Enter element you want to insert"<<endl;
    int x;
    cin>>x;
    InsertAtBottomStack(st,x);
    PrintStack(st);

    return 0;
}
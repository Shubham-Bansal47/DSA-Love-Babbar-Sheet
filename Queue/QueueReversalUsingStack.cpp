#include<bits/stdc++.h>
using namespace std;

void QueueReversal(queue<int> &q)
{
    stack<int> st;
    while(!q.empty())
    {    
        st.push(q.front());
        q.pop();
    }

    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    return;
}

void PrintQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return;
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    QueueReversal(q);

    PrintQueue(q);

    return 0;
}
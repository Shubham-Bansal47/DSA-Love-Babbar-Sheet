#include<bits/stdc++.h>
using namespace std;

void ReverseFirstKElements(queue<int> &q,int k)
{
    stack<int> st;
    k=k%q.size();
    int t=k;
    while(t--)
    {   
        st.push(q.front());
        q.pop();
    }
    int qsize=q.size();
    // 1 2 3 4 5 6
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while(qsize--)
    {
        q.push(q.front());
        q.pop();
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
    cout<<"Enter value of K"<<endl;
    int n,k;
    cin>>k;
    cin>>n;
    queue<int> q;
    while(n--)
    {
        int temp;
        cin>>temp;
        q.push(temp);
    }    

    ReverseFirstKElements(q,k);
    PrintQueue(q);

    return 0;
}
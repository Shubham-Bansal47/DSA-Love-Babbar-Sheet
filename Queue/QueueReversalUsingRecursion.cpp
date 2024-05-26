#include<bits/stdc++.h>
using namespace std;

void ReverseQueue(queue<int> &q)
{
    if(q.size()==0)
        return;

    int temp=q.front();
    q.pop();
    ReverseQueue(q);
    q.push(temp);

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
    ReverseQueue(q);

    PrintQueue(q);

    return 0;
}
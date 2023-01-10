#include<bits/stdc++.h>
using namespace std;

void insertbottom(stack<int>& stack,int val)
{
    if(stack.empty())
    {
        stack.push(val);
        return;
    }
    int val1=stack.top();
    stack.pop();
    insertbottom(stack,val);
    stack.push(val1);
}

void solve(stack<int>& stack)
{
    if(stack.empty())
    {
        return;
    }
    int val=stack.top();
    stack.pop();
    solve(stack);
    
    insertbottom(stack,val);
}

void reverseStack(stack<int> &stack) {
    solve(stack);
    return;
}

int main()
{
    stack<int> stack;
    reverseStack(stack);
    return;
}
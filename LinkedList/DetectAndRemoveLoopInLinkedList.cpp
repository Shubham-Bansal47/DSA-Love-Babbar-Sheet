#include<bits/stdc++.h>
using namespace std;

// Floyd's Cycle Detection Algorithm

class Node{
    public:
        int val;
        Node *next;

        Node(int value)
        {
            this->val=value;
            this->next=NULL;
        }
};

void CreateCircularLinkedList(Node* &start,Node* &last,int loop)
{
    int x;
    x=1;
    while(x)
    {
        int val;
        cin>>val;
        Node *tempnode=new Node(val);
        if(start==NULL)
        {
            start=tempnode;
            last=tempnode;
        }
        else
        {
            last->next=tempnode;
            last=last->next;
            last->next=start;
        }
        cout<<"Do you want to enter more nodes?"<<endl;
        cin>>x;
    }
    Node* temp=start;
    while(loop--)
        temp=temp->next;

    last->next=temp;

    return;
}

void DetectLoop(Node* start)
{
    Node *slow,*fast;
    slow=start;
    fast=start;
    bool check=false;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast)
        {
            check=true;
            break;
        }
    }
    if(check==true)
    {
        if(slow!=start)
        {
            slow=start;
            while(slow->next!=fast->next)
            {
                slow=slow->next;
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else
        {
            while(slow->next!=start)
                slow=slow->next;

            slow->next=NULL;
        }
    }
    
    return;
}

int main()
{
    Node *start,*last;
    start=last=NULL;
    int loop;
    cout<<"At which node you want to create loop?"<<endl;
    cin>>loop;
    CreateCircularLinkedList(start,last,loop);
    DetectLoopAndRemove(start);
    
    return 0;
}
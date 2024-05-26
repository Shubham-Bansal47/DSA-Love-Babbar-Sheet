#include<bits/stdc++.h>
using namespace std;

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

void CreateLinkedList(Node* &start,Node* &last)
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
        }
        cout<<"Do you want to enter more nodes?"<<endl;
        cin>>x;
    }

    return;
}

void RemoveDuplicates(Node* &start)
{
    map<int,int> mp;
    Node *temp=start;
    while(temp!=NULL)
    {
        mp[temp->val]++;
        temp=temp->next;
    }

    Node *prev,*front;
    prev=start;
    front=start->next;
    // 1 2 2 3 4 2
    while(front!=NULL)
    {
        if(mp[front->val]>1)
        {
            prev->next=front->next;
            mp[front->val]--;
            front=front->next;
        }
        else
        {
            prev=front;
            front=prev->next;
        }
    }

    return;
}

void PrintLinkedList(Node* start)
{
    while(start!=NULL)
    {
        cout<<start->val<<" ";
        start=start->next;
    }

    return;
}

int main()
{
    Node *start,*last;
    start=last=NULL;
    CreateLinkedList(start,last);
    RemoveDuplicates(start);
    PrintLinkedList(start);

    return 0;
}
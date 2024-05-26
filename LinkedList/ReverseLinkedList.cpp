#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* next;

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
        Node* tempnode=new Node(val);
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

Node* ReverseLinkedList(Node* start)
{
    Node *temp1,*temp2;
    temp1=NULL;
    temp2=start;
    while(temp2!=NULL)
    {
        Node* store=temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=store;
    }

    return temp1;
}

void PrintLinkedList(Node* start)
{
    Node* temp=start;
    while(temp!=NULL)
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    }

    return;
}

int main()
{
    Node *start,*last;
    start=NULL;
    last=NULL;
    CreateLinkedList(start,last);
    start=ReverseLinkedList(start);
    PrintLinkedList(start);

    return 0;
}
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

void CreateCircularLinkedList(Node* &start,Node* &last)
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
            last->next=start;
        }
        else
        {
            last->next=tempnode;
            last=last->next;
            last->next=start;
        }
        cout<<"Do you want to enter mode nodes?"<<endl;
        cin>>x;
    }

    return;
}

void PrintLinkedList(Node* start)
{
    Node* temp=start;
    do
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    } while(temp!=start);
    cout<<temp->val;

    return;
}

int main()
{
    Node *start,*last;
    start=NULL;
    last=NULL;
    CreateCircularLinkedList(start,last);
    PrintLinkedList(start);

    return 0;
}
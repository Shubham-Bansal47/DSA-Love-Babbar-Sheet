#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node* prev;
        Node* next;

        Node(int val)
        {
            this->val=val;
            this->prev=NULL;
            this->next=NULL;
        }
};

void CreateDoublyLinkedList(Node* &start,Node* &last)
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
            tempnode->prev=last;
            last=last->next;
        }
        cout<<"Do you want to enter more nodes?"<<endl;
        cin>>x;
    }

    return;
}

void PrintLinkedList(Node* start,Node* last)
{
    cout<<"Printing from front"<<endl;
    while(start!=NULL)
    {
        cout<<start->val<<" ";
        start=start->next;
    }
    cout<<endl;
    cout<<"Printing from back"<<endl;
    while(last!=NULL)
    {
        cout<<last->val<<" ";
        last=last->prev;
    }

    return;
}

int main()
{
    Node *start,*last;  
    start=last=NULL;
    CreateDoublyLinkedList(start,last);
    PrintLinkedList(start,last);

    return 0;
}
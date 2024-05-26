#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int val;
        Node *prev;
        Node* next;

        Node(int value)
        {
            this->val=value;
            this->next=NULL;
        }
};

void CreateDoublyCircularLinkedList(Node* &start,Node* &last)
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
            last->next=start;
        }
        cout<<"Do you want to enter more nodes?"<<endl;
        cin>>x;
    }
    start->prev=last;

    return;
}

void PrintLinkedList(Node* start,Node* last)
{
    Node* temp=start;
    cout<<"Printing from front"<<endl;
    do
    {
        cout<<temp->val<<" ";
        temp=temp->next;
    } while (temp!=start);
    cout<<temp->val<<endl;

    temp=last;
    cout<<"Printing from back"<<endl;
    do
    {
        cout<<temp->val<<" ";
        temp=temp->prev;
    } while (temp!=last);
    cout<<temp->val;

    return;
}

int main()
{
    Node *start,*last;
    start=last=NULL;
    CreateDoublyCircularLinkedList(start,last);
    PrintLinkedList(start,last);

    return 0;
}
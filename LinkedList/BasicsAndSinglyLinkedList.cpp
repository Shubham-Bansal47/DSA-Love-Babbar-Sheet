#include<bits/stdc++.h>
using namespace std;

//Linked list -> Linear data structure, dynamically implemented, no extra space, no memory wastage

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
    int x=1;
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

void PrintLinkedList(Node* start)
{
    Node* temp;
    temp=start;
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
    PrintLinkedList(start);

    return 0;
}
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
        cout<<"Do you want to enter more nodes"<<endl;
        cin>>x;
    }

    return;
}

Node* ReverseInKGroups(Node* start,int k)
{
    if(start==NULL || start->next==NULL)
        return start;
    int cnt=k;
    Node *temp1,*temp2;
    temp1=NULL;
    temp2=start;
    while(temp2!=NULL && cnt!=0)
    {
        cnt--;
        Node* store=temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=store;
    }
    if(temp2!=NULL)
        start->next=ReverseInKGroups(temp2,k);
    
    return temp1;
}

void PrintLinkedList(Node* start)
{
    Node *temp=start;
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
    start=last=NULL;
    CreateLinkedList(start,last);
    int k;
    cout<<"Enter the value of K"<<endl;
    cin>>k;
    start=ReverseInKGroups(start,k);
    PrintLinkedList(start);

    return 0;
}
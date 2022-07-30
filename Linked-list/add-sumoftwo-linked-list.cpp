#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int val)
    {
        data=val;
        next=NULL;
    }
};

Node* createlist(Node* head,Node* tail)
{
    cout<<"Enter the Data"<<endl;
    int val;
    cin>>val;
    while(val!=-1)
    {
        Node* temp=new Node(val);
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=tail->next;
        }
        cin>>val;
    }
    return head;
}

Node* reverse(Node* head)
{
    Node *prev,*curr;
    prev=NULL;
    curr=head;
    while(curr!=NULL)
    {
        Node *frd;
        frd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=frd;
    }

    return prev;
}

void insertnode(Node* &anshead,Node* &anstail,int digit)
{
    Node* temp=new Node(digit);
    if(anshead==NULL)
    {
        anshead=temp;
        anstail=temp;
    }
    else
    {
        anstail->next=temp;
        anstail=anstail->next;
    }
    return;
}

Node* addthem(Node* head1,Node* head2)
{
    Node *anshead=NULL;
    Node *anstail=NULL;
    int carry=0;
    while(head1!=NULL || head2!=NULL || carry!=0)
    {
        int val1=0;
        if(head1!=NULL)
        {
            val1=head1->data;
        }
        int val2=0;
        if(head2!=NULL)
        {
            val2=head2->data;
        }
        int sum=val1 + val2 + carry;
        int digit=sum%10;
        insertnode(anshead,anstail,digit);
        carry=sum/10;
        if(head1!=NULL)
        {
            head1=head1->next;
        }
        if(head2!=NULL)
        {
            head2=head2->next;
        }
    }
    return anshead;
}

int main()
{
    Node *head1,*tail1,*head2,*tail2;
    head1=NULL;
    tail1=NULL;
    head2=NULL;
    tail2=NULL;
    head1=createlist(head1,tail1);
    head2=createlist(head2,tail2);
    head1=reverse(head1);
    head2=reverse(head2);
    Node* temp=addthem(head1,head2);
    temp=reverse(temp);
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }

    return 0;
}
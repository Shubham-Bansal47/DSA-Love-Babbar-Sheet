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

Node* ReverseLinkedList(Node* &start,Node* &last)
{
    if(start==NULL || start->next==NULL)
        return start;

    Node *temp1,*temp2;
    temp1=NULL;
    temp2=start;
    while(temp2!=NULL)
    {
        Node *store=temp2->next;
        temp2->next=temp1;
        temp1=temp2;
        temp2=store;
    }

    return temp1;
}
 
Node* AddLinkedList(Node* &start1,Node* &last1,Node* &start2,Node* &last2)
{
    start1=ReverseLinkedList(start1,last1);
    start2=ReverseLinkedList(start2,last2);
    int carry=0;
    Node *temp1=start1;
    Node *temp2=start2;
    Node *start,*last;
    start=last=NULL;
    while(temp1!=NULL || temp2!=NULL || carry!=0)
    {
        int sum=0;
        sum+=carry;
        if(temp1!=NULL)
        {
            sum+=temp1->val;
            temp1=temp1->next;
        }    
        if(temp2!=NULL)
        {
            sum+=temp2->val;
            temp2=temp2->next;
        }

        carry=sum/10;
        int rem=sum%10;

        Node *tempnode=new Node(rem);
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
    }
    start=ReverseLinkedList(start,last);

    return start; 
}

void PrintLinkedList(Node *start)
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
    Node *start1,*last1,*start2,*last2;

    start1=last1=start2=last2=NULL;
    CreateLinkedList(start1,last1);
    CreateLinkedList(start2,last2);
    Node* temp=AddLinkedList(start1,last1,start2,last2);
    PrintLinkedList(temp);

    return 0;
}
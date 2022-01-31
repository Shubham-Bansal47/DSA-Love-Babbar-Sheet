#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

struct List
{
    struct List* prev;
    int val;
    struct List* next;
};

struct List* reverseDLL(struct List * head)
{
    struct List *ptr,*ptr1,*ptr3,*ptr4;
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    ptr3=NULL;
    ptr4=head;
    while(ptr4->next!=NULL)
    {
        ptr4=ptr4->next;
    }
    while(ptr4!=NULL)
    {
        struct List *ptr2;
        ptr2=ptr4->prev;
        ptr4->prev=ptr3;
        ptr3=ptr4;
        ptr4=ptr2;
    }
    ptr=NULL;
    ptr1=head;
    while(ptr1!=NULL)
    {
        struct List *ptr2;
        ptr2=ptr1->next;
        ptr1->next=ptr;
        ptr=ptr1;
        ptr1=ptr2;
    }
    return ptr;
}

void displayfront(struct List *head)
{
    struct List *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
    return;
}

void displayback(struct List *head)
{
    struct List *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->prev;
    }
    return;
}

int main()
{
    FastIO;
    int i,j,n;
    cin>>n;
    struct List *start,*trav,*ptr,*ptr1;
    start=NULL;
    trav=NULL;
    while(n--)
    {
        struct List *newnode;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->prev=NULL;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            newnode->prev=trav;
            trav=trav->next;
        }
    }
    start=reverseDLL(start);
    displayfront(start);
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    cout<<"\n";
    displayback(ptr);
}

   
    


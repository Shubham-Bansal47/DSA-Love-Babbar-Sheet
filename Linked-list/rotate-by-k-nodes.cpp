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

struct List *rotate(struct List *start,int k)
{
    struct List *ptr,*ptr1;
    ptr=start;
    ptr1=start;
    while(ptr1->next!=NULL)
    {
        ptr1=ptr1->next;
    }
    while(k--)
    {
        start=ptr->next;
        start->prev=NULL;
        ptr1->next=ptr;
        ptr->prev=ptr1;
        ptr->next=NULL;
        ptr1=ptr1->next;
        ptr=start;
    }
    return start;
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
    int i,j,n,k;
    cin>>n>>k;
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
    start=rotate(start,k);
    displayfront(start);
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    cout<<"\n";
    displayback(ptr);
}

   
    


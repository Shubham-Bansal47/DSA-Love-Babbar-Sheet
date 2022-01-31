#include<bits/stdc++.h>
#define ll long long int
#define FastIO ios_base::sync_with_stdio(false);
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
using namespace std;

struct List
{
    int val;
    struct List* next;
};

void display(struct List* head)
{
    struct List *ptr;
    ptr=head;
    do
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }while(ptr!=head);
}

void splitList(struct List *head)
{
    struct List *tr,*tr1;
    struct List *ptr,*ptr1;
    int x=0;
    if(head==NULL)
    {
        tr=NULL;
        tr1=NULL;
        return;
    }
    else if(head->next==head)
    {
        tr=head;
        tr1=NULL;
        return;
    }
    ptr=head;
    do
    {
        ++x;
        ptr=ptr->next;
    }while(ptr!=head);
    ptr=head;
    ptr1=ptr->next;
    if(x%2==0)
    {
        int y=(x/2)-1;
        while(y--)
        {
            ptr=ptr->next;
        }
        tr=head;
        ptr1=ptr->next;
        ptr->next=head;
        y=(x/2)-1;
        ptr=ptr1;
        while(y--)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr1;
        tr1=ptr1;
    }
    else
    {
        int y=x/2;
        while(y--)
        {
            ptr=ptr->next;
        }                         // 1 2 3 4 5
        tr=head;
        ptr1=ptr->next;
        ptr->next=head;
        y=(x/2)-1;
        ptr=ptr1;
        while(y--)
        {
            ptr=ptr->next;
        }
        ptr->next=ptr1;
        tr1=ptr1;
    }
    display(tr);
    cout<<"\n";
    display(tr1);
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
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            trav=newnode; 
            trav->next=start;
        }
        else
        {
            trav->next=newnode;
            trav=trav->next;
            trav->next=start;
        }
    }
    // display(start);
    splitList(start);
}

   
    


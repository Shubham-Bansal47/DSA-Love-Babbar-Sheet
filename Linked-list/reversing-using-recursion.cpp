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

struct List *reverse(struct List* head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    struct List *ptr=reverse(head->next);
    head->next->next=head;
    head->next=NULL;
    
    return ptr;
}

struct List* reverse1(struct List* head)
{
    if(head==NULL || head->next==NULL)
        return head;
    
    struct List *ptr,*ptr1;
    ptr=NULL;
    ptr1=head;
    int x=0;
    while(ptr1!=NULL && x<1)
    {
        struct List* ptr2;
        ptr2=ptr1->next;
        ptr1->next=ptr;
        ptr=ptr1;
        ptr1=ptr2;
        ++x;
    }
    if(ptr1!=NULL)
    {
        head->next=reverse1(ptr1);
    }
    return ptr;
}

int main()
{
    FastIO;
    int i,j,n;
    cin>>n;
    struct List *start,*ptr;
    start=NULL;
    while(n--)
    {
        struct List *newnode,*trav;
        newnode=(struct List*)malloc(sizeof(struct List));
        cin>>newnode->val;
        newnode->next=NULL;
        if(start==NULL)
        {
            start=newnode;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            trav=trav->next;
        }
    }
    if(n==1)
    {
        cout<<start->val;
        return 0;
    }
    start=reverse1(start);
    ptr=start;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}
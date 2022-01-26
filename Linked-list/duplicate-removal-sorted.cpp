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

void removeDuplicates(struct List* head)
{
    struct List* ptr=head; 
    if(!ptr) return ;
    while(ptr->next!=NULL)
    {
        if(ptr->val==(ptr->next)->val)
        {
            ptr->next=ptr->next->next;
        }
        else
        {
            ptr=ptr->next;
        }
    }
    return ;
}

void display(struct List* head)
{
    struct List *ptr;
    ptr=head;
    while(ptr!=NULL)
    {
        cout<<ptr->val<<" ";
        ptr=ptr->next;
    }
}

int main()
{
    FastIO;
    int i,j,n,x;
    cin>>n;
    struct List *start, *ptr,*ptr1;
    start=NULL;
    x=n;
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
    removeDuplicates(start);
    display(start);
}
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

bool isCircular(struct List *head) // use slow and fast pointer approach here
{
    struct List *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        return false;
    }
    while(ptr->next!=NULL && ptr->next!=head)
    {
        ptr=ptr->next;
    }
    if(ptr->next==NULL)
    {
        return false;
    }
    else
    {
        return true;
    }
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
    int i,j,n;
    cin>>n;
    struct List *start, *ptr,*ptr1;
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
            newnode->next=start;
            trav=newnode;
        }
        else
        {
            trav->next=newnode;
            newnode->next=start;
            trav=trav->next;

        }
    }
    int x=isCircular(start);
    cout<<x;
    // display(start);
}

   
    

